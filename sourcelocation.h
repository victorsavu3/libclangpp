#pragma once

#include <memory>

namespace clang {
	class SourceLocation;
}

#include <libclang++/location.h>
#include <libclang++/cursor.h>
#include <libclang++/file.h>
#include <libclang++/translationunit.h>
#include <libclang++/cursor.h>
#include <libclang++/exception.h>

namespace clang {

class SourceLocation_;

class SourceLocation {
	public:
		SourceLocation() = delete;
		SourceLocation(const TranslationUnit& from);
		SourceLocation(const SourceLocation&) = default;
		SourceLocation& operator=(const SourceLocation&) = default;

		SourceLocation(std::shared_ptr<SourceLocation_> from);
		SourceLocation(SourceLocation_* from);

		SourceLocation(TranslationUnit from, Location location);
		SourceLocation(TranslationUnit from, ExtendedLocation location);

		~SourceLocation();

		bool isInSystemHeader() const;
		bool isNull() const;

		void notNull() const{
			if(isNull())
				throw NullValueUsed<SourceLocation>();
		}

		ExtendedLocation getExpansionLocation() const;
		ExtendedLocation getFileLocation() const;
		ExtendedLocation getSpellingLocation() const;

		const TranslationUnit& getTranslationUnit() const;
		Cursor getCursor() const;

		bool operator ==(const SourceLocation& with) const;
	private:
		std::shared_ptr<SourceLocation_> p;

		friend class TranslationUnit;
		friend class SourceRange_;
};

}
