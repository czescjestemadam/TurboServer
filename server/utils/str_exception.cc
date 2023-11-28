#include "str_exception.hh"

StrException::StrException(std::string str) : str(std::move(str))
{
}

const char* StrException::what() const noexcept
{
	return str.c_str();
}
