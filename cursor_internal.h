#pragma once

#include <Index.h>

#include <libclang++/cursor.h>

namespace clang {

class Cursor_ {
	public:
		Cursor_() = delete;
		Cursor_(const Cursor_&) = delete;
		Cursor_& operator=(const Cursor_&) = delete;

		Cursor_(const TranslationUnit& translationunit, const CXCursor& from) : cursor(from), translationunit(translationunit) {}

		~Cursor_(){}

		CXCursorKind getKind() {
			return clang_getCursorKind(cursor);
		}

		CXAvailabilityKind getAvailability() {
			return clang_getCursorAvailability(cursor);
		}

		CXLanguageKind getLanguage() {
			return clang_getCursorLanguage(cursor);
		}
	private:
		CXCursor cursor;
		TranslationUnit translationunit;

		friend class Cursor;
};

}
