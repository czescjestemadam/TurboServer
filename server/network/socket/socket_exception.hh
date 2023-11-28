#pragma once
#include "../../utils/str_exception.hh"

class SocketException : public StrException
{
public:
	explicit SocketException(const std::string& str);
};
