#include "protocol_version.hh"

#include <vector>

static std::vector<ProtocolVersion*> versions;

ProtocolVersion::ProtocolVersion(int num, std::string name) : num(num), name(std::move(name))
{
	versions.push_back(this);
}

int ProtocolVersion::getNum() const
{
	return num;
}

const std::string& ProtocolVersion::getName() const
{
	return name;
}


const ProtocolVersion& ProtocolVersion::fromNum(int num)
{
	for (ProtocolVersion* ver : versions)
		if (ver->num == num)
			return *ver;

	return vUNKNOWN;
}

const ProtocolVersion& ProtocolVersion::fromString(const std::string& str)
{
	for (ProtocolVersion* ver : versions)
		if (ver->name == str)
			return *ver;

	return vUNKNOWN;
}

const ProtocolVersion ProtocolVersion::vUNKNOWN = { -1, "unknown" };
const ProtocolVersion ProtocolVersion::v1_16_5 = { 754, "1.16.5" };
const ProtocolVersion ProtocolVersion::v1_17 = { 755, "1.17" };
const ProtocolVersion ProtocolVersion::v1_17_1 = { 756, "1.17.1" };
const ProtocolVersion ProtocolVersion::v1_18 = { 757, "1.18" };
const ProtocolVersion ProtocolVersion::v1_18_2 = { 758, "1.18.2" };
const ProtocolVersion ProtocolVersion::v1_19 = { 759, "1.19" };
const ProtocolVersion ProtocolVersion::v1_19_1 = { 760, "1.19.1" };
const ProtocolVersion ProtocolVersion::v1_19_3 = { 761, "1.19.3" };
const ProtocolVersion ProtocolVersion::v1_19_4 = { 762, "1.19.4" };
const ProtocolVersion ProtocolVersion::v1_20 = { 763, "1.20" };
const ProtocolVersion ProtocolVersion::v1_20_2 = { 764, "1.20.2" };
