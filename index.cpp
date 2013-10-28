#include <libclang++/index_internal.h>

#include <libclang++/translationunit_internal.h>

namespace clang {

Index::Index()
	: p(new Index_(clang_createIndex(0, 0)))
{
}

Index::Index(std::shared_ptr<Index_> from) : p(from)
{
}

Index::Index(Index_* from) : p(from)
{
}

Index::~Index()
{
}

TranslationUnit Index::parse(unsigned argc, const char *const *argv, unsigned options) {
	return new TranslationUnit_(*this, clang_parseTranslationUnit(p->index, NULL, argv, argc, nullptr, 0, options));
}

}
