// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include "imgui_shadow.h"
#include "bytes.h"
#include <math.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

IDirect3DTexture9* legit_image = nullptr;
IDirect3DTexture9* rage_image = nullptr;
IDirect3DTexture9* visuals_image = nullptr;
IDirect3DTexture9* players_image = nullptr;
IDirect3DTexture9* misc_image = nullptr;
IDirect3DTexture9* settings_image = nullptr;

ImFont* font = nullptr;
// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int accent_color[4] = {130, 34, 35, 255};
int selection_count = 0;
int legit_group_count = 0;

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Dear ImGui DirectX9 Example"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    font = io.Fonts->AddFontFromMemoryTTF(fonto, sizeof(fonto), 14.f);
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);


    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.00f);

    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGuiStyle& style = ImGui::GetStyle();


        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {

            if (legit_image == nullptr)D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice
                , &legit, sizeof(legit),
                20, 20, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &legit_image);
            if (visuals_image == nullptr)D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice
                , &visuals, sizeof(visuals),
                20, 20, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &visuals_image);
            if (misc_image == nullptr)D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice
                , &misc, sizeof(misc),
                20, 20, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &misc_image);
            if (settings_image == nullptr)D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice
                , &settings, sizeof(settings),
                20, 20, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &settings_image);

            ImGui::SetNextWindowSize(ImVec2(100, 100));
            ImGui::SetNextWindowSize(ImVec2(680, 470));
            ImGui::Begin("����", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
            {
                const ImVec2 pos = ImGui::GetWindowPos();
                ImDrawList* draw = ImGui::GetWindowDrawList();

                style.ScrollbarSize = 3.f;
                style.ScrollbarRounding = 12.f;
                style.WindowBorderSize = 0.f;
                style.WindowPadding = ImVec2(0, 0);

                draw->AddRectFilled(pos + ImVec2(71, 56), pos + ImVec2(680, 470), ImColor(11, 11, 11, 255), 2.f, ImDrawFlags_RoundCornersBottomRight);

                draw->AddRectFilled(pos, pos + ImVec2(70, 470), ImColor(14, 14, 14, 255), 2.f, ImDrawFlags_RoundCornersLeft);
                draw->AddLine(pos + ImVec2(70, 0), pos + ImVec2(70, 470), ImColor(24, 24, 24, 255));

                draw->AddRectFilled(pos + ImVec2(71, 0), pos + ImVec2(680, 55), ImColor(14, 14, 14, 255), 2.f, ImDrawFlags_RoundCornersTopRight);
                draw->AddLine(pos + ImVec2(71, 55), pos + ImVec2(680, 55), ImColor(24, 24, 24, 255));

                draw->AddLine(pos + ImVec2(20, 176), pos + ImVec2(50, 176), ImColor(255, 255, 255, 15), 1.f);


                draw->AddCircleFilled(pos + ImVec2(35, 433), 16.f, ImColor(0, 0, 0, 50), 60.f);
                draw->AddCircle(pos + ImVec2(35, 433), 17.f, ImColor(255, 255, 255, 15), 60.f);

                ImGui::AddShadow(ImVec2(0, 0), ImVec2(680, 470), 20, 4, 7, 2, 20, ImColor(0, 0, 0));

                ImGui::SetCursorPos(ImVec2(10, 63));
                ImGui::BeginGroup();
                if (ImGui::selection("legit", legit_image, 0 == selection_count))
                    selection_count = 0;
                if (ImGui::selection("visuals", visuals_image, 2 == selection_count))
                    selection_count = 2;
                if (ImGui::selection("settings", settings_image, 5 == selection_count))
                    selection_count = 5;
                ImGui::EndGroup();

                ImGui::SetCursorPos(ImVec2(85, 15));
                ImGui::BeginGroup();
                if (selection_count == 0)
                {
                    if (ImGui::group("Legitbot", 0 == legit_group_count))
                        legit_group_count = 0;
                    ImGui::SameLine();
                    if (ImGui::group("Triggerbot", 1 == legit_group_count))
                        legit_group_count = 1;

                    if (legit_group_count == 0)
                    {
                        ImGui::SetCursorPos(ImVec2(85, 70));
                        ImGui::BeginChild("Aim Assistance", ImVec2(282, 386));

                        static bool checkbox_on = true;
                        ImGui::Checkbox("Checkbox ON", &checkbox_on);

                        static bool checkbox_off = false;
                        ImGui::Checkbox("Checkbox OFF", &checkbox_off);

                        static int slider_int = 0;
                        ImGui::SliderInt("Slider INT", &slider_int, 0, 100);

                        static float slider_float = 0.f;
                        ImGui::SliderFloat("Slider FLOAT", &slider_float, 0.f, 100.f);

                        ImGui::Button("Button", ImVec2(262, 26));

                        static int items_count = 0;
                        const char* items[3] = { "One", "Two", "Three" };
                        ImGui::Combo("Combo", &items_count, items, 3);

                        static float color[4] = { 130.f / 255.f, 34.f / 255.f, 35.f / 255.f, 1.f };
                        if (ImGui::ColorEdit4("Accent Color", color))
                        {
                            accent_color[0] = color[0] * 255.f;
                            accent_color[1] = color[1] * 255.f;
                            accent_color[2] = color[2] * 255.f;

                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(382, 70));
                        ImGui::BeginChild("Aim Settings", ImVec2(282, 238));
                        static bool ��������[50];

                        for (int i = 1; i <= 50; i++)
                            ImGui::Checkbox(std::to_string(i).c_str(), &��������[i]);
                        ImGui::EndChild();
                    }

                }
                ImGui::EndGroup();

            }
            ImGui::End();

        }


        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*clear_color.w*255.0f), (int)(clear_color.y*clear_color.w*255.0f), (int)(clear_color.z*clear_color.w*255.0f), (int)(clear_color.w*255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

// ��� ��� ������, ��� �������
