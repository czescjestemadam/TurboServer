#include "console_handler.hh"

#include <vector>
#include <iostream>
#include <algorithm>

static std::vector<IConsole*> consoles;

void ConsoleHandler::init()
{
	add(terminalConsole);
	add(fileConsole);
}

void ConsoleHandler::uninit()
{
	remove(terminalConsole);
	remove(fileConsole);
}


void ConsoleHandler::add(IConsole& con)
{
	con.init();
	consoles.push_back(&con);
}

void ConsoleHandler::remove(IConsole& con)
{
	con.uninit();
	consoles.erase(std::find(consoles.begin(), consoles.end(), &con));
}


void ConsoleHandler::log(const std::string& str)
{
	for (IConsole* con : consoles)
		con->log(str);
}

void ConsoleHandler::err(const std::string& str)
{
	for (IConsole* con : consoles)
		con->err(str);
}
