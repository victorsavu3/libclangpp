#include <libclang++/location.h>

#ifndef FILE_H_INCLUDED_
#define FILE_H_INCLUDED_

#include <memory>

namespace clang {
	class File;
}

#define FILE_H_INCLUDED

#include <libclang++/translationunit.h>
#include <libclang++/string.h>
#include <libclang++/exception.h>
#include <libclang++/sourcerange.h>
#include <libclang++/sourcelocation.h>

namespace clang {

class File_;

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

#endif
