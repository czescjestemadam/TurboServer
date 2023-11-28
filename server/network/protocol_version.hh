#pragma once
#include <string>

class ProtocolVersion
{
	int num;
	std::string name;

public:
	ProtocolVersion(int num, std::string name);

	int getNum() const;
	const std::string& getName() const;

	static const ProtocolVersion& fromNum(int num);
	static const ProtocolVersion& fromString(const std::string& str);

	static const ProtocolVersion vUNKNOWN;
	static const ProtocolVersion v1_16_5;
	static const ProtocolVersion v1_17;
	static const ProtocolVersion v1_17_1;
	static const ProtocolVersion v1_18;
	static const ProtocolVersion v1_18_2;
	static const ProtocolVersion v1_19;
	static const ProtocolVersion v1_19_1;
	static const ProtocolVersion v1_19_3;
	static const ProtocolVersion v1_19_4;
	static const ProtocolVersion v1_20;
	static const ProtocolVersion v1_20_2;
};
