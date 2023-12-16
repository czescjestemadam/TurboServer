#pragma once
#include <string>

class IEvent
{
public:
	virtual ~IEvent() = default;

	virtual std::string getName() const = 0;

	virtual std::string toString() const = 0;
};

class IEventCancelable : public IEvent
{
	bool canceled = false;

public:
	bool isCanceled() const;
	void setCanceled(bool b);
};

inline bool IEventCancelable::isCanceled() const
{
	return canceled;
}

inline void IEventCancelable::setCanceled(bool b)
{
	canceled = b;
}
