#include <libclang++/sourcerange_internal.h>

#include <libclang++/sourcelocation_internal.h>

namespace clang {

SourceRange::SourceRange(std::shared_ptr<SourceRange_> from) : p(from)
{
}

SourceRange::SourceRange(SourceRange_* from) : p(from)
{
}

SourceRange::~SourceRange()
{
}

SourceRange::SourceRange(const SourceLocation& start, const SourceLocation& end) : p(new SourceRange_(start, end))
{
}

SourceRange::SourceRange(const TranslationUnit& translationunit, const File& file, unsigned startOffset, unsigned endOffset)
	: p(new SourceRange_(translationunit, file, startOffset, endOffset))
{
}

SourceRange::SourceRange(const TranslationUnit& translationunit, const std::string& file, unsigned startOffset, unsigned endOffset)
	: SourceRange(translationunit, translationunit.getFile(file), startOffset, endOffset)
{
}

SourceLocation SourceRange::getStart() const {
	return new SourceLocation_(p->translationunit, clang_getRangeStart(p->sourcerange));
}
SourceLocation SourceRange::getEnd() const {
	return new SourceLocation_(p->translationunit, clang_getRangeEnd(p->sourcerange));
}

bool SourceRange::operator ==(const SourceRange& with) const {
	return clang_equalRanges(p->sourcerange, with.p->sourcerange);
}

bool SourceRange::isNull() const {
	return clang_Range_isNull(p->sourcerange);
}

}
