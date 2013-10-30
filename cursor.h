#pragma once

#include <memory>
#include <vector>

namespace clang {
	class Cursor;
}

#include <libclang++/sourcelocation.h>
#include <libclang++/sourcerange.h>
#include <libclang++/exception.h>
#include <libclang++/enum.h>

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
		CURSOR_IS(Definition);
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

		CursorKind getKind() const;
		LinkageKind getLinkageKind() const;
		AvailabilityKind getAvailabilityKind() const;
		LanguageKind getLanguageKind() const;

		SourceLocation getLocation() const;
		SourceRange getRange() const;

		Cursor getReferenced() const;
		Cursor getCannonical() const;
		Cursor getSemanticParent() const;
		Cursor getLexicalParent() const;
		Cursor getDefinition() const;

		SourceRange getCommentRange() const;
		String getNativeBriefComment() const;
		std::string getBriefComment() const {
			return getNativeBriefComment().getString();
		}
		String getNativeRawComment() const;
		std::string getRawComment() const {
			return getNativeRawComment().getString();
		}

		String getNativeSpelling() const;
		std::string getSpelling() const {
			return getNativeSpelling().getString();
		}
		String getNativeDisplayName() const;
		std::string getDisplayName() const {
			return getNativeDisplayName().getString();
		}
		String getNativeUSR() const;
		std::string getUSR() const {
			return getNativeUSR().getString();
		}

		std::vector<Cursor> getChildren() const;
		std::vector<Cursor> getChildrenRecursive() const;

	private:
		std::shared_ptr<Cursor_> p;
};

}
