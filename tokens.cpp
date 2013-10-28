#include <libclang++/tokens_internal.h>

#include <libclang++/token_internal.h>

namespace clang {

Tokens::Tokens(std::shared_ptr<Tokens_> from) : p(from)
{
}

Tokens::Tokens(Tokens_* from) : p(from)
{
}

Tokens::~Tokens()
{
}

unsigned int Tokens::size() const {
	return p->count;
}

Token Tokens::operator [](unsigned int index) const {
	return new Token_(*this, &p->tokens[index], &p->cursors[index]);
}

Tokens::iterator Tokens::begin() const {
	return iterator(*this, 0);
}

Tokens::iterator Tokens::end() const {
	return iterator(*this, size());
}

const TranslationUnit& Tokens::getTranslationUnit() const {
	return p->from;
}

Token Tokens::iterator::operator*(){
	return from[at];
}

}
