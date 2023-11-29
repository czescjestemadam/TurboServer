#pragma once
#include "stack_entry.hh"

#include <vector>

class Stacktrace
{
	std::vector<StackEntry> entries;

public:
	explicit Stacktrace(std::vector<StackEntry>&& entries);

	std::string toString() const;


	static Stacktrace get(int num = 16, int skip = 0);
};
