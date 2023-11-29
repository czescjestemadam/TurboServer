#include "stack_entry.hh"
#include "../console/console_handler.hh"

#include <algorithm>

StackEntry::StackEntry(std::string function) : function(std::move(function))
{
}

const std::string& StackEntry::getFunction() const
{
	return function;
}


StackEntry StackEntry::demangle(const std::string& function)
{
	if (function.starts_with('['))
		return StackEntry(function);

	bool binComplete = false;
	std::string bin;
	std::string addr;

	for (char c : function)
	{
		if (c == ')')
			break;

		if (c == '(')
			binComplete = true;
		else
			(binComplete ? addr : bin) += c;
	}

	std::string ret = ConsoleHandler::system("addr2line -Csfe " + bin + ' ' + addr);
	std::replace(ret.begin(), ret.end(), '\n', ' ');

	return StackEntry(ret);
}
