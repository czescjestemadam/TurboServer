#pragma once
#include "../str_exception.hh"

class TaskException : public StrException
{
public:
	explicit TaskException(const std::string& str);
};
