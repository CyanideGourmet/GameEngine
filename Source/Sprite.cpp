#include "Sprite.h"

Sprite::Sprite(Transform* transform)
	: Drawable::Drawable(transform, ComponentID) {}
std::unique_ptr<Component> Sprite::Clone() const noexcept {
	auto sprite{ std::make_unique<Sprite>(entityTransformPtr) };
	sprite->transform = transform;
	sprite->resourceName = resourceName;
	return sprite;
}