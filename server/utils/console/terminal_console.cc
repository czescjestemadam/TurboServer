#include "terminal_console.hh"

#include <iostream>

void TerminalConsole::init()
{

}

void TerminalConsole::uninit()
{

}

bool TerminalConsole::writeOnly()
{
	return false;
}

void TerminalConsole::log(const std::string& str)
{
	std::cout << colorReplacer(str) << '\n';
}

void TerminalConsole::err(const std::string& str)
{
	std::cout << colorReplacer(str) << '\n';
}

std::string TerminalConsole::readLine()
{
	return "line";
}

std::string TerminalConsole::getName()
{
	return "Console";
}


std::string TerminalConsole::colorReplacer(const std::string& str)
{
	std::string ret = str;

	

	return ret;
}
