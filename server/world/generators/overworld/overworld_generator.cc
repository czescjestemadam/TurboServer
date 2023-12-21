#include "overworld_generator.hh"

OverworldGenerator::OverworldGenerator(long seed) : WorldGenerator(seed)
{
}

Chunk OverworldGenerator::getChunk(int x, int z)
{
	return {x, z};
}

BlockState OverworldGenerator::getBlock(int x, int y, int z)
{
	return {};
}
