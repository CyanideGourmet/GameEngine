#pragma once
class Graphics final : DX::IDeviceNotify {
private:
	typedef void (*task)(void* data);
	std::unique_ptr<DX::DeviceResources> deviceResources;

	Scene* scenePtr;
	Event renderEvent;

	void CreateResources();
	void CreateWindowSizeResources();
public:
	Graphics();
	Graphics(const Graphics&) = delete;
	const Graphics& operator+(const Graphics&) noexcept = delete;

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	virtual void OnDeviceLost() override;
	virtual void OnDeviceRestored() override;
	
	void Start(HWND& window, const int& width, const int& height);
	void Render(DX::StepTimer const& timer);
	void Clear();

	void ChangeScene(Scene*);
};

