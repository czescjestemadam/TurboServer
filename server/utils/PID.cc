#include "PID.hh"

#include <fstream>
#include <unistd.h>
#include <filesystem>

constexpr const char* PIDFILE = ".pid";

int PID::readFile()
{
	std::ifstream ifs(PIDFILE);
	if (!ifs.good())
		return -1;

	int pid;
	ifs >> pid;

	ifs.close();
	return pid;
}

void PID::writeFile()
{
	std::ofstream ofs(PIDFILE);
	if (ofs.good())
		ofs << getpid();
	ofs.close();
}

void PID::removeFile()
{
	std::filesystem::remove(PIDFILE);
}


int PID::getCurrent()
{
	return getpid();
}
