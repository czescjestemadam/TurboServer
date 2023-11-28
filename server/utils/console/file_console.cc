#include "file_console.hh"

void FileConsole::init()
{

}

void FileConsole::uninit()
{

}

bool FileConsole::writeOnly()
{
	return true;
}

void FileConsole::log(const std::string& str)
{

}

void FileConsole::err(const std::string& str)
{

}

std::string FileConsole::readLine()
{
	return {};
}

std::string FileConsole::getName()
{
	return "LogWriter";
}
