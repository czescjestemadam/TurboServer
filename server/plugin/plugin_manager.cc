#include "plugin_manager.hh"

bool PluginManager::load(const std::string& name)
{
	//todo
	return false;
}

void PluginManager::unload(const std::string& name)
{
	disable(name);

	IPlugin* plg = getPlugin(name);
	//todo
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
