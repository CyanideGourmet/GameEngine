#include "Component.h"
Component::Component(Transform* transform, const unsigned int& ID)
	: ComponentID{ ID }, entityTransformPtr{ transform }, transform{ {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, {1.f, 1.f, 1.f} } {}
Component::Component(const Component& source)
	: ComponentID{ source.GetID() }, entityTransformPtr{ source.entityTransformPtr }, transform{ source.transform } {}
Component::Component(Component&& source) noexcept
	: ComponentID{ source.GetID() }, entityTransformPtr{ source.entityTransformPtr }, transform{ source.transform } { entityTransformPtr = nullptr; }

const unsigned int& Component::GetID() const noexcept {
	return ComponentID;
}
Transform& Component::GetTransform() noexcept {
	return transform;
}
Transform  Component::GetWorldTransform() const noexcept {
	return transform + *entityTransformPtr;
}