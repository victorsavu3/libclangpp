#include <libclang++/cursor_internal.h>

#include <libclang++/sourcelocation_internal.h>
#include <libclang++/sourcerange_internal.h>

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

#define CURSOR_IS(WHAT) bool Cursor::is##WHAT() const { return clang_is##WHAT(p->getKind()); }

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

#define CURSOR_IS(WHAT) bool Cursor::is##WHAT() const { return clang_Cursor_is##WHAT(p->cursor); }

CURSOR_IS(Null)
CURSOR_IS(BitField)
CURSOR_IS(DynamicCall)
CURSOR_IS(Variadic)

SourceLocation Cursor::getLocation() const{
	return new SourceLocation_(p->translationunit, clang_getCursorLocation(p->cursor));
}

SourceRange Cursor::getRange() const{
	return new SourceRange_(p->translationunit, clang_getCursorExtent(p->cursor));
}

#undef CURSOR_IS

}
