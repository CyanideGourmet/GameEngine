#include "Event.h"
void Event::AddListener(task listener) {
	listenersList.push_back(listener);
}
void Event::RemoveListener(task listener) {
	listenersList.remove(listener);
}
void Event::Invoke(void* data) const noexcept {
	for (auto taskIt{ listenersList.begin() }; taskIt != listenersList.end(); taskIt++) {
		(*taskIt)(data);
	}
}