#pragma once

namespace clang {
	struct Location;
	struct ExtendedLocation;
}

#include <libclang++/file.h>

namespace clang {

struct Location {
	Location() = delete;
	Location(const TranslationUnit& translationunit) : file(translationunit), offset(0) {}
	Location(File file) : file(file), offset(0) { file.notNull(); }
	Location(File file, unsigned offset) : file(file), offset(offset) { file.notNull(); }

	File file;
	unsigned offset;
};

struct ExtendedLocation : public Location {
	ExtendedLocation() = delete;
	ExtendedLocation(const  TranslationUnit& translationunit) : Location(translationunit), line(0), column(0) {}
	ExtendedLocation(File file) : Location(file), line(0), column(0) { file.notNull(); }
	ExtendedLocation(File file, unsigned line, unsigned column) :
		Location(file), line(line), column(column) { file.notNull(); }
	unsigned line;
	unsigned column;
};

}
