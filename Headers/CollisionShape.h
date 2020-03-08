#pragma once
struct CollisionShape {
	const unsigned int ID;
	CollisionShape(const unsigned int& ID) : ID{ ID } {}
	virtual ~CollisionShape() = 0 {}
};
struct CollisionBox : CollisionShape {
	static constexpr unsigned int ID{ 1 };

	float width;
	float height;
	float depth;

	CollisionBox() : CollisionShape(ID), width{ 0.f }, height{ 0.f }, depth{ 0.f } {}
	CollisionBox& operator=(const CollisionBox& source) { width = source.width; height = source.height; depth = source.depth; return *this; }
};
struct CollisionSphere : CollisionShape {
	static constexpr unsigned int ID{ 2 };

	float radius;

	CollisionSphere() : CollisionShape(ID), radius{ 0.f } {}
	CollisionSphere& operator=(const CollisionSphere& source) { radius = source.radius; return *this; }
};