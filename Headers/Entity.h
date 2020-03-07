#pragma once
class Entity {
private:
	std::list<std::unique_ptr<Component>> componentList;
	Transform transform;
	std::string entityName;
public:
	Entity(const char* = nullptr);
	Entity(const Entity&);
	Entity(Entity&&);
	Transform& GetTransform() noexcept;
	void SetName(const char*) noexcept;
	std::string GetName() const noexcept;
	template<typename T> T*			AddComponent();
	template<typename T> void		RemoveComponent();
	template<typename T> T*			GetComponent();
	template<typename T> std::unique_ptr<Component>* CheckIfPresent();
	void Start(Microsoft::WRL::ComPtr<ID3D11Device>&, Microsoft::WRL::ComPtr<ID3D11DeviceContext>&);
	void Update();
	void Render();
	void Reset();
};