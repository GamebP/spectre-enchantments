// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>

#include "user_interface.h"

// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;

    static const ImWchar ranges[] =
    {
        0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
        0x2DE0, 0x2DFF, // Cyrillic Extended-A
        0xA640, 0xA69F, // Cyrillic Extended-B
        0xE000, 0xE226, // icons
        0,
    };

    font_config.GlyphRanges = ranges;

    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 14.0f, &font_config, ranges);

    // Our state
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

        ImGui::SetNextWindowSize(ImVec2(520, 395));

        static int selected = 0;
        static int sub_selected = 0;

        static bool bullying = false;
        static bool bullythosemfs = false;
        static bool stopbullythemyoushitters = false;
        static bool stop = false;
        static bool niggas = false;
        static bool hihihi = false;
        static bool bro = false;
        static int sliderinc = 0;
        static int combo = 0;
        const char* combo_items[4] = { "head", "chest", "legs", "feet" };
        static float color[4] = { 1.f, 1.f, 1.f, 1.f };

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            ImGui::Begin("pandora-gui", nullptr, ImGuiWindowFlags_NoDecoration);
            {
                auto draw = ImGui::GetWindowDrawList();
                ImVec2 pos = ImGui::GetWindowPos();
                ImVec2 size = ImGui::GetWindowSize();

                draw->AddRectFilled(pos, ImVec2(pos.x + 55, pos.y + size.y), ImColor(20, 20, 20, 255)); // left rect
                draw->AddRectFilled(ImVec2(pos.x + 55, pos.y), ImVec2(pos.x + size.x, pos.y + 35), ImColor(20, 20, 20, 255)); // upper rect

                draw->AddLine(ImVec2(pos.x + 55, pos.y + 35), ImVec2(pos.x + size.x, pos.y + 35), ImColor(255, 255, 255, 15)); // upper line
                draw->AddLine(ImVec2(pos.x + 55, pos.y), ImVec2(pos.x + 55, pos.y + size.y), ImColor(255, 255, 255, 15)); // left line

                ImGui::SetCursorPos(ImVec2(-1, 11));
                ImGui::BeginGroup();
                if (custom_interface::tab("A", 0 == selected)) {
                    selected = 0; sub_selected = 0;
                }
                if (custom_interface::tab("B", 1 == selected)) {
                    selected = 1; sub_selected = 2;
                }
                if (custom_interface::tab("C", 2 == selected)) {
                    selected = 2;
                }
                if (custom_interface::tab("D", 3 == selected)) {
                    selected = 3;
                }
                if (custom_interface::tab("E", 4 == selected)) {
                    selected = 4;
                }
                ImGui::EndGroup();

                if (selected == 0) {
                    ImGui::BeginGroup();
                    ImGui::SetCursorPos(ImVec2(65, 14));
                    if (custom_interface::subtab("Aimbot", 0 == sub_selected)) {
                        sub_selected = 0;
                    }
                    ImGui::EndGroup();

                    
                    if (sub_selected == 0) {
                        ImGui::SetCursorPos(ImVec2(65, 44));
                        ImGui::BeginChild("Aim Assistance", ImVec2(219, 342));
                        {
                            ImGui::Checkbox("Lock Aimbot", &stop);
                            ImGui::Checkbox("Silent Aim", &niggas);
                            ImGui::Checkbox("Fov", &hihihi);
                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(291, 44));
                        ImGui::BeginChild("Triggerbot", ImVec2(219, 342));
                        {
                            ImGui::Checkbox("Triggerbot", &bro);
                        }
                        ImGui::EndChild();
                    }
                }

                if (selected == 1) {
                    ImGui::BeginGroup();
                    ImGui::SetCursorPos(ImVec2(65, 14));
                    if (custom_interface::subtab("Players", 2 == sub_selected)) {
                        sub_selected = 2;
                    }
                    ImGui::SameLine();
                    if (custom_interface::subtab("World", 3 == sub_selected)) {
                        sub_selected = 3;
                    }
                    ImGui::EndGroup();

                    static bool nigggers = false;
                    static bool espiguess = false;
                    if (sub_selected == 2) {
                        ImGui::SetCursorPos(ImVec2(65, 44));
                        ImGui::BeginChild("Visuals", ImVec2(219, 342));
                        {
                            ImGui::Checkbox("Enable 2D Box", &espiguess);
                            ImGui::Checkbox("Visible Only", &stopbullythemyoushitters);
                            ImGui::SliderInt("Chance prefering baim", &sliderinc, 0, 100, "%d%%", ImGuiSliderFlags_NoInput);
                            ImGui::Combo("Hitboxes", &combo, combo_items, 4);
                            ImGui::Button("cl_fullupdate callback", ImVec2(199, 22));
                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(291, 44));
                        ImGui::BeginChild("Preview", ImVec2(219, 342), ImGuiWindowFlags_NoScrollbar);
                        {
                            if (espiguess == true) {
                                ImGui::SetCursorPos(ImVec2(57, 65));
                                ImVec2 pos1 = ImGui::GetCursorScreenPos();
                                draw->AddRect(ImVec2(pos1.x, pos1.y), ImVec2(pos1.x + 100, pos1.y + 175), ImColor(255, 255, 255), 5.0f, 15, 1.f);
                            }
                        }
                        ImGui::EndChild();
                    }
                    else if (sub_selected == 3) {
                        ImGui::SetCursorPos(ImVec2(65, 44));
                        ImGui::BeginChild("Main", ImVec2(219, 44));
                        {
                            ImGui::Checkbox("Night Mode", &bullythosemfs);
                            ImGui::Checkbox("Third Person", &nigggers);
                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(65, 95));
                        ImGui::BeginChild("Actions", ImVec2(219, 291));
                        {

                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(291, 44));
                        ImGui::BeginChild("Luas", ImVec2(219, 283));
                        {

                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2(291, 334));
                        ImGui::BeginChild("utilities", ImVec2(219, 52));
                        {
                            ImGui::Button("Force skins update", ImVec2(199, 22));
                        }
                        ImGui::EndChild();
                    }
                }
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
