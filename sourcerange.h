#pragma once

#include <memory>

namespace clang {
	class SourceRange;
}

#include <libclang++/sourcelocation.h>
#include <libclang++/exception.h>

namespace clang {

class SourceRange_;

class SourceRange {
	public:
		SourceRange() = delete;
		SourceRange(const SourceRange&) = default;
		SourceRange& operator=(const SourceRange&) = default;

		SourceRange(std::shared_ptr<SourceRange_> from);
		SourceRange(SourceRange_* from);
		SourceRange(const SourceLocation& start, const SourceLocation& end);
		SourceRange(const TranslationUnit& translationunit, const std::string& file, unsigned startOffset, unsigned endOffset);
		SourceRange(const TranslationUnit& translationunit, const File& file, unsigned startOffset, unsigned endOffset);

		SourceLocation getStart() const;
		SourceLocation getEnd() const;

		bool operator ==(const SourceRange& with) const;

		bool isNull() const;
		void notNull() const {
			if(isNull())
				throw NullValueUsed<SourceRange>();
		}

		~SourceRange();
	private:
		std::shared_ptr<SourceRange_> p;

		friend class Tokens_;
};

}
