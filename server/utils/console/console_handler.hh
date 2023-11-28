#pragma once
#include "terminal_console.hh"
#include "file_console.hh"

#include <memory>

namespace ConsoleHandler
{
	static TerminalConsole terminalConsole;
	static FileConsole fileConsole;


	void init();
	void uninit();

	void add(IConsole& con);
	void remove(IConsole& con);

	void log(const std::string& str);
	void err(const std::string& str);
}
