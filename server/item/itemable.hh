#pragma once
#include "item.hh"

class Itemable
{
public:
	virtual Item asItem() = 0;
};
