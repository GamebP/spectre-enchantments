#include <iostream>
#include "SFML/Graphics.hpp"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>

#include <auth.hpp>
#include "win_utils.h"
#include "Controller.h"

#include "d3d9_x.h"
#include "xor.hpp"
#include <dwmapi.h>
#include <vector>
#include "settings.h"
#include "Icons.h"
#include "Font.h"
#include "SecondFont.h"
#include "LightFont.h"
#include "memoryq.h"
#define getfnnamefromfname		0x3281
//static void xCreateWindow();
//static void xInitD3d();
//static void xMainLoop();
//static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
//extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static std::string GetNameFromFName(int key)
{
    uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
    uint16_t NameOffset = (uint16_t)key;



 

    char buff[1024];
    char* v2 = buff; // rbx
    int v4; // edi
    unsigned int v5; // eax
    unsigned int v6; // r8d
    __int64 result; // rax
    unsigned int v8; // kr00_4
    int v9; // ecx

    v8 = v5;
    result = 1041204193 * v5;
    v9 = 0;

    if (v4)
    {
        do
        {
            result = v9 + v8 % 0x21;
            ++v9;
            v6 += result;
            *v2++ ^= v6;
        } while (v9 < v4);
    }

    buff[v4] = '\0';
    return std::string(buff);
}