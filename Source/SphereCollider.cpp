#include "SphereCollider.h"
#include "Colliders.h"
SphereCollider::SphereCollider(Transform* position)
	: Collider::Collider(position, ComponentID) {}
std::unique_ptr<Component> SphereCollider::clone() const noexcept {
	auto sphereCollider{ std::make_unique<SphereCollider>(entityTransformPtr) };
	sphereCollider->transform = transform;
	sphereCollider->AABB = AABB;
	sphereCollider->collisionSphere = collisionSphere;
	return sphereCollider;
}
void SphereCollider::CreateAABB() {
	AABB = CollisionBox{ collisionSphere.radius, collisionSphere.radius, collisionSphere.radius };
}
CollisionSphere& SphereCollider::GetSphere() noexcept {
	return collisionSphere;
}
bool SphereCollider::Collision(Collider* collider) const {
	bool collided{ false };
	switch (collider->GetID())
	{
	case 21:
	{
		BoxCollider* colliderB{ dynamic_cast<BoxCollider*>(collider) };
		collided = BoxSphereCollision(colliderB->GetBox(), colliderB->GetWorldTransform().position, this->collisionSphere, this->GetWorldTransform().position);
		break;
	}
	case 22:
	{
		const SphereCollider* colliderS{ dynamic_cast<const SphereCollider*>(collider) };
		collided = SphereSphereCollision(colliderS->collisionSphere, colliderS->GetWorldTransform().position, this->collisionSphere, this->GetWorldTransform().position);
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