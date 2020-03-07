#include "BoxCollider.h"
#include "Colliders.h"
BoxCollider::BoxCollider(Transform* position)
	: Collider::Collider(position, ComponentID) {}
std::unique_ptr<Component> BoxCollider::clone() const noexcept {
	auto boxCollider{ std::make_unique<BoxCollider>(entityTransformPtr) };
	boxCollider->transform = transform;
	boxCollider->AABB = AABB;
	boxCollider->collisionBox = collisionBox;
	return boxCollider;
}
void BoxCollider::CreateAABB() {
	float size{ sqrt(pow(collisionBox.width*2, 2) + pow(collisionBox.height*2, 2) + pow(collisionBox.depth*2, 2)) };
	AABB.width = size;
	AABB.height = size;
	AABB.depth = size;
}
CollisionBox& BoxCollider::GetBox() noexcept {
	return collisionBox;
}
bool BoxCollider::Collision(Collider* collider) const {
	bool collided{ false };
	switch (collider->GetID())
	{
	case 21:
	{
		const BoxCollider* colliderB{ dynamic_cast<const BoxCollider*>(collider) };
		collided = BoxBoxCollision(this->collisionBox, this->GetWorldTransform().position, colliderB->collisionBox, colliderB->GetWorldTransform().position);
		break;
	}
	case 22:
	{
		SphereCollider* colliderS{ dynamic_cast<SphereCollider*>(collider) };
		collided = BoxSphereCollision(this->collisionBox, this->GetWorldTransform().position, colliderS->GetSphere(), colliderS->GetWorldTransform().position);
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
