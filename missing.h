#pragma once

#include <Index.h>

#include <type_traits>

static_assert(std::is_same<CXFile, void*>::value, "Expected CXFile to be void*");

static inline bool clang_File_isNull(CXFile file) {
	return file == nullptr;
}

static inline CXFile clang_getNullFile() {
	return nullptr;
}

static inline bool clang_Location_isNull(CXSourceLocation location) {
	// inspired by the implementation of clang_Range_isNull()
	return clang_equalLocations(location, clang_getNullLocation());
}
