#pragma once
#include "iconsole.hh"
#include "server/commands/command_sender.hh"
#include "server/network/socket/epoll_socket.hh"

#include <thread>
#include <mutex>
#include <condition_variable>

class TerminalConsole : public IConsole, public CommandSender
{
	EpollSocket epoll;
	std::jthread readerThread;
	bool running = false;

	std::string line;
	uint cursor;

public:
	~TerminalConsole() override;

	void init() override;

	void log(const std::string& str) override;
	void err(const std::string& str) override;

	std::string getName() override;

	void sendMessage(const std::string& msg) override;
	void sendMessage(const std::vector<std::string>& msg) override;

private:
	std::string colorReplacer(const std::string& str);

	void readerLoop();
	inline void printPrompt();
	inline void print(std::ostream& os, const std::string& str);

	static void sigintHandler(int i);
	static void sigtstpHandler(int i);
};
