#pragma once
#include "../iplaceholder.hh"

class PlayercountPlaceholder : public IPlaceholder
{
public:
	std::string getName() override;

	std::string getReplacement() override;
	std::string getReplacementFor(PlayerEntity* player) override;
};
