#include "Component.h"
Component::Component(Transform* transform, const unsigned int& ID)
	: ComponentID{ ID }, entityTransformPtr{ transform } {}
Component::Component(const Component& source)
	: ComponentID{ source.GetID() }, entityTransformPtr{ source.entityTransformPtr }, transform{ source.transform } {}
Component::Component(Component&& source) noexcept
	: ComponentID{ source.GetID() }, entityTransformPtr{ source.entityTransformPtr }, transform{ source.transform } { entityTransformPtr = nullptr; }
std::unique_ptr<Component> Component::clone() const noexcept { return nullptr; }
const unsigned int& Component::GetID() const noexcept {
	return ComponentID;
}
Transform& Component::GetTransform() noexcept {
	return transform;
}
Transform  Component::GetWorldTransform() const noexcept {
	return transform + *entityTransformPtr;
}
void Component::Start(Microsoft::WRL::ComPtr<ID3D11Device>& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext>& deviceContext) {}
void Component::Update() {}
void Component::Render() {}
void Component::Reset()  {}