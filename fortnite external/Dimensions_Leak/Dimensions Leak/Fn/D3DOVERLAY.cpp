#include "D3DOverlay.hpp"

#define Log(x) printf(_xor_("[Narcos::Render->Log] %s\n").c_str(), x)



bool D3DOverlay::Init()
{
	if (!CreateOverlay())
	{
		CleanupOverlay();
		Log(_xor_("Failed to create overlay").c_str());
		return false;
	}

	if (!CreateDeviceD3D())
	{
		CleanupOverlay();
		Log(_xor_("Failed creating D3D device").c_str());
		return false;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(m_Window);
	ImGui_ImplDX9_Init(m_D3Device);


	
	return true;
}

bool D3DOverlay::CreateOverlay()
{
	m_Window = FindWindowA(_xor_("action_refresh_window_class").c_str(), 0);
	if (!m_Window)
		return false;


	MARGINS Margin = { -1 };
	DwmExtendFrameIntoClientArea(m_Window, &Margin);


	if (!SetWindowPos(m_Window, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW))
		return false;
	SetLayeredWindowAttributes(m_Window, RGB(0, 0, 0), 0, LWA_COLORKEY);
	return true;
}

bool D3DOverlay::CreateDeviceD3D()
{
	if ((m_D3D = Direct3DCreate9(D3D_SDK_VERSION)) == 0)
		return false;

	ZeroMemory(&m_D3Parameters, sizeof(m_D3Parameters));
	m_D3Parameters.Windowed = true;
	m_D3Parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_D3Parameters.BackBufferFormat = D3DFMT_A8R8G8B8;
	m_D3Parameters.EnableAutoDepthStencil = true;
	m_D3Parameters.AutoDepthStencilFormat = D3DFMT_D16;
	m_D3Parameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	if (m_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_Window, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_D3Parameters, &m_D3Device) < 0)
		return false;

	return true;
}


void D3DOverlay::SetUserRender(const std::function<void(int, int, bool)> UserRender)
{
	m_UserRender = UserRender;
}

void D3DOverlay::CleanupOverlay()
{
	if (m_D3Device)
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::EndFrame();

		m_D3Device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 0, 0), 1.f, 0);

		if (m_D3Device->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			m_D3Device->EndScene();
		}

		m_D3Device->Present(NULL, NULL, NULL, NULL);

		ImGui_ImplDX9_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();

		m_D3Device->Release();
		m_D3Device = 0;
	}

	if (m_D3D)
	{
		m_D3D->Release();
		m_D3D = 0;
	}

	if (m_Window)
	{
		SetWindowLong(m_Window, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	}
}

