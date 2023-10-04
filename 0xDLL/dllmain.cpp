// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "drive.h"
#include "screenshot.h"
#include <shlobj_core.h>
#include "draw.h"
#include "图标.h"
#include "base.h"
#include "engine.h"
#include "decrypt.h"
#include "menu.h"
#include "game.h"
#include <stdint.h>
#include <stdio.h>
#include <process.h>
#include "../YiYou/w3c_u.h"


void sssss();
ULONG FirstTime = 1;
ULONG_PTR GameOverlayRenderer64 = NULL;
ULONG NtReadVirtualMemoryIndex = 0;
LPCSTR GameData::卡密 = NULL;
int FuncIndex = 0;

DWORD GameData::pZwProtectVirtualMemory(HANDLE ProcessHandle, PVOID lpAddress, PSIZE_T dwSize, ULONG flNewProtect, PULONG lpflOldProtect)
{
	FuncIndex = GameData::NtUserCreateFile;
	return (DWORD)Asm_SysCall(ProcessHandle, lpAddress, dwSize, flNewProtect, lpflOldProtect);
}
DWORD GameData::pZwQueryVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, ULONG MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationLength, PSIZE_T ReturnLength)
{
	FuncIndex = GameData::ZwQueryVirtualMemoryIndex;
	return (DWORD)Asm_SysCall(ProcessHandle, BaseAddress, MemoryInformationClass, MemoryInformation, MemoryInformationLength, ReturnLength);
}
void MyMemoryCopy(void* desc, void* src, unsigned int size)
{
	unsigned char* pdesc = (unsigned char*)desc;
	unsigned char* psrc = (unsigned char*)src;
	while ((size--) != 0)*pdesc++ = *psrc++;
}
bool WriteProtectMemory(UINT64 ptr, PVOID buff, ULONG size) {
	if (IsBadReadPtr((LPVOID)ptr, size)) { return false; }
	DWORD oldProtect = 0;
	SIZE_T Sz = size;
	PVOID Address = (PVOID)ptr;
	GameData::pZwProtectVirtualMemory((HANDLE)(ULONG_PTR)-1, &Address, &Sz, PAGE_EXECUTE_READWRITE, &oldProtect);
	Address = (PVOID)ptr;
	MyMemoryCopy(Address, buff, size);
	GameData::pZwProtectVirtualMemory((HANDLE)(ULONG_PTR)-1, &Address, &Sz, oldProtect, &oldProtect);
	return true;
}
DWORD GameData::NtUserSendInput(UINT cInputs, LPINPUT pInputs, int cbSize)
{
	FuncIndex = NtUserSendInputIndex;
	return (DWORD)Asm_SysCall(cInputs, pInputs, cbSize);
}
SHORT GameData::NtUserGetAsyncKeyState(DWORD key)
{
	FuncIndex = NtUserGetAsyncKeyStateIndex;
	return (SHORT)Asm_SysCall(key);
}
HRESULT WINAPI NewPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (FirstTime == 2) 
	{

		Draw::DX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		DrawMenu();
		EntityWhile();
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		
	}
	else if(FirstTime == 1)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&g_pd3dDevice)))
		{
			DXGI_SWAP_CHAIN_DESC pDesc;
			ID3D11Texture2D* pBackBuffer;

			if (SUCCEEDED(pSwapChain->GetDesc(&pDesc))
				&& SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer))
				&& SUCCEEDED(g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView))) 
			{
				g_pSwapChain = pSwapChain;
				g_pd3dDevice->GetImmediateContext(&g_pd3dDeviceContext);
				g_pHwnd = pDesc.OutputWindow;
				pBackBuffer->Release();
				g_OriginalWndProc = (WNDPROC)SetWindowLongPtr(g_pHwnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO();
				
				io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
				ImGui_ImplWin32_Init(g_pHwnd);
				ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
				char SystemPath[MAX_PATH] = { 0 };
				char FontPath[MAX_PATH] = { 0 };
				/*SHGetSpecialFolderPathA(NULL, SystemPath, CSIDL_FONTS, FALSE);*/
				sprintf_s(FontPath, "%s\\msyh.ttf", SystemPath);
				g_font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttf", 16.f, NULL, io.Fonts->GetGlyphRangesChineseFull());
				if (g_font == NULL) {
					sprintf_s(FontPath, "%s\\msyh.ttc", SystemPath);
					g_font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.f, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				g_font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\simhei.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

				//g_font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
				//IM_ASSERT(g_font != NULL);

				全局::InitEntityNameIDMap();
				InitPNG(g_pd3dDevice);
				FirstTime = 2;
			}
		}
	}
	return ((HRESULT(WINAPI*)(IDXGISwapChain*, UINT, UINT))(全局::绘制挂接))(pSwapChain, SyncInterval, Flags);
}
BYTE* MemoryData;
BOOL Flag = FALSE;
#define BLOCKMAXSIZE 409600//每次读取内存的最大大小
short Next[260];

typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation,
	MemoryWorkingSetList,
	MemorySectionName
}MEMORY_INFORMATION_CLASS;

WORD GetTzmArray(char* Tzm, WORD* TzmArray)
{
	int len = 0;
	WORD TzmLength = (WORD)strlen(Tzm) / 3 + 1;

	for (int i = 0; i < strlen(Tzm); )//将十六进制特征码转为十进制
	{
		char num[2];
		num[0] = Tzm[i++];
		num[1] = Tzm[i++];
		i++;
		if (num[0] != '?' && num[1] != '?')
		{
			int sum = 0;
			WORD a[2];
			for (int i = 0; i < 2; i++)
			{
				if (num[i] >= '0' && num[i] <= '9')
				{
					a[i] = num[i] - '0';
				}
				else if (num[i] >= 'a' && num[i] <= 'z')
				{
					a[i] = num[i] - 87;
				}
				else if (num[i] >= 'A' && num[i] <= 'Z')
				{
					a[i] = num[i] - 55;
				}

			}
			sum = a[0] * 16 + a[1];
			TzmArray[len++] = sum;
		}
		else
		{
			TzmArray[len++] = 256;
		}
	}
	return TzmLength;
}

void GetNext(short* next, WORD* Tzm, WORD TzmLength)
{
	for (int i = 0; i < 260; i++)
		next[i] = -1;
	for (int i = 0; i < TzmLength; i++)
		next[Tzm[i]] = i;
}
bool ReadMemoryS(UINT64 ptr, PVOID buff, size_t size)
{
	if (ptr < 0x1000000 - 0x8 || ptr > 0x7FFFFFF00000 + 0x8)
	{
		__stosb((PBYTE)buff, 0, size);
		return true;
	}
	else {
		if (IsBadReadPtr((PVOID)ptr, size)) {
			__stosb((PBYTE)buff, 0, size);
			return true;
		}
		else {
			__movsb((PBYTE)buff, (BYTE*)ptr, size);
			return true;
		}
	}
	return false;
}
//搜索一块内存
void SearchMemoryBlock(WORD* Tzm, WORD TzmLength, unsigned __int64 StartAddress, unsigned long size, std::vector<unsigned __int64>& ResultArray)
{
	if (!ReadMemoryS(StartAddress, MemoryData, size))
	{
		return;
	}

	for (unsigned long i = 0, j, k; i < size;)
	{
		j = i; k = 0;

		for (; k < TzmLength && j < size && (Tzm[k] == MemoryData[j] || Tzm[k] == 256); k++, j++);

		if (k == TzmLength)
		{
			ResultArray.push_back(StartAddress + i);
		}

		if ((i + TzmLength) >= size)
		{
			return;
		}

		int num = Next[MemoryData[i + TzmLength]];
		if (num == -1)
			i += (TzmLength - Next[256]);
		else
			i += (TzmLength - num);
	}
}

int SearchMemory(char* Tzm, unsigned __int64 StartAddress, unsigned __int64 EndAddress, int InitSize, vector<unsigned __int64>& ResultArray)
{
	int i = 0;
	unsigned long BlockSize;
	MEMORY_BASIC_INFORMATION mbi;

	WORD TzmLength = (WORD)strlen(Tzm) / 3 + 1;
	WORD* TzmArray = new WORD[TzmLength];

	GetTzmArray(Tzm, TzmArray);
	GetNext(Next, TzmArray, TzmLength);

	//初始化结果数组
	ResultArray.clear();
	ResultArray.reserve(InitSize);

	while (GameData::pZwQueryVirtualMemory((HANDLE)-1, (PVOID)StartAddress, MemoryBasicInformation, &mbi, sizeof(mbi), 0) >= 0)
	{
		if (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)
		{
			i = 0;
			BlockSize = (unsigned long)mbi.RegionSize;
			//搜索这块内存
			while (BlockSize >= BLOCKMAXSIZE)
			{
				SearchMemoryBlock(TzmArray, TzmLength, StartAddress + (BLOCKMAXSIZE * i), BLOCKMAXSIZE, ResultArray);
				BlockSize -= BLOCKMAXSIZE; i++;
			}
			SearchMemoryBlock(TzmArray, TzmLength, StartAddress + (BLOCKMAXSIZE * i), BlockSize, ResultArray);
		}
		StartAddress += mbi.RegionSize;
		if (EndAddress != 0 && StartAddress > EndAddress)
		{
			return (int)ResultArray.size();
		}
	}
	delete[] TzmArray;
	return (int)ResultArray.size();
}

bool WriteMemory(void* ptr, void* buff, size_t size)
{
	if (((__int64)ptr > 0x1000000 - 0x8) || ((__int64)ptr < 0x7FFFFFF00000 + 0x8)) {
		FuncIndex = NtReadVirtualMemoryIndex;
		SIZE_T ls;
		DWORD oldprotect;
		Asm_SysCall((HANDLE)-1, buff, ptr, size, &ls);
		return true;
	}
	return false;
}

void 反截图()
{
	Sleep(5000);
	std::vector<unsigned __int64> ResultArray;
	MemoryData = new BYTE[BLOCKMAXSIZE];
	ResultArray.clear();
	SearchMemory((char*)XorString("48 8B 44 24 ?? 48 8B 00 48 8B 54 24 ?? 48 8B 4C 24 ?? FF 50 38 48 83 C4 ?? C3"), 0, 0x30000000000, 10, ResultArray);
	while (true)
	{
		if (ResultArray.size() <= 0)
		{
			SearchMemory((char*)XorString("48 8B 44 24 ?? 48 8B 00 48 8B 54 24 ?? 48 8B 4C 24 ?? FF 50 38 48 83 C4 ?? C3"), 0, 0x30000000000, 10, ResultArray);
		}
		else
		{
			break;
		}
		Sleep(100);
	}

	for (std::vector<unsigned __int64>::iterator it = ResultArray.begin(); it != ResultArray.end(); it++)
	{
		BYTE call_rax[] = { 0x90,0x90,0x90 };
		BYTE Je[] = { 0x90,0x90 };

		WriteProtectMemory(*it - 0x64, &call_rax, sizeof(call_rax));
		WriteProtectMemory(*it - 0x9, &Je, sizeof(Je));
		BYTE Buffer;
		SIZE_T Ls;
		ReadProcessMemory((HANDLE)-1, PVOID((ULONG_PTR)(*it - 0x9)), &Buffer, 1, &Ls);

		if (Buffer == 0x90)
		{
			Flag = TRUE;
		}
	}


	/******************************gdi处理****************************************************/
	BYTE Hookgdi[] = { 0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90 };

	ResultArray.clear();

	SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 19"), 0, 0x30000000000, 10, ResultArray);

	while (true)
	{
		if (ResultArray.size() <= 0)
		{
			SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 19"), 0, 0x30000000000, 10, ResultArray);
		}
		else
		{
			Flag = TRUE;
			break;
		}
	}

	for (std::vector<unsigned __int64>::iterator it = ResultArray.begin(); it != ResultArray.end(); it++)
	{
		BYTE Buffer;

		SIZE_T Ls;

		WriteMemory((void*)(*it - 0x80), &Hookgdi, 8);

		ReadProcessMemory((HANDLE)-1, PVOID((ULONG_PTR)(*it - 0x80)), &Buffer, 1, &Ls);

		if (Buffer == 0x90)
		{
			Flag = TRUE;
		}
	}

	/******************************gdi处理****************************************************/
	BYTE Hookgdi1[] = { 0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90 };

	ResultArray.clear();

	SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 07"), 0, 0x30000000000, 10, ResultArray);

	while (true)
	{
		if (ResultArray.size() <= 0)
		{
			SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 07"), 0, 0x30000000000, 10, ResultArray);
		}
		else
		{
			Flag = TRUE;
			break;
		}
	}

	for (std::vector<unsigned __int64>::iterator it = ResultArray.begin(); it != ResultArray.end(); it++)
	{
		BYTE Buffer;

		SIZE_T Ls;

		WriteMemory((void*)(*it - 0x80), &Hookgdi, 8);

		ReadProcessMemory((HANDLE)-1, PVOID((ULONG_PTR)(*it - 0x80)), &Buffer, 1, &Ls);

		if (Buffer == 0x90)
		{
			Flag = TRUE;
		}
	}

	///******************************gdi处理****************************************************/
	//BYTE Hookgdi2[] = { 0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90 };

	//ResultArray.clear();

	//SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 12"), 0, 0x30000000000, 10, ResultArray);

	//while (true)
	//{
	//	if (ResultArray.size() <= 0)
	//	{
	//		SearchMemory((char*)XorString("48 89 45 C7 48 85 C0 75 12"), 0, 0x30000000000, 10, ResultArray);
	//	}
	//	else
	//	{
	//		Flag = TRUE;
	//		break;
	//	}
	//}

	//for (std::vector<unsigned __int64>::iterator it = ResultArray.begin(); it != ResultArray.end(); it++)
	//{
	//	BYTE Buffer;

	//	SIZE_T Ls;

	//	Mem::WriteMemory((void*)(*it - 0x80), &Hookgdi, 8);

	//	ReadProcessMemory((HANDLE)-1, PVOID((ULONG_PTR)(*it - 0x80)), &Buffer, 1, &Ls);

	//	if (Buffer == 0x90)
	//	{
	//		Flag = TRUE;
	//	}
	//}
	////用你驱动写 ？ 反截图最好用驱动去写 用驱动写要好点 我知道 1完事了 额 写的哪里自己替换一下就好 行吧 
	//

	ResultArray.clear();
	SearchMemory((char*)XorString("48 8D 44 24 ?? 4D 8B CF 4C 8B C6 48 89 44 24 ?? 48 8B D5 49 8B CE"), 0, 0x30000000000, 10, ResultArray);
	while (true)
	{
		if (ResultArray.size() <= 0)
		{
			SearchMemory((char*)XorString("48 8D 44 24 ?? 4D 8B CF 4C 8B C6 48 89 44 24 ?? 48 8B D5 49 8B CE"), 0, 0x30000000000, 10, ResultArray);
		}
		else
		{
			break;
		}
		Sleep(100);
	}

	for (std::vector<unsigned __int64>::iterator it = ResultArray.begin(); it != ResultArray.end(); it++)
	{
		BYTE call_Rdi[] = { 0x90,0x90,0x90 };
		WriteProtectMemory(*it + 0x16, &call_Rdi, sizeof(call_Rdi));
		BYTE Buffer;
		SIZE_T Ls;
		ReadProcessMemory((HANDLE)-1, PVOID((ULONG_PTR)(*it + 0x16)), &Buffer, 1, &Ls);

		if (Buffer == 0x90)
		{
			Flag = TRUE;
		}
	}


	ResultArray.clear();
	delete[]MemoryData;
	Menu::ScreenFlag = true;

}

int my_atoi(const char* str)
{
	assert(NULL != str);
	int ret = 0, sign = 1;
	for (; *str == ' ' || *str == '\t'; str++);
	if (*str == '-')sign = -1;
	if (*str == '-' || *str == '+')str++;
	while (isdigit(*str)) {
		ret = ret * 10 + *str - '0';
		str++;
	}
	return sign * ret;
}
BOOL YiYouCheck()
{

	W3Client w3;

	W3Client client;
	if (client.Connect("http://w.eydata.net"))
	{
		client.AddPostArgument(XorString("SingleCode"), "DWDD0A8E3B82B6170F598CAEEBBCC18C");
		client.AddPostArgument(XorString("&Ver"), XorString("1.0"));
		client.AddPostArgument(XorString("&Mac"), XorString(""));
		if (client.Request(XorString("/9686010BDE9AEA42"), W3Client::reqPost))
		{
			char buf[1024] = "\0";
			if (client.Response(reinterpret_cast<unsigned char*>(buf), 1024) > 0)
			{
				if (strlen(buf) == 32)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
			else
			{
				return FALSE;
			}
		}
		client.Close();
	}
	return FALSE;
}
static unsigned __stdcall  InitialEvent(LPVOID lpParameter)
{

	//反截图();

	_endthreadex(0);

	return 0;
}

VOID PassScreenShot()
{
	UCHAR Buffer[] = { 0x48, 0xB8, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x50, 0xC3 };

	PVOID AllocAddress = (PVOID)VirtualAlloc(NULL, sizeof(Buffer), MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	*((PULONG_PTR)(Buffer + 2)) = (ULONG_PTR)InitialEvent;

	RtlCopyMemory(AllocAddress, Buffer, sizeof(Buffer));

	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)AllocAddress, NULL, 0, NULL);

}


VOID StartThread()
{
	static unsigned long long HookOffset = 0x16BD78;
	do { 全局::模块地址 = (ULONG_PTR)GetModuleHandleA(NULL); Sleep(0); } while (!全局::模块地址);
	do { GameOverlayRenderer64 = (ULONG_PTR)GetModuleHandleA("GameOverlayRenderer64.dll"); Sleep(0); } while (!GameOverlayRenderer64);

	
	do
	{
		if (Memory::Read<ULONG_PTR>(Memory::Read<ULONG_PTR>(Memory::Read<ULONG_PTR>(GameOverlayRenderer64 + HookOffset) + 0xE8)) != NULL)
		{
			static unsigned long long Table[1000] = { 0 };
			Memory::RtlCopyMemoryEx((PBYTE)&Table, (PBYTE)Memory::Read<ULONG_PTR>(Memory::Read<ULONG_PTR>(Memory::Read<ULONG_PTR>(GameOverlayRenderer64 + HookOffset) + 0xE8)), sizeof(Table));
			全局::绘制挂接 = Memory::Read<ULONG_PTR>((ULONG_PTR)&Table + 0x40);
			Memory::Write<ULONG_PTR>((ULONG_PTR)&Table + 0x40, (ULONG_PTR)NewPresent);
			Memory::Write<ULONG_PTR>(Memory::Read<ULONG_PTR>(Memory::Read<ULONG_PTR>(GameOverlayRenderer64 + HookOffset) + 0xE8), (ULONG_PTR)&Table);
			FirstTime = 1;
			break;
		}
		else Sleep(0);
	} while (true);
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		//if (YiYouCheck() == FALSE)
		//{
		//	MessageBoxA(NULL, "获取服务器数据失败！", "请联系作者", MB_OK);
		//	exit(0);
		//}
		sssss();

		
	}
	return TRUE;
}




void sssss()
{

	DWORD_PTR FuncAddress = (DWORD_PTR)GetProcAddress(GetModuleHandleA(XorString("Ntdll.dll")), XorString("ZwReadVirtualMemory"));

	GameData::NtReadVirtualMemoryIndex = *(DWORD*)(FuncAddress + 0x4);


	PCHAR ZwQueryVirtualMemory = (PCHAR)GetProcAddress(GetModuleHandleA(XorString("ntdll.dll")), XorString("ZwOpenThreadToken"));

	PCHAR ZwProtectVirtualMemory = (PCHAR)GetProcAddress(GetModuleHandleA(XorString("ntdll.dll")), XorString("ZwQuerySection"));

	GameData::ZwQueryVirtualMemoryIndex = ZwQueryVirtualMemory[4] - 1;

	GameData::NtUserCreateFile = ZwProtectVirtualMemory[4] - 1;


	HMODULE user32 = GetModuleHandle(L"win32u.dll");
	if (user32)
	{
		DWORD_PTR FuncAddress = (DWORD_PTR)GetProcAddress(user32, XorString("NtUserGetAsyncKeyState"));
		GameData::NtUserGetAsyncKeyStateIndex = *(ULONG*)(FuncAddress + 0x4);
		FuncAddress = (DWORD_PTR)GetProcAddress(user32, XorString("NtUserSendInput"));
		GameData::NtUserSendInputIndex = *(DWORD*)(FuncAddress + 0x4);
	}
	else
	{
		GameData::NtUserGetAsyncKeyStateIndex = 0x1044;
		GameData::NtUserSendInputIndex = 0x1082;
	}
	PassScreenShot();
	StartThread();
}


