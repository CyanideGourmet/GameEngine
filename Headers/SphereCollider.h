#pragma once
#include "Collider.h"
class SphereCollider : public Collider {
private:
	static constexpr unsigned int ComponentID{ 22 };
public:
	SphereCollider(Transform* position = nullptr);
	virtual std::unique_ptr<Component> Clone() const noexcept override;
	virtual void CreateAABB() override;
	const CollisionSphere& GetSphere() const noexcept;
	virtual bool Collision(Collider*) const override;
};

