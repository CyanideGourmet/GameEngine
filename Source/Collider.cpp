#include "Collider.h"
#include <array>
#include <cmath>
Collider::Collider(Transform* transform, const unsigned int& ID)
	: Component::Component(transform, ID) {}
const CollisionBox& Collider::GetAABB() const noexcept {
	return AABB;
}
bool Collider::BoxBoxCollision		 (const CollisionBox& box1, const DirectX::SimpleMath::Vector3& pos1, 
									  const CollisionBox& box2, const DirectX::SimpleMath::Vector3& pos2) noexcept {
	std::array<bool, 3> axesIntercepting{ false, false, false };
	axesIntercepting.at(0) = pos1.x - box1.width  < pos2.x + box2.width  && pos2.x - box2.width  < pos1.x + box1.width;
	axesIntercepting.at(1) = pos1.y - box1.height < pos2.y + box2.height && pos2.y - box2.height < pos1.y + box1.height;
	axesIntercepting.at(2) = pos1.z - box1.depth  < pos2.z + box2.depth  && pos2.z - box2.depth  < pos1.z + box1.depth;
	return axesIntercepting.at(0) && axesIntercepting.at(1) && axesIntercepting.at(2);
}
bool Collider::BoxSphereCollision	 (const CollisionBox& box,		 const DirectX::SimpleMath::Vector3& posBox,
									  const CollisionSphere& sphere, const DirectX::SimpleMath::Vector3& posSphere) noexcept {
	auto distance{ pow((sphere.radius), 2) };
	auto Corner1{ posBox - DirectX::SimpleMath::Vector3{box.width, box.height, box.depth} };
	auto Corner2{ posBox + DirectX::SimpleMath::Vector3{box.width, box.height, box.depth} };
	if		(posSphere.x < Corner1.x) { distance -= pow((posSphere.x - Corner1.x), 2); }
	else if (posSphere.x > Corner2.x) { distance -= pow((posSphere.x - Corner2.x), 2); }
	if		(posSphere.y < Corner1.y) { distance -= pow((posSphere.y - Corner1.y), 2); }
	else if (posSphere.y > Corner2.y) { distance -= pow((posSphere.y - Corner2.y), 2); }
	if		(posSphere.z < Corner1.z) { distance -= pow((posSphere.z - Corner1.z), 2); }
	else if (posSphere.z > Corner2.z) { distance -= pow((posSphere.z - Corner2.z), 2); }
	return distance > 0;
}
bool Collider::SphereSphereCollision (const CollisionSphere& sphere1, const DirectX::SimpleMath::Vector3& pos1,
									  const CollisionSphere& sphere2, const DirectX::SimpleMath::Vector3& pos2) noexcept {
	auto distance { pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2) + pow((pos1.z - pos2.z), 2) };
	auto radiusSum{ pow((sphere1.radius + sphere2.radius), 2) };
	return distance < radiusSum;
}