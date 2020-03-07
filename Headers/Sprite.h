#pragma once
#include "Component.h"
#include "SpriteBatch.h"
#include "DDSTextureLoader.h"
class Sprite : public Component {
private:
	static constexpr unsigned int ComponentID{ 11 };
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> textureView;
	std::unique_ptr<DirectX::SpriteBatch>			 spriteBatch;
	DirectX::SimpleMath::Vector3					 origin;
	std::wstring									 spriteFilename;
public:
	Sprite(Transform* = nullptr);
	virtual std::unique_ptr<Component> clone() const noexcept override;
	void SetTexture(const wchar_t* filename);
	virtual void Start(Microsoft::WRL::ComPtr<ID3D11Device>&, Microsoft::WRL::ComPtr<ID3D11DeviceContext>&) override;
	virtual void Render() override;
	virtual void Reset() override;
};
