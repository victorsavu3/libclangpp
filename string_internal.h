#pragma once

#include <string>

#include <Index.h>

#include <libclang++/string.h>

namespace clang {

class String_ {
	public:
		String_() = delete;
		String_(const String_&) = delete;
		String_& operator=(const String_&) = delete;

		String_(const CXString& from) : string(from) {}

		~String_(){
			clang_disposeString(string);
		}
	private:
		CXString string;

		friend String;
};

}
