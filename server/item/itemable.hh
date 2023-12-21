#pragma once
#include "item.hh"

class Itemable
{
public:
	virtual ~Itemable() = default;

	virtual Item asItem() = 0;
};
