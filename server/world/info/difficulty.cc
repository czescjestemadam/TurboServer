#include <utility>

#include "difficulty.hh"

Difficulty::Difficulty(int id, std::string name) : id(id), name(std::move(name))
{
}

int Difficulty::getId() const
{
	return id;
}

const std::string& Difficulty::getName() const
{
	return name;
}


const Difficulty Difficulty::PEACEFUL = { 0, "peaceful" };
const Difficulty Difficulty::EASY = { 1, "easy" };
const Difficulty Difficulty::NORMAL = { 2, "normal" };
const Difficulty Difficulty::HARD = { 3, "hard" };
