#include <libclang++/string_internal.h>

namespace clang {

String::String(std::shared_ptr<String_> from) : p(from)
{
}

String::String(String_* from) : p(from)
{
}

String::~String()
{
}

std::string String::getString() const {
	return clang_getCString(p->string);
}

}
