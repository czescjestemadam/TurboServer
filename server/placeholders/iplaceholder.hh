#pragma once
#include <string>

class PlayerEntity;

class IPlaceholder
{
public:
	virtual ~IPlaceholder() = default;

	virtual std::string getName() = 0;

	virtual std::string getReplacement() = 0;
	virtual std::string getReplacementFor(PlayerEntity* player);
};

inline std::string IPlaceholder::getReplacementFor(PlayerEntity* player)
{
	return getReplacement();
}
