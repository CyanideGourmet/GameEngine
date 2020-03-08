#pragma once
#include "Component.h"
class Drawable : public Component {
private:
	static constexpr unsigned int ComponentID{ 0 };
protected:
	std::wstring resourceName;
public:
	Drawable(Transform* = nullptr, const unsigned int& ID = ComponentID);
	void SetResource(const wchar_t* filename);
	const std::wstring& GetResourceName() const noexcept;
};