#pragma once
#ifndef _DRAW_
#define _DRAW_

// Data
HWND g_pHwnd = NULL;
IDXGISwapChain* g_pSwapChain = NULL;
ID3D11Device* g_pd3dDevice = NULL;
ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
ID3D11RenderTargetView* g_mainRenderTargetView = NULL;
WNDPROC g_OriginalWndProc = NULL;
ImFont* g_font = NULL;
D3D11_VIEWPORT g_d3dViewPort = { 0 };
// KEY
bool g_MenuEnable = true;

typedef struct ICON {
	ID3D11ShaderResourceView* PNG_ID; int Width; int Height;
	ICON() :PNG_ID(NULL), Width(NULL), Height(NULL) {}
	ICON(ID3D11ShaderResourceView* id, int width, int height) :PNG_ID(id), Width(width), Height(height) {};
}*PICON;

namespace Draw
{
	ImDrawList* GetOverlayDrawList() { return ImGui::GetForegroundDrawList();}
	void AddTextEx(const ImFont* font, float font_size, const ImVec2& pos, ImVec4 Color, const char* text_begin, const char* text_end = NULL, float wrap_width = 0.0f, const ImVec4* cpu_fine_clip_rect = NULL);

	VOID Image(PICON pIcon, FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImVec4 Color = ImVec4(255.f, 255.f, 255.f, 1.0f))
	{
		FLOAT wScale = W / pIcon->Width;
		FLOAT hScale = H / pIcon->Height;
		FLOAT scale = pIcon->Height * wScale > H ? hScale : wScale;
		FLOAT dw = pIcon->Width * scale;
		FLOAT dh = pIcon->Height * scale;
		FLOAT dx = X + dw;
		FLOAT dy = Y - dh;

		GetOverlayDrawList()->AddImage(pIcon->PNG_ID, ImVec2(X - dw / 2, dy), ImVec2(dx - dw / 2, Y), ImVec2(0, 0), ImVec2(1, 1), ImGui::ColorConvertFloat4ToU32(Color));
	}

	VOID ImageEx(PICON pIcon, FLOAT X, FLOAT Y, FLOAT W, FLOAT H , ImVec4 Color = ImVec4(255.f, 255.f, 255.f, 1.0f))
	{
		ImVec4 BgColor = ImVec4(0.05f, 0.05f, 0.05f, 0.75f);
		Draw::Image(pIcon, X - 1, Y, W, H, BgColor);
		Draw::Image(pIcon, X, Y - 1, W, H, BgColor);
		Draw::Image(pIcon, X + 1, Y, W, H, BgColor);
		Draw::Image(pIcon, X, Y + 1, W, H, BgColor);
		Draw::Image(pIcon, X, Y, W, H);
		Draw::Image(pIcon, X, Y, W, H, Color);
	}

	// 绘制三角EX
	VOID QuadFilled(FLOAT X, FLOAT Y, FLOAT X2, FLOAT Y2, FLOAT X3, FLOAT Y3, FLOAT X4, FLOAT Y4, ImVec4 Color)
	{
		ImGui::GetForegroundDrawList()->AddQuadFilled(ImVec2(X, Y), ImVec2(X2, Y2), ImVec2(X3, Y3), ImVec2(X4, Y4), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)));
	}
	
	// 绘制方框
	VOID FilledRect(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImVec4 Color)
	{
		GetOverlayDrawList()->AddRectFilled(ImVec2(X, Y), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), 0, 0);
	}

	// 绘制直线
	VOID Line(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImVec4 Color, FLOAT Width)
	{
		GetOverlayDrawList()->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), Width);
	}
	VOID CircleFilled(FLOAT X, FLOAT Y, FLOAT Radius, ImVec4 Color, INT Segments)
	{
		GetOverlayDrawList()->AddCircleFilled(ImVec2(X, Y), Radius, ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), Segments);
	}
	VOID Text(FLOAT X, FLOAT Y, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);
		GetOverlayDrawList()->AddText(NULL, Size, ImVec2(X, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), Buffer);
	}

	FLOAT TextCenter(FLOAT X, FLOAT Y, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);
		ImVec2 TextSize = g_font->CalcTextSizeA(g_font->FontSize, D3D11_FLOAT32_MAX, 0.0f, Buffer);
		GetOverlayDrawList()->AddText(NULL, Size, ImVec2(X - TextSize.x / 2, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), Buffer);
		return X - TextSize.x / 2;
	}

	VOID TextEx(FLOAT X, FLOAT Y, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);

		const char* text_begin = Buffer;
		const char* text_end = text_begin + strlen(Buffer);
		AddTextEx(NULL, Size, ImVec2(X, Y), Color, text_begin, text_end);
	}

	VOID TextMaxWidth(FLOAT X, FLOAT Y, FLOAT MaxWidth, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);

		const char* text_begin = Buffer;
		const char* text_end = text_begin + strlen(Buffer);

		for (const char* i = text_end; i > text_begin + 1; i--)
		{
			ImVec2 TextSize = g_font->CalcTextSizeA(Size > 0.0f ? Size : g_font->FontSize, D3D11_FLOAT32_MAX, 0.0f, text_begin, i);
			if (TextSize.x <= MaxWidth) {
				GetOverlayDrawList()->AddText(NULL, Size, ImVec2(X, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(Color)), text_begin, i);
				break;
			}
		}
	}

	VOID TextMaxWidthEx(FLOAT X, FLOAT Y, FLOAT MaxWidth, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);

		const char* text_begin = Buffer;
		const char* text_end = text_begin + strlen(Buffer);

		for (const char* i = text_end; i > text_begin + 1; i--)
		{
			ImVec2 TextSize = g_font->CalcTextSizeA(Size > 0.0f ? Size : g_font->FontSize, D3D11_FLOAT32_MAX, 0.0f, text_begin, i);
			if (TextSize.x <= MaxWidth) {
				AddTextEx(NULL, Size, ImVec2(X, Y), Color, text_begin, i);
				break;
			}
		}
	}

	FLOAT TextCenterEx(FLOAT X, FLOAT Y, ImVec4 Color, FLOAT Size, CONST CHAR* Str, ...)
	{
		CHAR Buffer[1024] = { 0 };
		va_list va_alist;
		va_start(va_alist, Str);
		vsprintf_s(Buffer, Str, va_alist);
		va_end(va_alist);
		ImVec2 TextSize = g_font->CalcTextSizeA(Size > 0.0f ? Size : g_font->FontSize, D3D11_FLOAT32_MAX, 0.0f, Buffer);
		AddTextEx(NULL, Size, ImVec2(X - TextSize.x / 2, Y), Color, Buffer);
		return X - TextSize.x / 2;
	}

	void AddTextEx(const ImFont* font, float font_size, const ImVec2& pos, ImVec4 Color, const char* text_begin, const char* text_end, float wrap_width, const ImVec4* cpu_fine_clip_rect)
	{
		ImDrawList* drawList = GetOverlayDrawList();

		ImU32 col = ImGui::ColorConvertFloat4ToU32(ImVec4(Color));

		if ((col & IM_COL32_A_MASK) == 0) return;

		if (text_end == NULL) text_end = text_begin + strlen(text_begin);
		if (text_begin == text_end) return;

		// Pull default font/size from the shared ImDrawListSharedData instance
		if (font == NULL) font = drawList->_Data->Font;
		if (font_size == 0.0f) font_size = drawList->_Data->FontSize;

		IM_ASSERT(font->ContainerAtlas->TexID == _CmdHeader.TextureId);  // Use high-level ImGui::PushFont() or low-level ImDrawList::PushTextureId() to change font.

		ImVec4 clip_rect = drawList->_CmdHeader.ClipRect;
		if (cpu_fine_clip_rect)
		{
			clip_rect.x = ImMax(clip_rect.x, cpu_fine_clip_rect->x);
			clip_rect.y = ImMax(clip_rect.y, cpu_fine_clip_rect->y);
			clip_rect.z = ImMin(clip_rect.z, cpu_fine_clip_rect->z);
			clip_rect.w = ImMin(clip_rect.w, cpu_fine_clip_rect->w);
		}

		ImU32 BgColor = ImGui::ColorConvertFloat4ToU32(ImVec4(0.05f, 0.05f, 0.05f, 0.75f));
		font->RenderText(drawList, font_size, ImVec2(pos.x - 1, pos.y), BgColor, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip_rect != NULL);
		font->RenderText(drawList, font_size, ImVec2(pos.x, pos.y - 1), BgColor, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip_rect != NULL);
		font->RenderText(drawList, font_size, ImVec2(pos.x + 1, pos.y), BgColor, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip_rect != NULL);
		font->RenderText(drawList, font_size, ImVec2(pos.x, pos.y + 1), BgColor, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip_rect != NULL);
		font->RenderText(drawList, font_size, pos, col, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip_rect != NULL);
	}

	VOID DX11_NewFrame() {
		g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
		UINT Temp = 1; g_pd3dDeviceContext->RSGetViewports(&Temp, &g_d3dViewPort);
		if (g_d3dViewPort.Width <= 0 || g_d3dViewPort.Height <= 0) {
			RECT rect = { 0, 0, 0, 0 }; ::GetClientRect(g_pHwnd, &rect);
			g_d3dViewPort.Width = (float)(rect.right - rect.left);
			g_d3dViewPort.Height = (float)(rect.bottom - rect.top);
		}
		ImGuiIO& io = ImGui::GetIO();
		g_d3dViewPort.TopLeftX = g_d3dViewPort.Width / 2;
		g_d3dViewPort.TopLeftY = g_d3dViewPort.Height / 2;
		io.DisplaySize = ImVec2((FLOAT)g_d3dViewPort.Width, (FLOAT)g_d3dViewPort.Height);
		ImGui_ImplDX11_NewFrame();
	}
}
// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) {};
	if (g_OriginalWndProc) return CallWindowProcA(g_OriginalWndProc, hWnd, msg, wParam, lParam);
	else return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
#endif