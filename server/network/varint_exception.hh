#pragma once
#include "../utils/str_exception.hh"

class VarintException : public StrException
{
public:
	explicit VarintException(const std::string& str);
};
