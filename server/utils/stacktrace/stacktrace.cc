#include "stacktrace.hh"

#include <execinfo.h>

Stacktrace::Stacktrace(std::vector<StackEntry>&& entries) : entries(entries)
{
}

std::string Stacktrace::toString() const
{
	std::string str;

	for (const StackEntry& entry : entries)
		str += "\n\t\t" + entry.getFunction();

	return str;
}


Stacktrace Stacktrace::get(int num, int skip)
{
	++skip;

	std::vector<StackEntry> entries;

	void* trace[num];
	int traceSize = backtrace(trace, num + skip);

	char** msgs = backtrace_symbols(trace, num);

	for (int i = skip; i < traceSize; ++i)
		entries.push_back(StackEntry::demangle(msgs[i]));

	free(msgs);

	return Stacktrace(std::move(entries));
}
