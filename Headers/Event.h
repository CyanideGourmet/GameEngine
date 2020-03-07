#pragma once
#include <list>
class Event
{
private:
	typedef void (*task)(void* data);
	std::list<task> listenersList;
public:
	Event() = default;
	void AddListener(task);
	void RemoveListener(task);
	void Invoke(void* data = nullptr) const noexcept;
};