#pragma once

#include <memory>

namespace clang {
	class Index;
}

#include <libclang++/translationunit.h>

namespace clang {

class Index_;

class Index {
	public:
		Index();
		Index(const Index&) = default;
		Index& operator=(const Index&) = default;

		Index(std::shared_ptr<Index_> from);
		Index(Index_* from);

		TranslationUnit parse(unsigned argc, const char *const *argv, unsigned options);

		~Index();
	private:
		std::shared_ptr<Index_> p;
};

}
