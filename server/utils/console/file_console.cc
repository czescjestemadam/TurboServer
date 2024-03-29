#include "file_console.hh"

#include <functional>
#include <filesystem>
#include <format>

FileConsole::~FileConsole()
{
	running = false;
	logQueueCv.notify_one();
}

void FileConsole::init()
{
	running = true;
	std::filesystem::create_directory(std::filesystem::current_path() / "logs");
	writerThread = std::jthread(std::bind(&FileConsole::writerLoop, this));
}

void FileConsole::log(const std::string& str)
{
	{
		std::unique_lock lock(logQueueMx);
		logQueue.push_back(str);
	}
	logQueueCv.notify_one();
}

void FileConsole::err(const std::string& str)
{
	log(str);
}

std::string FileConsole::getName()
{
	return "LogWriter";
}


std::string FileConsole::stripColors(const std::string& str)
{
	std::string ret = str;

	for (int i = 0; i < 1024; i++)
	{
		const ulong pos = ret.find("§");
		if (pos < ret.length())
			ret.erase(pos, 3);
	}

	return ret;
}

void FileConsole::writerLoop()
{
	while (running)
	{
		std::unique_lock lock(logQueueMx);
		while (logQueue.empty() && running)
			logQueueCv.wait(lock);

		if (!running)
			return;

		std::string str = logQueue.front();
		logQueue.pop_front();

		updateOfs();
		ofs << stripColors(str) << std::endl;
	}
}

void FileConsole::updateOfs()
{
	const std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

	const std::string nextFile = std::format("{}-{}-{}.log", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);

	if (file != nextFile)
	{
		file = nextFile;

		if (ofs.is_open())
			ofs.close();

		ofs.open("logs/" + file, std::ios::out | std::ios::app);

		constexpr const char* LINK = "logs/latest.log";
		if (std::filesystem::exists(LINK))
			std::filesystem::remove(LINK);

		std::filesystem::create_symlink(nextFile, LINK);
	}
}
