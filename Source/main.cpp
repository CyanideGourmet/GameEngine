#include "Event.h"
#include "DeviceResources.h"
#include "StepTimer.h"
#include "Graphics.h"
int CALLBACK WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd) {
    WNDCLASSEX wnd{ 0 };
    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.lpfnWndProc = DefWindowProc;
    wnd.hInstance = hInstance;
    wnd.lpszClassName = L"WindowClass";
    wnd.style = CS_OWNDC;
    wnd.hbrBackground = NULL;
    wnd.hCursor = NULL;
    wnd.hIcon = NULL;
    wnd.lpszMenuName = NULL;
    wnd.hIconSm = NULL;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    RegisterClassEx(&wnd);
    HWND hWnd{ CreateWindowEx(NULL, L"WindowClass", L"Window", WS_BORDER | WS_CAPTION | WS_SYSMENU, 100, 100, 1280, 720, NULL, NULL, hInstance, nullptr) };
    ShowWindow(hWnd, SW_SHOW);
    Graphics graphics{};
    graphics.Start(hWnd, 1280, 720);
    DX::StepTimer timer{};
    MSG message{};
    while (1) {
        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        else {
            timer.Tick([&]() {});
            graphics.Render(timer);
        }
    }
    return 0;
}