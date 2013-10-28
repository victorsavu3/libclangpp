#pragma once

#include <Index.h>

#include <libclang++/translationunit.h>

namespace clang {

class TranslationUnit_ {
	public:
		TranslationUnit_() = delete;
		TranslationUnit_(const TranslationUnit_&) = delete;
		TranslationUnit_& operator=(const TranslationUnit_&) = delete;

		TranslationUnit_(Index index, const CXTranslationUnit& from) : translationunit(from), index(index) {}

		~TranslationUnit_(){
			clang_disposeTranslationUnit(translationunit);
		}
	private:
		CXTranslationUnit translationunit;
		Index index;

		friend class TranslationUnit;

		friend class Tokens_;
		friend class Token_;
		friend class SourceLocation;
		friend class SourceRange_;
		friend class File;
};

}
