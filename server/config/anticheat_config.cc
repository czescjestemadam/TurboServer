#include "anticheat_config.hh"

#include "json_helper.hh"

void AnticheatConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(movedWronglyThreshold)
	JSON_HELPER_READ(movedTooQuicklyMultiplier)

	JSON_HELPER_READ(antixrayEnable)
	JSON_HELPER_READ(antixrayEngineMode)
	JSON_HELPER_READ(antixrayMinBlockHeight)
	JSON_HELPER_READ(antixrayMaxBlockHeight)
	JSON_HELPER_READ(antixrayUpdateRadius)
	JSON_HELPER_READ(antixrayUsePermission)
	JSON_HELPER_READ(antixrayHiddenBlocks)
	JSON_HELPER_READ(antixrayReplacementBlocks)

	JSON_HELPER_READ(hideItemDurability)
	JSON_HELPER_READ(hideItemItemmeta)
	JSON_HELPER_READ(hideItemItemmetaVisuals)
	JSON_HELPER_READ(hidePlayersOutOfFrustum)
}

nlohmann::json AnticheatConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(movedWronglyThreshold)
	JSON_HELPER_WRITE(movedTooQuicklyMultiplier)

	JSON_HELPER_WRITE(antixrayEnable)
	JSON_HELPER_WRITE(antixrayEngineMode)
	JSON_HELPER_WRITE(antixrayMinBlockHeight)
	JSON_HELPER_WRITE(antixrayMaxBlockHeight)
	JSON_HELPER_WRITE(antixrayUpdateRadius)
	JSON_HELPER_WRITE(antixrayUsePermission)
	JSON_HELPER_WRITE(antixrayHiddenBlocks)
	JSON_HELPER_WRITE(antixrayReplacementBlocks)

	JSON_HELPER_WRITE(hideItemDurability)
	JSON_HELPER_WRITE(hideItemItemmeta)
	JSON_HELPER_WRITE(hideItemItemmetaVisuals)
	JSON_HELPER_WRITE(hidePlayersOutOfFrustum)

	return j;
}

std::string AnticheatConfig::getName()
{
	return "anticheat";
}
