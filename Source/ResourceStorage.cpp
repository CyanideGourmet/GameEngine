#include <wrl/client.h>
#include <d3d11.h>
#include "SimpleMath.h"
#include "DDSTextureLoader.h"
#include "ResourceStorage.h"

ResourceStorage::ResourceStorage() {}
void ResourceStorage::LoadSprite(const wstring& fileName, const wstring& resourceName, ID3D11Device* device, ID3D11DeviceContext* deviceContext) {
	spriteMap.emplace(resourceName, SpriteRenderData{});
	
	ComPtr<ID3D11Resource> resource{};
	DirectX::CreateDDSTextureFromFile(device,
									  fileName.c_str(),
									  resource.GetAddressOf(),
									  spriteMap.at(resourceName).resourceView.ReleaseAndGetAddressOf());

	ComPtr<ID3D11Texture2D> texture{};
	resource.As(&texture);

	CD3D11_TEXTURE2D_DESC textureDesc{};
	texture->GetDesc(&textureDesc);

	spriteMap.at(resourceName).origin.x = textureDesc.Width / 2.f;
	spriteMap.at(resourceName).origin.y = textureDesc.Height / 2.f;
}
SpriteRenderData& ResourceStorage::GetSprite(const wstring& resourceName) {
	return spriteMap.at(resourceName);
}
