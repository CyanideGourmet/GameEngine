#include "Drawable.h"
Drawable::Drawable(Transform* transform, const unsigned int& ID)
	: Component::Component(transform, ID) {}
void Drawable::SetResource(const wchar_t* resource) {
	resourceName = resource;
}
const std::wstring& Drawable::GetResourceName() const noexcept {
	return resourceName;
}
