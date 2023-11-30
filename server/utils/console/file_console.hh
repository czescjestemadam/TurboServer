#pragma once
#include "iconsole.hh"

#include <deque>
#include <thread>
#include <fstream>
#include <mutex>
#include <condition_variable>

class FileConsole : public IConsole
{
	bool running = false;

	std::deque<std::string> logQueue;
	std::mutex logQueueMx;
	std::condition_variable logQueueCv;

	std::string file;
	std::ofstream ofs;
	std::jthread writerThread;

public:
	~FileConsole() override;

	void init() override;

	void log(const std::string& str) override;
	void err(const std::string& str) override;

	std::string getName() override;

private:
	std::string stripColors(const std::string& str);

	void writerLoop();
	void updateOfs();
};
