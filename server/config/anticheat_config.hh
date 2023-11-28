#pragma once
#include "iconfig.hh"

class AnticheatConfig : public IConfig
{
public:
	float movedWronglyThreshold = 0.0625f;
	int movedTooQuicklyMultiplier = 10;

	bool antixrayEnable = false;
	int antixrayEngineMode = 1;
	int antixrayMinBlockHeight = 3;
	int antixrayMaxBlockHeight = 64;
	int antixrayUpdateRadius = 2;
	bool antixrayUsePermission = false;
	std::vector<std::string> antixrayHiddenBlocks = {};//todo
	std::vector<std::string> antixrayReplacementBlocks = {};

	bool hideItemDurability = false;
	bool hideItemItemmeta = false;
	bool hideItemItemmetaVisuals = false;
	bool hidePlayersOutOfFrustum = false;

	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
