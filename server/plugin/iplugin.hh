#pragma once

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	virtual void init() = 0;

	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
	virtual void onReload() = 0;

	virtual bool isEnabled() const = 0;
	virtual void setEnabled(bool enabled) = 0;

	virtual const char* getName() const = 0;
	virtual const char* getDescription() const = 0;
	virtual const char* getAuthor() const = 0;
};
