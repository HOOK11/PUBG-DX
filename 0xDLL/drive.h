#pragma once

#ifndef _DRIVE_
#define _DRIVE_

//VOID DbgPrint(LPCSTR szFormat, ...)
//{
//	char szBuffer[1024] = { 0 };
//	va_list pArgList;
//	va_start(pArgList, szFormat);
//	_vsnprintf_s(szBuffer, sizeof(szBuffer) / sizeof(char), szFormat, pArgList);
//	va_end(pArgList);
//	char szOutBuffer[1024] = { 0 };
//	sprintf_s(szOutBuffer, "[+] %s \n", szBuffer);
//	//printf(szOutBuffer);
//	OutputDebugStringA(szOutBuffer);
//}

//namespace GSDrive
//{
//	BOOL SendDrvMsg(DWORD Code, PVOID Data, ULONG DataSize)
//	{
//		return RegSetValueExA(HKEY_CURRENT_USER, NULL, NULL, Code, (CONST BYTE*)Data, DataSize) == 998;
//	}
//
//	BOOL UnInject()
//	{
//		DbgPrint("«Â¿Ì◊¢»Î£°");
//		return SendDrvMsg(0x1001, NULL, NULL);
//	}
//}
namespace Memory
{
	template<typename T> T Read(ULONG_PTR _Dst)
	{
		T Ele{};

		if (IsBadHugeReadPtr((PVOID)_Dst, sizeof(T)) == 0)
			Ele = *reinterpret_cast<T*>(_Dst);

		return Ele;
	}

	template<typename T> VOID Write(ULONG_PTR _Dst, T _Src)
	{
		if (IsBadHugeWritePtr((PVOID)_Dst, sizeof(T)) == 0)
			*reinterpret_cast<T*>(_Dst) = _Src;
	}

	//BOOL ForceCopyMemory(ULONGLONG TargetAddress, ULONGLONG SourceAddress, ULONGLONG NumberOfBytes)
	//{
	//	struct
	//	{
	//		ULONGLONG TargetAddress;
	//		ULONGLONG SourceAddress;
	//		ULONGLONG NumberOfBytes;
	//	} Structs;

	//	RtlZeroMemory(&Structs, sizeof(Structs));

	//	Structs.TargetAddress = TargetAddress;

	//	Structs.SourceAddress = SourceAddress;

	//	Structs.NumberOfBytes = NumberOfBytes;

	//	return RegSetValueExA(HKEY_CURRENT_USER, NULL, NULL, 0x1006, (CONST BYTE*) & Structs, sizeof(Structs)) == 998;
	//}

	BOOL ValidPtr(ULONG_PTR Ptr, ULONG Value)
	{
		return (BOOL)(Ptr < 0xFFFF || Ptr > 0x7FFFFFFFFFFF || Ptr % Value);
	}

	VOID JMP(ULONG_PTR HookAddress, ULONG_PTR JumpToAddress)
	{
		unsigned char ShellCode[] = { 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
		*(ULONG_PTR*)(ShellCode + 6) = JumpToAddress;
		for (size_t i = 0; i < sizeof(ShellCode); i++)
		{
			((BYTE*)HookAddress)[i] = ShellCode[i];
		}
	}

	VOID RtlCopyMemoryEx(PBYTE _Dst, PBYTE _Src, SIZE_T _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			_Dst[i] = _Src[i];
		}
	}

	VOID RtlZeroMemoryEx(PBYTE _Dst, SIZE_T _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			_Dst[i] = (BYTE)NULL;
		}
	}

	VOID RtlFillMemoryEx(PBYTE _Dst, BYTE _Src, SIZE_T _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			_Dst[i] = (BYTE)_Src;
		}
	}

	BOOL Compare(CONST BYTE* pData, CONST BYTE* bMask, CONST CHAR* szMask)
	{
		for (; *szMask; ++szMask, ++pData, ++bMask)
			if (*szMask == 'x' && *pData != *bMask)
				return FALSE;
		return (*szMask) == NULL;
	}

	ULONG_PTR FindPatternForModule(ULONG_PTR dwModule, BYTE* bMask, std::string szMask)
	{
		PIMAGE_DOS_HEADER pImageDos = (PIMAGE_DOS_HEADER)dwModule;

		PIMAGE_NT_HEADERS32 pImageNt = (PIMAGE_NT_HEADERS32)(dwModule + pImageDos->e_lfanew);

		ULONG ImageLen = pImageNt->OptionalHeader.SizeOfImage;

		size_t MaskLen = szMask.length();

		for (ULONG i = 0; i < ImageLen - MaskLen; i++)
		{
			if (IsBadHugeReadPtr((PVOID)(dwModule + i), 1) == 0)
			{
				if (Compare((BYTE*)(dwModule + i), bMask, szMask.c_str()))
				{
					return (ULONG_PTR)(dwModule + i);
				}
			}
		}

		return 0;
	}
}

//namespace SSDT
//{
//
//	BOOL CreateThreadEx(ULONGLONG StratAddress, ULONG Flags, BOOL BypassKernelThreadNotify)
//	{
//		/*
//			NULL_THREAD        1
//			HIDE_THREAD        2
//			ANTI_DEBUG_THREAD  3
//		*/
//
//		static struct
//		{
//			ULONGLONG StratAddress;
//			ULONGLONG ThreadType;
//			ULONGLONG BypassNotify;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//
//		Structs.StratAddress = StratAddress;
//
//		Structs.ThreadType = Flags;
//
//		Structs.BypassNotify = BypassKernelThreadNotify;
//
//		return GSDrive::SendDrvMsg(0x1002, &Structs, sizeof(Structs));
//	}
//
//	BOOL VirtualProtect(ULONGLONG MemoryAddress, ULONGLONG MemorySize, ULONG NewProtect)
//	{
//		static struct
//		{
//			ULONGLONG MemoryAddress;
//			ULONGLONG MemorySize;
//			ULONGLONG NewProtect;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//
//		Structs.MemoryAddress = MemoryAddress;
//
//		Structs.MemorySize = MemorySize;
//
//		Structs.NewProtect = NewProtect;
//
//		return GSDrive::SendDrvMsg(0x1003, &Structs, sizeof(Structs));
//	}
//
//	BOOL VirtualQuery(ULONGLONG MemoryAddress, PVOID BufferAddress, ULONGLONG BufferSize)
//	{
//		static struct
//		{
//			ULONGLONG MemoryAddress;
//			ULONGLONG BufferAddress;
//			ULONGLONG BufferSize;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//
//		Structs.MemoryAddress = MemoryAddress;
//
//		Structs.BufferAddress = (ULONGLONG)BufferAddress;
//
//		Structs.BufferSize = BufferSize;
//
//		return GSDrive::SendDrvMsg(0x1004, &Structs, sizeof(Structs));
//	}
//
//	ULONGLONG VirtualAllocate(ULONGLONG DesiredAddress, ULONGLONG RegionSize, ULONGLONG HideMemory)
//	{
//		static struct
//		{
//			ULONGLONG DesiredAddress;
//			ULONGLONG RegionSize;
//			ULONGLONG HideMemory;
//			ULONGLONG BufferAddress;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//
//		Structs.DesiredAddress = DesiredAddress;
//
//		Structs.RegionSize = RegionSize;
//
//		Structs.HideMemory = HideMemory;
//
//		Structs.BufferAddress = (ULONGLONG)&Structs.BufferAddress;
//
//		return GSDrive::SendDrvMsg(0x1005, &Structs, sizeof(Structs)) ? Structs.BufferAddress : NULL;
//	}
//}

//namespace Mouse
//{
//	BOOL SimulatedMove(ULONG X, ULONG Y, ULONG Flags)
//	{
//		static struct
//		{
//			USHORT UnitId;
//			USHORT Flags;
//			union {
//				ULONG Buttons;
//				struct {
//					USHORT  ButtonFlags;
//					USHORT  ButtonData;
//				};
//			};
//			ULONG RawButtons;
//			LONG LastX;
//			LONG LastY;
//			ULONG ExtraInformation;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//
//		if (Flags == MOUSE_MOVE_RELATIVE)
//		{
//			Structs.LastX = X;
//
//			Structs.LastY = Y;
//		}
//		if (Flags == MOUSE_MOVE_ABSOLUTE)
//		{
//			Structs.LastX = X * 65535 / GetSystemMetrics(SM_CXSCREEN);
//
//			Structs.LastY = Y * 65535 / GetSystemMetrics(SM_CYSCREEN);
//		}
//
//		return GSDrive::SendDrvMsg(0x1007, &Structs, sizeof(Structs));
//	}
//
//	BOOL SimulatedButton(ULONG ButtonFlags)
//	{
//		/*
//			MOUSE_BUTTON_1_DOWN    1
//			MOUSE_BUTTON_1_UP      2
//			MOUSE_BUTTON_2_DOWN    4
//			MOUSE_BUTTON_2_UP      8
//			MOUSE_BUTTON_3_DOWN   16
//			MOUSE_BUTTON_3_UP     32
//			MOUSE_BUTTON_4_DOWN   64
//			MOUSE_BUTTON_4_UP    128
//			MOUSE_BUTTON_5_DOWN  256
//			MOUSE_BUTTON_5_UP    512
//			MOUSE_WHEEL         1024
//		*/
//		static struct
//		{
//			USHORT UnitId;
//			USHORT Flags;
//			union {
//				ULONG Buttons;
//				struct {
//					USHORT  ButtonFlags;
//					USHORT  ButtonData;
//				};
//			};
//			ULONG RawButtons;
//			LONG LastX;
//			LONG LastY;
//			ULONG ExtraInformation;
//		} Structs;
//		RtlZeroMemory(&Structs, sizeof(Structs));
//		Structs.ButtonFlags = (USHORT)ButtonFlags;
//		return GSDrive::SendDrvMsg(0x1007, &Structs, sizeof(Structs));
//	}
//}
//
//namespace Keyboard
//{
//	BOOL SimulatedInput(ULONG Key, ULONG Flags)
//	{
//		/*
//			KEY_DOWN    0
//			KEY_UP      1
//		*/
//
//		static struct
//		{
//			USHORT UnitId;
//			USHORT MakeCode;
//			USHORT Flags;
//			USHORT Reserved;
//			ULONG ExtraInformation;
//		} Structs;
//
//		RtlZeroMemory(&Structs, sizeof(Structs));
//		Structs.Flags = (USHORT)Flags;
//		Structs.MakeCode = (USHORT)MapVirtualKeyA(Key, 0);;
//		return GSDrive::SendDrvMsg(0x1008, &Structs, sizeof(Structs));
//	}
//}
#endif