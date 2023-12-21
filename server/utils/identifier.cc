#include "identifier.hh"

Identifier::Identifier(const std::string& str)
{
	bool spaceSet = false;
	for (const char c : str)
	{
		if (c == ':')
		{
			spaceSet = true;
			continue;
		}

		std::string& toWrite = spaceSet ? key : space;
		toWrite += c;
	}
}

Identifier::Identifier(std::string space, std::string key) : space(std::move(space)), key(std::move(key))
{
}

const std::string& Identifier::getSpace() const
{
	return space;
}

const std::string& Identifier::getKey() const
{
	return key;
}

std::string Identifier::toString() const
{
	return space + ':' + key;
}

Identifier Identifier::mc(const std::string& key)
{
	return { "minecraft", key };
}

Identifier Identifier::ts(const std::string& key)
{
	return { "turboserver", key };
}

Identifier Identifier::nil()
{
	return { "", "" };
}
