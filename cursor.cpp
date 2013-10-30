#include <libclang++/cursor_internal.h>

#include <libclang++/sourcelocation_internal.h>
#include <libclang++/sourcerange_internal.h>
#include <libclang++/string_internal.h>

namespace clang {

Cursor::Cursor(std::shared_ptr<Cursor_> from) : p(from)
{
}

Cursor::Cursor(Cursor_* from) : p(from)
{
}

Cursor::~Cursor()
{
}

#define CURSOR_IS(WHAT) bool Cursor::is##WHAT() const { notNull(); return clang_is##WHAT(p->getKind()); }

CURSOR_IS(Declaration)
CURSOR_IS(Reference)
CURSOR_IS(Expression)
CURSOR_IS(Statement)
CURSOR_IS(Attribute)
CURSOR_IS(Invalid)
CURSOR_IS(TranslationUnit)
CURSOR_IS(Preprocessing)
CURSOR_IS(Unexposed)

#undef CURSOR_IS

#define CURSOR_IS(WHAT) bool Cursor::is##WHAT() const { notNull(); return clang_Cursor_is##WHAT(p->cursor); }

CURSOR_IS(BitField)
CURSOR_IS(DynamicCall)
CURSOR_IS(Variadic)

#undef CURSOR_IS

bool Cursor::isNull() const {
	return clang_Cursor_isNull(p->cursor);
}

bool Cursor::isDefinition() const {
	notNull();
	return clang_isCursorDefinition(p->cursor);
}

SourceLocation Cursor::getLocation() const {
	notNull();
	return new SourceLocation_(p->translationunit, clang_getCursorLocation(p->cursor));
}

SourceRange Cursor::getRange() const {
	notNull();
	return new SourceRange_(p->translationunit, clang_getCursorExtent(p->cursor));
}

Cursor Cursor::getReferenced() const  {
	notNull();
	return new Cursor_(p->translationunit, clang_getCursorReferenced(p->cursor));
}

Cursor Cursor::getCannonical() const {
	notNull();
	return new Cursor_(p->translationunit, clang_getCanonicalCursor(p->cursor));
}

Cursor Cursor::getSemanticParent() const {
	notNull();
	return new Cursor_(p->translationunit, clang_getCursorSemanticParent(p->cursor));
}

Cursor Cursor::getLexicalParent() const {
	notNull();
	return new Cursor_(p->translationunit, clang_getCursorLexicalParent(p->cursor));
}

Cursor Cursor::getDefinition() const {
	notNull();
	return new Cursor_(p->translationunit, clang_getCursorDefinition(p->cursor));
}

SourceRange Cursor::getCommentRange() const {
	notNull();
	return new SourceRange_(p->translationunit, clang_Cursor_getCommentRange(p->cursor));
}

String Cursor::getNativeBriefComment() const {
	notNull();
	return new String_(clang_Cursor_getBriefCommentText(p->cursor));
}

String Cursor::getNativeRawComment() const {
	notNull();
	return new String_(clang_Cursor_getRawCommentText(p->cursor));
}

String Cursor::getNativeSpelling() const {
	notNull();
	return new String_(clang_getCursorSpelling(p->cursor));
}

String Cursor::getNativeDisplayName() const {
	notNull();
	return new String_(clang_getCursorDisplayName(p->cursor));
}

String Cursor::getNativeUSR() const {
	notNull();
	return new String_(clang_getCursorUSR(p->cursor));
}

CursorKind Cursor::getKind() const {
	notNull();
	return static_cast<CursorKind>(clang_getCursorKind(p->cursor));
}

LinkageKind Cursor::getLinkageKind() const {
	notNull();
	return static_cast<LinkageKind>(clang_getCursorLinkage(p->cursor));
}

AvailabilityKind Cursor::getAvailabilityKind() const {
	notNull();
	return static_cast<AvailabilityKind>(clang_getCursorAvailability(p->cursor));
}

LanguageKind Cursor::getLanguageKind() const {
	notNull();
	return static_cast<LanguageKind>(clang_getCursorLanguage(p->cursor));
}

struct VisitorData {
	TranslationUnit* translatonunit;
	std::vector<Cursor>* data;
};

CXChildVisitResult visit(CXCursor cursor, CXCursor /*parent*/, CXClientData client_data) {
	auto ret = static_cast<VisitorData*>(client_data);

	ret->data->push_back(new Cursor_(*ret->translatonunit, cursor));

	return CXChildVisit_Continue;
}

std::vector<Cursor> Cursor::getChildren() const {
	notNull();
	std::vector<Cursor> ret;

	VisitorData data;
	data.translatonunit = &p->translationunit;
	data.data = &ret;

	clang_visitChildren(p->cursor, visit, static_cast<CXClientData>(&data));

	return ret;
}

CXChildVisitResult visitRecursive(CXCursor cursor, CXCursor /*parent*/, CXClientData client_data) {
	auto ret = static_cast<VisitorData*>(client_data);

	ret->data->push_back(new Cursor_(*ret->translatonunit, cursor));

	return CXChildVisit_Recurse;
}

std::vector<Cursor> Cursor::getChildrenRecursive() const {
	notNull();
	std::vector<Cursor> ret;

	VisitorData data;
	data.translatonunit = &p->translationunit;
	data.data = &ret;

	clang_visitChildren(p->cursor, visit, static_cast<CXClientData>(&data));

	return ret;
}

}
