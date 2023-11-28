#pragma once
#include "iconsole.hh"

#include <thread>

class TerminalConsole : public IConsole
{
	std::jthread readerThread;

public:
	void init() override;
	void uninit() override;

	bool writeOnly() override;
	void log(const std::string& str) override;
	void err(const std::string& str) override;

	std::string readLine() override;

	std::string getName() override;

private:
	std::string colorReplacer(const std::string& str);
};
