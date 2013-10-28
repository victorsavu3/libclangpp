#pragma once

#include <Index.h>

#include <libclang++/sourcerange.h>

#include <libclang++/sourcelocation_internal.h>
#include <libclang++/translationunit_internal.h>
#include <libclang++/file_internal.h>

namespace clang {

class SourceRange_ {
	public:
		SourceRange_() = delete;
		SourceRange_(const SourceRange_&) = delete;
		SourceRange_& operator=(const SourceRange_&) = delete;

		SourceRange_(const TranslationUnit& translationunit, const CXSourceRange& sourcerange) :
			sourcerange(sourcerange), translationunit(translationunit) {}

		SourceRange_(const SourceLocation& start, const SourceLocation& end) :
			sourcerange(clang_getRange(start.p->sourcelocation, end.p->sourcelocation)), translationunit(start.getTranslationUnit()){}

		SourceRange_(const TranslationUnit& translationunit, const File& file, unsigned startOffset, unsigned endOffset) :
			translationunit(translationunit)
		{
			file.notNull();
			sourcerange = clang_getRange(
								clang_getLocationForOffset(translationunit.p->translationunit, file.p->file, startOffset),
								clang_getLocationForOffset(translationunit.p->translationunit, file.p->file, endOffset)
					);
		}
		~SourceRange_(){}
	private:
		CXSourceRange sourcerange;
		TranslationUnit translationunit;

		friend class SourceRange;

		friend class Tokens_;
};

}
