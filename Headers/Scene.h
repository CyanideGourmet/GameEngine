#pragma once
class Scene {
private:
	std::string sceneName;
	std::list<std::shared_ptr<Entity>> entityList;
	std::list<std::shared_ptr<Entity>> drawableList;
public:
	Scene(const char* = nullptr);
	void Initialize();
	Entity* AddEntity(const char*) noexcept;
	Entity* GetEntity(const char*);
	void RemoveEntity(const char*);
	std::list<std::shared_ptr<Entity>>* GetEntities() noexcept;
	std::list<std::shared_ptr<Entity>>* GetDrawable() noexcept;
};