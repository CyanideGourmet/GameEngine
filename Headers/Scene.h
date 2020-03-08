#pragma once
class Scene {
private:
	std::list<Entity> entityList;
	std::string sceneName;
public:
	Scene(const char* = nullptr);
	Scene(const Scene&);
	Entity* AddEntity(const char* = nullptr) noexcept;
	Entity* GetEntity(const char*);
	void RemoveEntity(const char*);
	void Start(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	void Update();
	void Render();
	void Reset();
};