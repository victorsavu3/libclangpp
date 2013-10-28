#pragma once

#include <Index.h>

#include <libclang++/file.h>

namespace clang {

class File_ {
	public:
		File_() = delete;
		File_(const File_&) = delete;
		File_& operator=(const File_&) = delete;

		File_(const TranslationUnit& translationunit, const CXFile& from) : file(from), translationunit(translationunit){}

		~File_(){}
	private:
		CXFile file;
		TranslationUnit translationunit;

		friend class File;

		friend class SourceLocation;
		friend class SourceRange_;
};

}
