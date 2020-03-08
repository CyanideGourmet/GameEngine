#include "Sprite.h"

Sprite::Sprite(Transform* transform)
	: Component::Component(transform, ComponentID) {}
std::unique_ptr<Component> Sprite::clone() const noexcept {
	auto sprite{ std::make_unique<Sprite>(entityTransformPtr) };
	sprite->transform = transform;
	sprite->origin = origin;
	sprite->spriteFilename = spriteFilename;
	return sprite;
}
void Sprite::SetTexture(const wchar_t* filename) {
	spriteFilename = filename;
}
void Sprite::Start(ID3D11Device* device, ID3D11DeviceContext* deviceContext) {
	if (spriteFilename == L"") { throw("No filename for sprite component - critical error"); }
	spriteBatch = std::make_unique<DirectX::SpriteBatch>(deviceContext);

	Microsoft::WRL::ComPtr<ID3D11Resource> resource{};
	DirectX::CreateDDSTextureFromFile(device, spriteFilename.c_str(), resource.GetAddressOf(), textureView.ReleaseAndGetAddressOf());	//Throw

	Microsoft::WRL::ComPtr<ID3D11Texture2D> texture{};
	resource.As(&texture);	//Throw

	CD3D11_TEXTURE2D_DESC textureDesc{};
	texture->GetDesc(&textureDesc);

	origin.x = textureDesc.Width / 2.f;
	origin.y = textureDesc.Height / 2.f;
	origin.z = 0.f;
}
void Sprite::Render() {
	spriteBatch->Begin();

	Transform drawTransform{ this->GetWorldTransform() };
	spriteBatch->Draw(textureView.Get(), drawTransform.position, nullptr, DirectX::Colors::White, drawTransform.rotation.z * 0.0174532f, origin, drawTransform.scale);

	spriteBatch->End();
}
void Sprite::Reset() {
	textureView.Reset();
	spriteBatch.reset();
}