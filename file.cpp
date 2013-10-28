#include <libclang++/file_internal.h>

#include <libclang++/string_internal.h>
#include <libclang++/translationunit_internal.h>
#include <libclang++/missing.h>

namespace clang {

File::File(const TranslationUnit& translationunit) : p(new File_(translationunit, clang_getNullFile()))
{
}

File::File(std::shared_ptr<File_> from) : p(from)
{
}

File::File(File_* from) : p(from)
{
}

File::~File()
{
}

File::File(const TranslationUnit& translationunit, std::string file)
	: p(new File_(translationunit, clang_getFile(translationunit.p->translationunit, file.c_str())))
{
}

String File::getName() const {
	notNull();
	return new String_(clang_getFileName(p->file));
}

time_t File::getTime() const {
	notNull();
	return clang_getFileTime(p->file);
}

bool File::isGuarder() const {
	notNull();
	return clang_isFileMultipleIncludeGuarded(p->translationunit.p->translationunit, p->file);
}

bool File::isNull() const {
	return clang_File_isNull(p->file);
}

SourceRange File::getRange(unsigned startOffset, unsigned endOffset) {
	notNull();
	return SourceRange(p->translationunit, *this, startOffset, endOffset);
}

SourceLocation File::getLocation(unsigned offset) {
	notNull();
	return SourceLocation(p->translationunit, Location(*this, offset));
}

}
