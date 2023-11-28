#pragma once
#include <string>

class Difficulty
{
	int id;
	std::string name;

public:
	Difficulty(int id, std::string name);

	int getId() const;
	const std::string& getName() const;


	static const Difficulty PEACEFUL;
	static const Difficulty EASY;
	static const Difficulty NORMAL;
	static const Difficulty HARD;
};
