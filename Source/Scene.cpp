#include "Components.h"
#include "Entity.h"
#include "Scene.h"

Scene::Scene(const char* name)
	: sceneName{ name } {}
Scene::Scene(const Scene& source)
	: sceneName{ source.sceneName }, entityList{ source.entityList } {}
Entity* Scene::AddEntity(const char* name) noexcept {
	entityList.emplace_back(name);
	return &entityList.back();
}
Entity* Scene::GetEntity(const char* name) {
	auto entityIt{ std::find_if(entityList.begin(), entityList.end(), [&](const Entity& entity) { return entity.GetName() == name; }) };
	if (entityIt == entityList.end()) { throw("No such entity!"); }
	return &*entityIt;
}
void Scene::RemoveEntity(const char* name) {
	auto entityIt{ std::find_if(entityList.begin(), entityList.end(), [&](const Entity& entity) { return entity.GetName() == name; }) };
	if (entityIt == entityList.end()) { throw("No such entity!"); }
	entityList.erase(entityIt);
}
void Scene::Start(ID3D11Device* device, ID3D11DeviceContext* deviceContext) {
	for (auto iter{ entityList.begin() }; iter != entityList.end(); iter++) {
		iter->Start(device, deviceContext);
	}
}
void Scene::Update() {
	for (auto iter{ entityList.begin() }; iter != entityList.end(); iter++) {
		iter->Update();
	}
}
void Scene::Render() {
	for (auto iter{ entityList.begin() }; iter != entityList.end(); iter++) {
		iter->Render();
	}
}
void Scene::Reset() {
	for (auto iter{ entityList.begin() }; iter != entityList.end(); iter++) {
		iter->Reset();
	}
}