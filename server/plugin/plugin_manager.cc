#include "plugin_manager.hh"

#include <filesystem>

static std::filesystem::path PLUGINS_DIR = std::filesystem::current_path() / "plugins";

void PluginManager::loadAll()
{
	for (const std::string& name : listPluginsDir())
		load(name);
}

void PluginManager::unloadAll()
{
	for (const std::string& name : getPlugins())
		unload(name);
}

bool PluginManager::load(const std::string& name)
{
	//todo
	return false;
}

void PluginManager::unload(const std::string& name)
{
	IPlugin* plg = getPlugin(name);
	if (!plg)
		return;

	if (plg->isEnabled())
	{
		plg->setEnabled(false);
		plg->onDisable();
	}

	//todo unload lib
}

IPlugin* PluginManager::getPlugin(const std::string& name) const
{
	for (const std::unique_ptr<IPlugin>& plg : plugins)
		if (name == plg->getName())
			return plg.get();

	return nullptr;
}

void PluginManager::enable(const std::string& name)
{
	IPlugin* plg = getPlugin(name);
	if (!plg || plg->isEnabled())
		return;

	plg->setEnabled(true);
	plg->onEnable();
}

void PluginManager::disable(const std::string& name)
{
	IPlugin* plg = getPlugin(name);
	if (!plg || !plg->isEnabled())
		return;

	plg->setEnabled(false);
	plg->onDisable();
}

void PluginManager::reload(const std::string& name)
{
	IPlugin* plg = getPlugin(name);
	if (!plg || !plg->isEnabled())
		return;

	plg->onReload();
}

bool PluginManager::isEnabled(const std::string& name) const
{
	const IPlugin* plugin = getPlugin(name);
	return plugin && plugin->isEnabled();
}

std::vector<std::string> PluginManager::getPlugins() const
{
	std::vector<std::string> names;

	for (const std::unique_ptr<IPlugin>& plg : plugins)
		names.push_back(plg->getName());

	return names;
}


std::vector<std::string> PluginManager::listPluginsDir() const
{
	std::vector<std::string> names;

	for (auto& dir : std::filesystem::directory_iterator(PLUGINS_DIR))
	{
		if (dir.is_directory())
			names.push_back(dir.path().filename().string());
	}

	return names;
}
