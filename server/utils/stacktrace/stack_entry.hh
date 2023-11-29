#pragma once
#include <string>

class StackEntry
{
	std::string function;

public:
	explicit StackEntry(std::string function);

	const std::string& getFunction() const;


	static StackEntry demangle(const std::string& function);
};
