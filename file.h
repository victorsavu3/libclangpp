#pragma once

#include <memory>

namespace clang {
	class File;
}

#include <libclang++/exception.h>
#include <libclang++/string.h>

namespace clang {

class File_;

class TranslationUnit;
class SourceLocation;
class SourceRange;

class File {
	public:
		File() = delete;
		File(const File&) = default;
		File& operator=(const File&) = default;

		File(std::shared_ptr<File_> from);
		File(File_* from);

		File(const TranslationUnit& translationunit);
		File(const TranslationUnit& translationunit, std::string file);

		~File();

		String getName() const;
		time_t getTime() const;

		bool isGuarder() const;
		bool isNull() const;

		void notNull() const{
			if(isNull())
				throw NullValueUsed<File>();
		}

		SourceRange getRange(unsigned startOffset, unsigned endOffset);
		SourceLocation getLocation(unsigned offset);
	private:
		std::shared_ptr<File_> p;

		friend class SourceLocation;
		friend class SourceRange_;
};

}

#include <libclang++/translationunit.h>
#include <libclang++/sourcelocation.h>
#include <libclang++/sourcerange.h>
