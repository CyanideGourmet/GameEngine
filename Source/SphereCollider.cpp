#include "SphereCollider.h"
#include "Colliders.h"
SphereCollider::SphereCollider(Transform* position)
	: Collider::Collider(position, ComponentID) {
	collisionShape = std::make_unique<CollisionSphere>();
}
std::unique_ptr<Component> SphereCollider::Clone() const noexcept {
	auto sphereCollider{ std::make_unique<SphereCollider>(entityTransformPtr) };
	sphereCollider->transform = transform;
	sphereCollider->AABB = AABB;
	sphereCollider->collisionShape = std::make_unique<CollisionSphere>(GetSphere());
	return sphereCollider;
}
void SphereCollider::CreateAABB() {
	AABB = CollisionBox{};
	AABB.width  = GetSphere().radius;
	AABB.height = GetSphere().radius;
	AABB.depth  = GetSphere().radius;
}
const CollisionSphere& SphereCollider::GetSphere() const noexcept {
	return *dynamic_cast<CollisionSphere*>(collisionShape.get());
}
bool SphereCollider::Collision(Collider* collider) const {
	bool collided{ false };
	switch (collider->GetID())
	{
	case 21:
	{
		BoxCollider* colliderB{ dynamic_cast<BoxCollider*>(collider) };
		collided = BoxSphereCollision(colliderB->GetBox(), colliderB->GetWorldTransform().position, this->GetSphere(), this->GetWorldTransform().position);
		break;
	}
	case 22:
	{
		const SphereCollider* colliderS{ dynamic_cast<const SphereCollider*>(collider) };
		collided = SphereSphereCollision(colliderS->GetSphere(), colliderS->GetWorldTransform().position, this->GetSphere(), this->GetWorldTransform().position);
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