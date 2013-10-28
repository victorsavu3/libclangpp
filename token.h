#pragma once

#include <memory>
#include <string>

namespace clang {
	class Token;
}

#include <libclang++/tokens.h>
#include <libclang++/cursor.h>
#include <libclang++/sourcelocation.h>
#include <libclang++/sourcerange.h>
#include <libclang++/enum.h>
#include <libclang++/string.h>

namespace clang {

class Token_;

class Token {
	public:
		Token() = delete;
		Token(const Token&) = default;
		Token& operator=(const Token&) = default;

		Token(std::shared_ptr<Token_> from);
		Token(Token_* from);

		~Token();

		TokenKind getKind() const;

		Tokens getTokens() const;
		Cursor getCursor() const;
		SourceLocation getLocation() const;
		SourceRange getRange() const;

		std::string getSpelling() const;
		String getNativeSpelling() const;
	private:
		std::shared_ptr<Token_> p;
};

}
