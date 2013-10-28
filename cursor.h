#pragma once

#include <memory>

namespace clang {
	class Cursor;
}

#include <libclang++/sourcelocation.h>
#include <libclang++/sourcerange.h>
#include <libclang++/exception.h>

namespace clang {

class Cursor_;

class Cursor {
	public:
		Cursor() = delete;
		Cursor(const Cursor&) = default;
		Cursor& operator=(const Cursor&) = default;

		Cursor(std::shared_ptr<Cursor_> from);
		Cursor(Cursor_* from);

		~Cursor();

#define CURSOR_IS(WHAT) bool is##WHAT() const;

		CURSOR_IS(Null);
		CURSOR_IS(BitField);
		CURSOR_IS(DynamicCall);
		CURSOR_IS(Variadic);
		CURSOR_IS(Declaration);
		CURSOR_IS(Reference);
		CURSOR_IS(Expression);
		CURSOR_IS(Statement);
		CURSOR_IS(Attribute);
		CURSOR_IS(Invalid);
		CURSOR_IS(TranslationUnit);
		CURSOR_IS(Preprocessing);
		CURSOR_IS(Unexposed);
#undef CURSOR_IS

		void notNull() const {
			if(isNull())
				throw NullValueUsed<Cursor>();
		}

		SourceLocation getLocation() const;
		SourceRange getRange() const;
	private:
		std::shared_ptr<Cursor_> p;
};

}
