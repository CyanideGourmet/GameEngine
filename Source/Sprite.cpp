#include "Sprite.h"

Sprite::Sprite(Transform* transform)
	: Component::Component(transform, ComponentID) {}
std::unique_ptr<Component> Sprite::Clone() const noexcept {
	auto sprite{ std::make_unique<Sprite>(entityTransformPtr) };
	sprite->transform = transform;
	sprite->resourceName = resourceName;
	return sprite;
}
void Sprite::SetResource(const wchar_t* resource) {
	resourceName = resource;
}
const std::wstring& Sprite::GetResourceName() const noexcept {
	return resourceName;
}