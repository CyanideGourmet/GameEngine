#pragma once
#include "Drawable.h"
class Sprite : public Drawable {
private:
	static constexpr unsigned int ComponentID{ 1 };
public:
	Sprite(Transform* = nullptr);
	virtual std::unique_ptr<Component> Clone() const noexcept override;
};
