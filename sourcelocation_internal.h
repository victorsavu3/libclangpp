#pragma once

#include <Index.h>

#include <libclang++/sourcelocation.h>

namespace clang {

class SourceLocation_ {
	public:
		SourceLocation_() = delete;
		SourceLocation_(const SourceLocation_&) = delete;
		SourceLocation_& operator=(const SourceLocation_&) = delete;

		SourceLocation_(const TranslationUnit& translationunit, const CXSourceLocation& sourcelocation) :
			sourcelocation(sourcelocation), translationunit(translationunit) {}

		SourceLocation_(const TranslationUnit& translationunit) : sourcelocation(clang_getNullLocation()), translationunit(translationunit) {}
		~SourceLocation_(){}
	private:
		CXSourceLocation sourcelocation;
		TranslationUnit translationunit;

		friend class SourceLocation;

		friend class TranslationUnit;
		friend class SourceRange_;
};

}
