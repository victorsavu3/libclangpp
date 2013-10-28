#include <libclang++/token_internal.h>

#include <libclang++/cursor_internal.h>
#include <libclang++/sourcelocation_internal.h>
#include <libclang++/sourcerange_internal.h>
#include <libclang++/string_internal.h>

namespace clang {

Token::Token(std::shared_ptr<Token_> from) : p(from)
{
}

Token::Token(Token_* from) : p(from)
{
}

Token::~Token()
{
}

Tokens Token::getTokens() const {
	return p->from;
}

Cursor Token::getCursor() const {
	return new Cursor_(p->getTranslationUnit(), p->getCursor());
}

SourceLocation Token::getLocation() const {
	return new SourceLocation_(p->getTranslationUnit(), clang_getTokenLocation(p->getNativeTranslationUnit(), p->getToken()));
}

SourceRange Token::getRange() const {
	return new SourceRange_(p->getTranslationUnit(), clang_getTokenExtent(p->getNativeTranslationUnit(), p->getToken()));
}

String Token::getNativeSpelling() const {
	return new String_(clang_getTokenSpelling(p->getNativeTranslationUnit(), p->getToken()));
}

std::string Token::getSpelling() const {
	return getNativeSpelling().getString();
}

TokenKind Token::getKind() const {
	return static_cast<TokenKind>(p->getKind());
}

}
