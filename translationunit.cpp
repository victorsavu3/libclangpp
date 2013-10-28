#include <libclang++/translationunit_internal.h>

#include <libclang++/sourcelocation_internal.h>
#include <libclang++/cursor_internal.h>
#include <libclang++/string_internal.h>
#include <libclang++/tokens_internal.h>
#include <libclang++/file_internal.h>

namespace clang {

TranslationUnit::TranslationUnit(std::shared_ptr<TranslationUnit_> from) : p(from)
{
}

TranslationUnit::TranslationUnit(TranslationUnit_* from) : p(from)
{
}

TranslationUnit::~TranslationUnit()
{
}

String TranslationUnit::getNativeName() const {
	return new String_(clang_getTranslationUnitSpelling(p->translationunit));
}

Tokens TranslationUnit::getTokens(SourceRange range) const{
	return new Tokens_(*this, range);
}

File TranslationUnit::getFile(const std::string& name) const {
	return new File_(*this, clang_getFile(p->translationunit, name.c_str()));
}

}
