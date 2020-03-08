#pragma once
#include <map>
using std::map;
using std::wstring;
using Microsoft::WRL::ComPtr;

struct SpriteRenderData {
	ComPtr<ID3D11ShaderResourceView> resourceView;
	DirectX::SimpleMath::Vector2 origin;
};
class ResourceStorage {
private:
	map<wstring, SpriteRenderData> spriteMap;
public:
	ResourceStorage();
	ResourceStorage(const ResourceStorage&) = delete;
	void			  LoadSprite(const wstring&, const wstring&, ID3D11Device*, ID3D11DeviceContext*);
	SpriteRenderData& GetSprite (const wstring&);
};