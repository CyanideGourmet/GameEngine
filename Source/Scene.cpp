#include "Components.h"
#include "Entity.h"
#include "Scene.h"
#include <algorithm>

Scene::Scene(const char* name)
	: sceneName{ name } {}
void Scene::Initialize() {
	std::for_each(entityList.begin(), entityList.end(),
		[&](const std::shared_ptr<Entity>& entity) {
			if (entity->GetComponent<Drawable>()) {
				drawableList.push_back(entity);
			}
		});
	drawableList.remove_if(
		[&](const std::shared_ptr<Entity>& entity) {
			return !entity->GetComponent<Drawable>();
		});
}
Entity* Scene::AddEntity(	const char* name) noexcept {
	entityList.emplace_back(std::make_shared<Entity>(name));
	return entityList.back().get();
}
Entity* Scene::GetEntity(	const char* name) {
	Entity* entity{ nullptr };
	auto entityIt{ std::find_if(entityList.begin(), entityList.end(), [&](const std::shared_ptr<Entity>& entity) { return entity->GetName().c_str() == name; }) };
	if (entityIt != entityList.end()) { entity = entityIt->get(); }
	return entity;
}
void	Scene::RemoveEntity(const char* name) {
	drawableList.remove_if([&](const std::shared_ptr<Entity>& entity) { return entity->GetName().c_str() == name; });
	entityList.remove_if  ([&](const std::shared_ptr<Entity>& entity) { return entity->GetName().c_str() == name; });
}
std::list<std::shared_ptr<Entity>>* Scene::GetDrawable() noexcept {
	return &drawableList;
}
std::list<std::shared_ptr<Entity>>* Scene::GetEntities() noexcept {
	return &entityList;
}
