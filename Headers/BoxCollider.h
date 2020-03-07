#pragma once
#include "Collider.h"
class BoxCollider : public Collider {
private:
	static constexpr unsigned int ComponentID{ 21 };
	CollisionBox				  collisionBox;
public:
	BoxCollider(Transform* position = nullptr);
	virtual std::unique_ptr<Component> clone() const noexcept override;
	virtual void CreateAABB() override;
	CollisionBox& GetBox() noexcept;
	virtual bool Collision(Collider*) const override;
};