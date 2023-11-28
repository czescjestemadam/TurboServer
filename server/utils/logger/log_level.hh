#pragma once
#include <string>

class LogLevel
{
	int level;
	std::string name;

public:
	LogLevel(int level, std::string name);

	int getLevel() const;

	const std::string& getName() const;

	bool operator<(const LogLevel& rhs) const;
	bool operator>(const LogLevel& rhs) const;
	bool operator<=(const LogLevel& rhs) const;
	bool operator>=(const LogLevel& rhs) const;

	static const LogLevel MDEBUG;
	static const LogLevel DEBUG;
	static const LogLevel INFO;
	static const LogLevel WARN;
	static const LogLevel ERROR;
	static const LogLevel CRASH;
};
