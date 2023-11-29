#pragma once
#include "iconsole.hh"

#include <thread>

class FileConsole : public IConsole
{
	std::jthread writerThread;

public:
	void init() override;

	void log(const std::string& str) override;
	void err(const std::string& str) override;

	std::string getName() override;
};
