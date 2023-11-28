#include "game_rule_set.hh"

GameRule* GameRuleSet::getRule(const GameRule& rule)
{
	for (GameRule& r : rules)
		if (r == rule)
			return &r;

	return nullptr;
}
