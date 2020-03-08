#include "Components.h"
#include "Entity.h"
#pragma region Class-specific methods
Entity::Entity(const char* name)
	: componentList{}, entityName{ name }, transform{ {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, {1.f, 1.f, 1.f} } {}
Entity::Entity(const Entity& source)
	: componentList{}, transform{ source.transform }, entityName{ source.GetName() + "0" } {
	for (auto iter{ source.componentList.begin() }; iter != source.componentList.end(); iter++) {
		componentList.emplace_back((*iter)->Clone());
	}
}
Entity::Entity(Entity&& source)
	: componentList{}, transform{ source.transform }, entityName{ source.GetName() } {
	for (auto iter{ source.componentList.begin() }; iter != source.componentList.end(); iter++) {
		componentList.emplace_back(std::move(*iter));
		iter->release();
	}
}
Transform& Entity::GetTransform() noexcept {
	return transform;
}
void Entity::SetName(const char* name) noexcept {
	entityName = name;
}
std::string Entity::GetName() const noexcept {
	return entityName;
}
#pragma endregion
#pragma region Component functionality
void Entity::Start(ID3D11Device* device, ID3D11DeviceContext* deviceContext) {
}
void Entity::Update() {
}
void Entity::Render() {
}
void Entity::Reset() {
}
#pragma endregion
#pragma region Component management
template<typename T> T*							 Entity::AddComponent() {
	if (CheckIfPresent<T>()) { throw("Component already exists! - Change to proper exception later"); }
	componentList.emplace_back(std::make_unique<T>(&transform));
	return dynamic_cast<T*>(componentList.back().get());
}
template<typename T> void						 Entity::RemoveComponent() {
	std::unique_ptr<Component>* component{ CheckIfPresent<T>() };
	if (!component) { throw("Component doesn't exist! - Change to proper exception later"); }
	componentList.remove(*component);
}
template<typename T> T*							 Entity::GetComponent() {
	std::unique_ptr<Component>* component{ CheckIfPresent<T>() };
	if (!component) { throw("Component doesn't exist! - Change to proper exception later"); }
	return dynamic_cast<T*>(component->get());
}
template<typename T> std::unique_ptr<Component>* Entity::CheckIfPresent() {
	std::unique_ptr<Component>* componentPtr{ nullptr };
	if (std::is_base_of<Collider, T>::value && !std::is_base_of<T, Collider>::value) {
		componentPtr = CheckIfPresent<Collider>();
	}
	else {
		for (auto component{ componentList.begin() }; component != componentList.end(); component++) {
			if (dynamic_cast<T*>(component->get())) {
				componentPtr = &*component;
				break;
			}
		}
	}
	return componentPtr;
}
#pragma endregion
#pragma region Template declarations
template Sprite*		 Entity::AddComponent<Sprite>();
template BoxCollider*	 Entity::AddComponent<BoxCollider>();
template SphereCollider* Entity::AddComponent<SphereCollider>();

template void Entity::RemoveComponent<Sprite>();
template void Entity::RemoveComponent<Collider>();
template void Entity::RemoveComponent<BoxCollider>();
template void Entity::RemoveComponent<SphereCollider>();

template Sprite*		 Entity::GetComponent<Sprite>();
template Collider*		 Entity::GetComponent<Collider>();
template BoxCollider*	 Entity::GetComponent<BoxCollider>();
template SphereCollider* Entity::GetComponent<SphereCollider>();

template std::unique_ptr<Component>* Entity::CheckIfPresent<Sprite>();
template std::unique_ptr<Component>* Entity::CheckIfPresent<BoxCollider>();
template std::unique_ptr<Component>* Entity::CheckIfPresent<SphereCollider>();
#pragma endregion