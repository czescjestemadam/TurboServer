#include <utility>

#include "log_level.hh"

LogLevel::LogLevel(int level, std::string name) : level(level), name(std::move(name))
{
}

int LogLevel::getLevel() const
{
	return level;
}

const std::string& LogLevel::getName() const
{
	return name;
}

bool LogLevel::operator<(const LogLevel& rhs) const
{
	return level < rhs.level;
}

bool LogLevel::operator>(const LogLevel& rhs) const
{
	return rhs < *this;
}

bool LogLevel::operator<=(const LogLevel& rhs) const
{
	return !(rhs < *this);
}

bool LogLevel::operator>=(const LogLevel& rhs) const
{
	return !(*this < rhs);
}

const LogLevel LogLevel::MDEBUG = { 0, "µDEBUG" };
const LogLevel LogLevel::DEBUG = { 1, "DEBUG" };
const LogLevel LogLevel::INFO = { 2, "INFO" };
const LogLevel LogLevel::WARN = { 3, "WARN" };
const LogLevel LogLevel::ERROR = { 4, "ERROR" };
const LogLevel LogLevel::CRASH = { 5, "CRASH" };
