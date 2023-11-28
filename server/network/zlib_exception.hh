#pragma once
#include "../utils/str_exception.hh"

class ZlibException : public StrException
{
public:
	explicit ZlibException(const std::string& str);
};
