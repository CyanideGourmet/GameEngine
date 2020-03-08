#pragma once
#include <wrl/client.h>
#include <d3d11.h>
#include "SimpleMath.h"
struct Transform {
	DirectX::SimpleMath::Vector3 position;
	DirectX::SimpleMath::Vector3 rotation;
	DirectX::SimpleMath::Vector3 scale;
	Transform operator+(const Transform& rhs) const {
		return Transform{ position + rhs.position, rotation + rhs.rotation, scale * rhs.scale };
	}
};
class Component abstract {
private:
	const unsigned int ComponentID;
protected:
	Transform* entityTransformPtr;
	Transform  transform;
public:
	Component(Transform* = nullptr, const unsigned int& ID = 0);
	Component(const Component&);
	Component(Component&&) noexcept;
	virtual std::unique_ptr<Component> clone() const noexcept;
	virtual ~Component() = 0 {}
	const unsigned int& GetID()				const noexcept;
	Transform&			GetTransform()			  noexcept;
	Transform			GetWorldTransform() const noexcept;
	virtual void Start(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	virtual void Update();
	virtual void Render();
	virtual void Reset();
};