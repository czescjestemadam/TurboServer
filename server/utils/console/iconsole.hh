#pragma once
#include <string>

class IConsole
{
public:
	virtual ~IConsole() = default;

	virtual void init() = 0;
	virtual void uninit() = 0;

	virtual bool writeOnly() = 0;
	virtual void log(const std::string& str) = 0;
	virtual void err(const std::string& str) = 0;

	virtual std::string readLine() = 0;

	virtual std::string getName() = 0;
};
