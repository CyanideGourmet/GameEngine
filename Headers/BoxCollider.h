#pragma once
#include "Collider.h"
class BoxCollider : public Collider {
private:
	static constexpr unsigned int ComponentID{ 21 };
public:
	BoxCollider(Transform* position = nullptr);
	virtual std::unique_ptr<Component> Clone() const noexcept override;
	virtual void CreateAABB() override;
	const CollisionBox& GetBox() const noexcept;
	virtual bool Collision(Collider*) const override;
};