#pragma once
#include "Collider.h"
class SphereCollider : public Collider {
private:
	static constexpr unsigned int ComponentID{ 22 };
	CollisionSphere				  collisionSphere;
public:
	SphereCollider(Transform* position = nullptr);
	virtual std::unique_ptr<Component> clone() const noexcept override;
	virtual void CreateAABB() override;
	CollisionSphere& GetSphere() noexcept;
	virtual bool Collision(Collider*) const override;
};

