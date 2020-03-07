#include "Event.h"
#include "DeviceResources.h"
#include "StepTimer.h"
#include "Graphics.h"

Graphics::Graphics() {
	deviceResources = std::make_unique<DX::DeviceResources>();
	deviceResources->RegisterDeviceNotify(this);
}
ID3D11Device* Graphics::GetDevice() {
	return deviceResources->GetD3DDevice();
}
ID3D11DeviceContext* Graphics::GetDeviceContext() {
	return deviceResources->GetD3DDeviceContext();
}

void Graphics::Start(HWND& window, const int& width, const int& height) {
	deviceResources->SetWindow(window, width, height);
	deviceResources->CreateDeviceResources();
	deviceResources->CreateWindowSizeDependentResources();

	CreateResources();
	CreateWindowSizeResources();
}
void Graphics::Render(DX::StepTimer const& timer) {
	if (timer.GetFrameCount() != 0) {
		Clear();
		deviceResources->PIXBeginEvent(L"Render");
		renderEvent.Invoke();
		deviceResources->PIXEndEvent();
		deviceResources->Present();
	}
}
void Graphics::Clear() {
	deviceResources->PIXBeginEvent(L"Clear");

	auto context     { deviceResources->GetD3DDeviceContext() };
	auto renderTarget{ deviceResources->GetRenderTargetView() };
	auto depthStencil{ deviceResources->GetDepthStencilView() };
	
	context->ClearRenderTargetView(renderTarget, DirectX::Colors::Gray);
	context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);
	context->OMSetRenderTargets(1, &renderTarget, depthStencil);

	auto viewport{ deviceResources->GetScreenViewport() };
	context->RSSetViewports(1, &viewport);

	deviceResources->PIXEndEvent();
}

void Graphics::AddEntity(task entityRender) {
	renderEvent.AddListener(entityRender);
}
void Graphics::RemoveEntity(task entityRender) {
	renderEvent.RemoveListener(entityRender);
}

void Graphics::CreateResources() {}
void Graphics::CreateWindowSizeResources() {}
void Graphics::OnDeviceLost() {}
void Graphics::OnDeviceRestored() {
	CreateResources();
	CreateWindowSizeResources();
}