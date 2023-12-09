#pragma once
#include "iplugin.hh"

#include <vector>
#include <memory>
#include <string>

class PluginManager
{
	std::vector<std::unique_ptr<IPlugin>> plugins;

public:
	void loadAll();
	void unloadAll();

	bool load(const std::string& name);
	void unload(const std::string& name);

	IPlugin* getPlugin(const std::string& name) const;

	void enable(const std::string& name);
	void disable(const std::string& name);
	void reload(const std::string& name);

	bool isEnabled(const std::string& name) const;

	std::vector<std::string> getPlugins() const;
	std::vector<std::string> listPluginsDir() const;
};
