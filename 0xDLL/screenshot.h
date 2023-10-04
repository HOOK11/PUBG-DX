#pragma once

//void HookCreateCompatibleDC() {
//	DbgPrint("HookCreateCompatibleDC£¡");
//}
//void HookCreateCompatibleBitmap() {
//	DbgPrint("HookCreateCompatibleBitmap£¡");
//}
//void HookBitBlt() {
//	DbgPrint("HookBitBlt£¡");
//}
//void HookStretchBlt() {
//	DbgPrint("HookStretchBlt£¡");
//}

void PassGDI()
{
	//BYTE SBlt[] = { 0x33,0xC0, 0x49, 0x8B, 0xE3, 0x5F, 0xC3 };
	//BYTE BBlt[] = { 0x33,0xC0, 0x48, 0x83, 0xC4, 0x60, 0x5F, 0xC3 };
	//BYTE Bitmap[] = { 0x33,0xC0, 0x48, 0x83, 0xC4, 0x20, 0x5F, 0xC3 };
	//BYTE DC[] = { 0x33,0xC0, 0x48, 0x83, 0xC4, 0x20, 0x5B, 0xC3 };
	//HMODULE GDI32 = GetModuleHandleA("GDI32.dll");
	//DWORD_PTR CreateCompatibleDC = (DWORD_PTR)GetProcAddress(GDI32, "CreateCompatibleDC");
	//DWORD_PTR CreateCompatibleBitmap = (DWORD_PTR)GetProcAddress(GDI32, "CreateCompatibleBitmap");
	//DWORD_PTR BitBlt = (DWORD_PTR)GetProcAddress(GDI32, "BitBlt");
	//DWORD_PTR StretchBlt = (DWORD_PTR)GetProcAddress(GDI32, "StretchBlt");

	//Memory::JMP(CreateCompatibleDC, (ULONG_PTR)HookCreateCompatibleDC);
	//Memory::JMP(CreateCompatibleBitmap, (ULONG_PTR)HookCreateCompatibleBitmap);
	//Memory::JMP(BitBlt, (ULONG_PTR)HookBitBlt);
	//Memory::JMP(StretchBlt, (ULONG_PTR)HookStretchBlt);

	//Memory::ForceCopyMemory(CreateCompatibleDC + 0x06, (ULONGLONG)DC, 8);
	//Memory::ForceCopyMemory(CreateCompatibleBitmap + 0x0F, (ULONGLONG)Bitmap, 8);
	//Memory::ForceCopyMemory(BitBlt + 0x14, (ULONGLONG)BBlt, 8);
	//Memory::ForceCopyMemory(StretchBlt + 0x10, (ULONGLONG)SBlt, 7);
}