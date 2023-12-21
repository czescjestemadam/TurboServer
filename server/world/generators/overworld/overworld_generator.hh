#pragma once
#include "server/world/generators/world_generator.hh"


class OverworldGenerator : public WorldGenerator
{
public:
	explicit OverworldGenerator(long seed);

	Chunk getChunk(int x, int z) override;
	BlockState getBlock(int x, int y, int z) override;
};
