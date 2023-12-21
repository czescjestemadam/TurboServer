#pragma once
#include "terminal_console.hh"
#include "file_console.hh"

namespace ConsoleHandler
{
	static TerminalConsole terminalConsole;
	static FileConsole fileConsole;


	void init();

	void add(IConsole& con);
	void remove(IConsole& con);

	void log(const std::string& str);
	void err(const std::string& str);

	std::string system(const std::string& cmd);
}
