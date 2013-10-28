#pragma once

#include <Index.h>

#include <libclang++/index.h>

namespace clang {

class Index_ {
	public:
		Index_() = delete;
		Index_(const Index_&) = delete;
		Index_& operator=(const Index_&) = delete;

		Index_(const CXIndex& from) : index(from) {}

		~Index_(){
			clang_disposeIndex(index);
		}
	private:
		CXIndex index;

		friend Index;
};

}
