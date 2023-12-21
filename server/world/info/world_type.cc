#include "world_type.hh"

WorldType::WorldType(int id, std::string name) : id(id), name(std::move(name))
{
}


WorldType WorldType::OVERWORLD = { 0, "overworld" };
WorldType WorldType::NETHER = { 1, "nether" };
WorldType WorldType::THE_END = { 2, "the_end" };
