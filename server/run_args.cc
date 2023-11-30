#include "run_args.hh"
#include "server/utils/str_utils.hh"

#include <algorithm>
#include <format>

static RunArgs* inst;

RunArgs::RunArgs(int argc, char **argv)
{
	inst = this;

	argsStr.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		argsStr.emplace_back(argv[i]);
}

void RunArgs::parse()
{
	std::string currentArg;
	std::string currentVal;

	for (const std::string& arg : argsStr)
	{
		if (arg.starts_with("--"))
		{
			if (!currentArg.empty() && currentVal.empty()) // flag, next
				flags.push_back(currentArg);
			else if (!currentArg.empty() && !currentVal.empty()) // arg, next
			{
				args.insert_or_assign(currentArg, currentVal);
				currentVal.clear();
			}

			currentArg = arg.substr(2);
		}
		else
		{
			if (currentVal.empty())
				currentVal = arg;
			else
				currentVal += ' ' + arg;
		}
	}

	if (!currentArg.empty() && currentVal.empty()) // flag
		flags.push_back(currentArg);
	else if (!currentArg.empty() && !currentVal.empty()) // arg
		args.insert_or_assign(currentArg, currentVal);

	argsStr.clear();
}

bool RunArgs::hasFlag(const std::string& name) const
{
	return std::find(flags.begin(), flags.end(), name) != flags.end();
}

std::optional<std::string> RunArgs::getArg(const std::string& name) const
{
	return args.contains(name) ? std::make_optional<>(args.at(name)) : std::nullopt;
}

std::string RunArgs::toString() const
{
	return std::format("RunArgs[flags={}, args={}]", StrUtils::vectorToString(flags), StrUtils::mapToString(args));
}


RunArgs* RunArgs::get()
{
	return inst;
}
