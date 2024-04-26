#pragma once
#include <functional>
#include <thread>

#include <dwmapi.h>
#pragma comment (lib, "dwmapi.lib")

#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "xor.hpp"


class D3DOverlay
{
private:
	static std::function<void(int, int, bool)> m_UserRender;
	static HWND m_Window;
	static bool m_MenuOpen;
	static int m_WindowWidth;
	static int m_WindowHeight;

	static LPDIRECT3D9 m_D3D;
	static LPDIRECT3DDEVICE9 m_D3Device;
	static D3DPRESENT_PARAMETERS m_D3Parameters;

	static bool CreateOverlay();
	static bool CreateDeviceD3D();

public:
	static bool Init();
	static bool Update();
	static void SetUserRender(const std::function<void(int, int, bool)> UserRender);
	static void CleanupOverlay();

};

