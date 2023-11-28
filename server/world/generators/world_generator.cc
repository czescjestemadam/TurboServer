#include "world_generator.hh"

WorldGenerator::WorldGenerator(long seed) : seed(seed)
{
}

long WorldGenerator::getSeed() const
{
	return seed;
}
