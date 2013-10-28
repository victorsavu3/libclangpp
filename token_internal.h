#pragma once

#include <memory>

#include <Index.h>

#include <libclang++/token.h>

#include <libclang++/tokens.h>
#include <libclang++/translationunit_internal.h>

namespace clang {

class Token_ {
	public:
		Token_() = delete;
		Token_(const Token_&) = delete;
		Token_& operator=(const Token_&) = delete;

		Token_(Tokens from, CXToken* token, CXCursor* cursor) :
			from(from), token(token), cursor(cursor) {}

		~Token_(){}

		CXTokenKind getKind() {
			return clang_getTokenKind(*token);
		}
	private:
		Tokens from;
		CXToken* token;
		CXCursor* cursor;

		const CXCursor& getCursor() const{
			return *cursor;
		}

		const CXToken& getToken() const{
			return *token;
		}

		const CXTranslationUnit& getNativeTranslationUnit() const {
			return getTranslationUnit().p->translationunit;
		}

		const TranslationUnit& getTranslationUnit() const {
			return from.getTranslationUnit();
		}

		friend Token;
};

}
