#include "console_handler.hh"
#include "server/run_args.hh"

#include <vector>
#include <algorithm>
#include <iostream>

static std::vector<IConsole*> consoles;

void ConsoleHandler::init()
{
	add(terminalConsole);
	if (!RunArgs::get()->hasFlag("no-logs"))
		add(fileConsole);
}


void ConsoleHandler::add(IConsole& con)
{
	con.init();
	consoles.push_back(&con);
}

void ConsoleHandler::remove(IConsole& con)
{
	consoles.erase(std::ranges::find(consoles, &con));
}


void ConsoleHandler::log(const std::string& str)
{
	if (consoles.empty())
		std::cout << str << std::endl;

	for (IConsole* con : consoles)
		con->log(str);
}

void ConsoleHandler::err(const std::string& str)
{
	if (consoles.empty())
		std::cerr << str << std::endl;

	for (IConsole* con : consoles)
		con->err(str);
}


std::string ConsoleHandler::system(const std::string& cmd)
{
	std::string str;
	char buff[256];

	FILE* file = popen(cmd.c_str(), "r");
	if (file)
	{
		while (!feof(file))
		{
			if (fgets(buff, 256, file) != nullptr)
				str.append(buff);
		}
		pclose(file);
	}

	return str;
}
