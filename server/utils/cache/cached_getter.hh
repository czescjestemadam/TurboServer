#pragma once
#include <map>
#include <chrono>
#include <functional>

template<class K, class V>
class CachedGetter
{
	std::map<K, std::pair<V, std::chrono::system_clock::time_point>> cache;
	std::chrono::system_clock::duration cacheValidTime;
	std::function<V(K)> getter;

public:
	CachedGetter(const std::chrono::system_clock::duration& cacheValidTime, const std::function<V(K)>& getter) : cacheValidTime(cacheValidTime), getter(getter)
	{
	}

	V& get(const K& key)
	{
		if (cache.contains(key))
		{
			auto& [ val, timestamp ] = cache[key];

			if (std::chrono::system_clock::now() - timestamp <= cacheValidTime)
				return val;
		}

		cache[key] = { getter(key), std::chrono::system_clock::now() };
		return cache[key].first;
	}

	void invalidate(const K& key)
	{
		cache.erase(key);
	}

	void invalidate()
	{
		cache.clear();
	}
};
