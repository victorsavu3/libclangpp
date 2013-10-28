#pragma once

#include <memory>

namespace clang {

class String_;

class String {
	public:
		String() = delete;
		String(const String&) = default;
		String& operator=(const String&) = default;

		String(std::shared_ptr<String_> from);
		String(String_* from);

		std::string getString() const;

		~String();
	private:
		std::shared_ptr<String_> p;
};

}
