#pragma once
#include "game_rule.hh"

class GameRuleSet
{
	std::vector<GameRule> rules = GameRule::copyValues();

public:
	GameRule* getRule(const GameRule& rule);

	template<class T>
	T get(const GameRule& rule)
	{
		return std::get<T>(getRule(rule)->value);
	}

	template<class T>
	void set(const GameRule& rule, const T& val)
	{
		getRule(rule)->value = val;
	}
};
