#pragma once

#include <string>

class Permission
{
public:
	std::string name;
	std::string description;
	bool defaultOp = false;
};

class AppliedPermission : public Permission
{
public:
	bool value;
};
