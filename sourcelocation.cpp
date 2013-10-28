#include <libclang++/sourcelocation_internal.h>

#include <cstring>
#include <iostream>

#include <libclang++/file_internal.h>
#include <libclang++/translationunit_internal.h>
#include <libclang++/cursor_internal.h>
#include <libclang++/missing.h>

namespace clang {

SourceLocation::SourceLocation(const TranslationUnit& from) : p(new SourceLocation_(from))
{

}

SourceLocation::SourceLocation(std::shared_ptr<SourceLocation_> from) : p(from)
{
}

SourceLocation::SourceLocation(SourceLocation_* from) : p(from)
{
}

SourceLocation::~SourceLocation()
{
}

SourceLocation::SourceLocation(TranslationUnit from, Location location)
	: p(new SourceLocation_(from, clang_getLocationForOffset(from.p->translationunit, location.file.p->file, location.offset)))
{
	location.file.notNull();
}

SourceLocation::SourceLocation(TranslationUnit from, ExtendedLocation location)
	: p(new SourceLocation_(from, clang_getLocation(from.p->translationunit, location.file.p->file, location.line, location.column)))
{
	location.file.notNull();
}

bool SourceLocation::isInSystemHeader() const {
	notNull();
	return clang_Location_isInSystemHeader(p->sourcelocation);
}

bool SourceLocation::isNull() const {
	return clang_Location_isNull(p->sourcelocation);
}

#define GetLocation(X) \
	ExtendedLocation SourceLocation::get##X##Location() const {\
		notNull(); \
		CXFile file; \
		memset(&file, 0, sizeof(file)); \
		ExtendedLocation location(p->translationunit); \
		clang_get ## X ## Location(p->sourcelocation, &location.file.p->file, &location.line, &location.column, &location.offset); \
		return location; \
	}

GetLocation(Expansion);
GetLocation(File);
GetLocation(Spelling);

Cursor SourceLocation::getCursor() const {
	notNull();
	return new Cursor_(p->translationunit, clang_getCursor(p->translationunit.p->translationunit, p->sourcelocation));
}

const TranslationUnit& SourceLocation::getTranslationUnit() const {
	return p->translationunit;
}

bool SourceLocation::operator ==(const SourceLocation& with) const {
	notNull();
	with.notNull();
	return clang_equalLocations(p->sourcelocation, with.p->sourcelocation);
}

}
