#pragma once

#include <Index.h>

static inline bool clang_File_isNull(CXFile file) {
	return file == nullptr;
}

static inline CXFile clang_getNullFile() {
	return nullptr;
}

static inline bool clang_Location_isNull(CXSourceLocation location) {
	CXFile file;
	unsigned line, column, offset;

	clang_getFileLocation(location, &file, &line, &column, &offset);

	return clang_File_isNull(file);
}
