#include "terminal_console.hh"
#include "server/turbo_server.hh"
#include "console_handler.hh"
#include "stdin_socket.hh"

#include <iostream>
#include <functional>
#include <termios.h>
#include <csignal>

TerminalConsole::~TerminalConsole()
{
	running = false;
}

void TerminalConsole::init()
{
	termios ts{};
	tcgetattr(STDIN_FILENO, &ts);
	ts.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &ts);

	std::signal(SIGINT, &sigintHandler);
	std::signal(SIGTSTP, &sigtstpHandler);

	running = true;

	epoll.create();
	StdinSocket sock;
	epoll.add(sock);

	readerThread = std::jthread(std::bind(&TerminalConsole::readerLoop, this));
	readerThread.detach();
}

void TerminalConsole::log(const std::string& str)
{
	print(std::cout, str);
}

void TerminalConsole::err(const std::string& str)
{
	print(std::cerr, str);
}

std::string TerminalConsole::getName()
{
	return "Console";
}

void TerminalConsole::sendMessage(const std::string& msg)
{
	ConsoleHandler::log(msg);
}

void TerminalConsole::sendMessage(const std::vector<std::string>& msg)
{
	for (const std::string& str : msg)
		log(str);
}


std::string TerminalConsole::colorReplacer(const std::string& str)
{
	std::string ret = str;

	for (int i = 0; i < 1024; i++)
	{
		ulong pos = ret.find("§");
		if (pos >= ret.length())
			break;

		char nextChar = ret[pos + 2];
		const ChatFormat* fmt = ChatFormat::fromCode(nextChar);

		ret.erase(pos, 3);
		if (!fmt)
			continue;

		std::string toInsert = "\033[";

		if (fmt->ansiResetPrefix())
			toInsert += "0;";
		toInsert += std::to_string(fmt->ansiCode) + "m";

		ret.insert(pos, toInsert);
	}

	return ret + "\033[0m";
}

void TerminalConsole::readerLoop()
{
	enum state
	{
		text,
		escape,
		escape_bracket
	} st = text;

	while (running)
	{
		std::vector<epoll_event> events = epoll.wait();
		for (epoll_event& e : events)
		{
			int c = std::getchar();

			switch (st)
			{
				case text:
					switch (c)
					{
						case 10: // enter
							if (!TurboServer::get()->getCommandManager().execute(TurboServer::getConsoleSender(), line))
								print(std::cout, ChatFormat::RED + "Unknown command");
							line.clear();
							cursor = 0;
							break;

						case 127: // backspace
							if (line.empty())
								break;
							line.erase(line.end() - 1);
							--cursor;
							break;

						case 27: // escape
							st = escape;
							break;

						default:
							char cs[2] = { (char)c, 0 };
							line.insert(cursor++, cs);
							break;
					}
					break;

				case escape:
					if (c == '[')
						st = escape_bracket;
					break;

				case escape_bracket:
					switch (c)
					{
						case 'A': // up
							break;

						case 'B': // down
							break;

						case 'C': // right
							if (cursor < line.length())
								++cursor;
							break;

						case 'D': // left
							if (cursor > 0)
								--cursor;
							break;

						case 'H': // home
							cursor = 0;
							break;

						case 'F': // end
							cursor = line.length();
							break;

						default:
							break;
					}
					st = text;
					break;

				default:
					break;
			}

			printPrompt();
		}
	}
}

#define ERASE_TO_END "\033[K"
#define MOVE_LEFT(x) "\033[" << x << "D"

void TerminalConsole::printPrompt()
{
	std::cout << "\r> " + line + ERASE_TO_END;
	if (cursor < line.length())
		std::cout << MOVE_LEFT(line.length() - cursor);
	std::cout.flush();
}

void TerminalConsole::print(std::ostream& os, const std::string& str)
{
	os << '\r' << colorReplacer(str) << std::endl;
	printPrompt();
}


void TerminalConsole::sigintHandler(int i)
{
	std::cout << "\rpress again to stop the server\n";

	static std::chrono::steady_clock::time_point last;
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

	if (now - last < std::chrono::milliseconds(400))
	{
		std::cout << "\rresetting sigint handler\n";
		std::signal(SIGINT, SIG_DFL);
		TurboServer::get()->stop();
	}
	last = now;

	ConsoleHandler::terminalConsole.printPrompt();
}

void TerminalConsole::sigtstpHandler(int i)
{

}
