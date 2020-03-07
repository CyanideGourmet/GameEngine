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
	void Start(Microsoft::WRL::ComPtr<ID3D11Device>&, Microsoft::WRL::ComPtr<ID3D11DeviceContext>&);
	void Update();
	void Render();
	void Reset();
};