#pragma once
#include "Component.h"
#include "SpriteBatch.h"
#include "PrimitiveBatch.h"
#include "DDSTextureLoader.h"
class Sprite : public Component {
private:
	static constexpr unsigned int ComponentID{ 11 };
	std::wstring resourceName;
public:
	Sprite(Transform* = nullptr);
	virtual std::unique_ptr<Component> Clone() const noexcept override;
	void SetResource(const wchar_t* filename);
	const std::wstring& GetResourceName() const noexcept;
};
