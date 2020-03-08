#include "BoxCollider.h"
#include "Colliders.h"
BoxCollider::BoxCollider(Transform* position)
	: Collider::Collider(position, ComponentID) {
	collisionShape = std::make_unique<CollisionBox>();
}
std::unique_ptr<Component> BoxCollider::Clone() const noexcept {
	auto boxCollider{ std::make_unique<BoxCollider>(entityTransformPtr) };
	boxCollider->transform = transform;
	boxCollider->AABB = AABB;
	boxCollider->collisionShape = std::make_unique<CollisionBox>(GetBox());
	return boxCollider;
}
void BoxCollider::CreateAABB() {
	float size{ sqrt(pow(this->GetBox().width*2, 2) + pow(this->GetBox().height*2, 2) + pow(this->GetBox().depth*2, 2)) };
	AABB.width = size;
	AABB.height = size;
	AABB.depth = size;
}
const CollisionBox& BoxCollider::GetBox() const noexcept {
	return *dynamic_cast<CollisionBox*>(collisionShape.get());
}
bool BoxCollider::Collision(Collider* collider) const {
	bool collided{ false };
	switch (collider->GetID())
	{
	case 21:
	{
		const BoxCollider* colliderB{ dynamic_cast<const BoxCollider*>(collider) };
		collided = BoxBoxCollision(this->GetBox(), this->GetWorldTransform().position, colliderB->GetBox(), colliderB->GetWorldTransform().position);
		break;
	}
	case 22:
	{
		SphereCollider* colliderS{ dynamic_cast<SphereCollider*>(collider) };
		collided = BoxSphereCollision(this->GetBox(), this->GetWorldTransform().position, colliderS->GetSphere(), colliderS->GetWorldTransform().position);
		break;
	}
	case 23:
	{
		break;
	}
	case 24:
	{
		break;
	}
	case 25:
	{
		break;
	}
	default:
		throw("Invalid collider pointer - change to an actual exception later");
		break;
	}
	return collided;
}
