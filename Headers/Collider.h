#pragma once
#include "Component.h"
#include "CollisionShape.h"
class Collider : public Component {
private:
	static constexpr unsigned int ComponentID{ 20 };
protected:
	std::unique_ptr<CollisionShape> collisionShape;
	CollisionBox AABB;
public:
	Collider(Transform* = nullptr, const unsigned int& ID = ComponentID);
	virtual void CreateAABB() = 0;
	const CollisionBox& GetAABB() const noexcept;
	static bool BoxBoxCollision      (const CollisionBox&,	  const DirectX::SimpleMath::Vector3&, const CollisionBox&,	   const DirectX::SimpleMath::Vector3&) noexcept;
	static bool BoxSphereCollision   (const CollisionBox&,    const DirectX::SimpleMath::Vector3&, const CollisionSphere&, const DirectX::SimpleMath::Vector3&) noexcept;
	static bool SphereSphereCollision(const CollisionSphere&, const DirectX::SimpleMath::Vector3&, const CollisionSphere&, const DirectX::SimpleMath::Vector3&) noexcept;
	virtual bool Collision(Collider*) const = 0;
};
