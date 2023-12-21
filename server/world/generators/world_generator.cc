#include "world_generator.hh"

WorldGenerator::WorldGenerator(long seed) : seed(seed)
{
}


std::unique_ptr<WorldGenerator> WorldGenerator::forType(WorldType* type, long seed)
{
	return nullptr;
}
