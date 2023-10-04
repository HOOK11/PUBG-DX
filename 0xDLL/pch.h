#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

#include <io.h>
#include <list>
#include <string>
#include <math.h>
#include <corecrt_math_defines.h>

#include <vector>
#include <corecrt_math.h>
#include <unordered_map>
#include <corecrt_math.h>
#include <unordered_map>

#include "d3d11.h"

#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include <imgui_internal.h>

extern ULONG NtReadVirtualMemoryIndex,
NtUserSendInputIndex,
NtUserGetAsyncKeyStateIndex,
ZwQueryVirtualMemoryIndex,
NtUserCreateFile;

EXTERN_C int FuncIndex;

EXTERN_C DWORD Asm_SysCall(...);