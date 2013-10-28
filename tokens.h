#pragma once

#include <memory>

namespace clang {
	class Tokens;
}

#include <libclang++/token.h>
#include <libclang++/translationunit.h>

namespace clang {

class Tokens_;

class Tokens {
	public:
		Tokens() = delete;
		Tokens(const Tokens&) = default;
		Tokens& operator=(const Tokens&) = default;

		Tokens(std::shared_ptr<Tokens_> from);
		Tokens(Tokens_* from);

		~Tokens();

		unsigned int size() const;
		Token operator [](unsigned int index) const;

		class iterator;

		iterator begin() const;
		iterator end() const;

		const TranslationUnit& getTranslationUnit() const;
	private:
		std::shared_ptr<Tokens_> p;

		friend class iterator;
};

class Tokens::iterator {
public:
	iterator(Tokens from, unsigned int at) : from(from), at(at) {}

	Token operator*();

	void operator++() {
		at++;
	}

	bool operator!=(const iterator & with) {
		return with.from.p != from.p || with.at != at;
	}
private:
	Tokens from;
	unsigned int at;
};

}
