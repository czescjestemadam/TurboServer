#pragma once

template<class Ev>
class IEventListener
{
public:
	virtual ~IEventListener() = default;

	virtual void onEvent(Ev& e) = 0;
};
