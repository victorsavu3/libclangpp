#pragma once

#include <Index.h>

#include <libclang++/tokens.h>

#include <iostream>

#include <libclang++/translationunit_internal.h>
#include <libclang++/sourcerange_internal.h>

namespace clang {

class Tokens_ {
	public:
		Tokens_() = delete;
		Tokens_(const Tokens_&) = delete;
		Tokens_& operator=(const Tokens_&) = delete;

		Tokens_(TranslationUnit from, SourceRange range) : from(from)
		{
			range.notNull();

			clang_tokenize(from.p->translationunit, range.p->sourcerange, &tokens, &count);
			if(count > 0) {
				cursors = new CXCursor[count];
				clang_annotateTokens(from.p->translationunit, tokens, count, cursors);
			} else {
				cursors = nullptr;
			}
		}

		~Tokens_(){
			clang_disposeTokens(from.p->translationunit, tokens, count);
			if(cursors)
				delete[] cursors;
		}

	private:
		TranslationUnit from;
		CXToken* tokens;
		CXCursor* cursors;
		unsigned int count;

		friend Tokens;
};

}
