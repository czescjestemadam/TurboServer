#pragma once
#include <string>
#include <exception>

class StrException : public std::exception
{
	std::string str;

public:
	explicit StrException(std::string str);

	const char* what() const noexcept override;
};
