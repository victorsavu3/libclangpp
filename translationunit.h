#pragma once

#include <memory>

namespace clang {
	class TranslationUnit;
}

#include <libclang++/cursor.h>
#include <libclang++/sourcelocation.h>
#include <libclang++/sourcerange.h>
#include <libclang++/string.h>
#include <libclang++/tokens.h>
#include <libclang++/index.h>
#include <libclang++/file.h>

namespace clang {

class TranslationUnit_;

class TranslationUnit {
	public:
		TranslationUnit() = delete;
		TranslationUnit(const TranslationUnit&) = default;
		TranslationUnit& operator=(const TranslationUnit&) = default;

		TranslationUnit(std::shared_ptr<TranslationUnit_> from);
		TranslationUnit(TranslationUnit_* from);

		~TranslationUnit();

		String getNativeName() const;
		std::string getName() const { return getNativeName().getString(); }
		Tokens getTokens(SourceRange range) const;

		File getFile(const std::string& name) const;

	private:
		std::shared_ptr<TranslationUnit_> p;

		friend class Tokens_;
		friend class Token_;
		friend class SourceLocation;
		friend class SourceRange_;
		friend class File;
};

}
