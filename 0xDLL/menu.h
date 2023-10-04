#pragma once

#ifndef _MENU_
#define _MENU_
#include "date.h"


ImVec4 YColor(DWORD rgb, FLOAT a) {
	return ImVec4((float)((rgb >> 16) & 0xFF) * (1.0f / 255.0f), (float)((rgb >> 8) & 0xFF) * (1.0f / 255.0f), (float)((rgb >> 0) & 0xFF) * (1.0f / 255.0f), a);
}
namespace Menu
{

	bool ScreenFlag = false;
	namespace 菜单设置
	{
		bool 菜单开关 = true;
	}

	namespace 全局设置
	{
		bool 战斗模式 = false;
		bool 图标模式 = false;
		bool 预警开关 = true;
	}

	namespace 自瞄设置
	{
		namespace 自瞄开关
		{
			bool 启用自瞄 = true;
			bool 漏打追踪 = false;
			bool 攻击倒地 = true;
			bool 漏打自瞄 = true;
			bool 辅助瞄准 = false;
			bool 攻击队友 = false;
		}

		namespace 自瞄参数
		{
			float 自瞄速度 = 50.f;
			float 自瞄范围 = 150.f;
		}
	}

	namespace 玩家透视
	{
		namespace 透视开关
		{
			bool 启用透视 = true;
			bool 骨骼 = true;
			bool 观战 = true;
			bool 雷达 = true;
			bool 详细信息 = true;
			bool 危险预警 = true;
		}

		namespace 透视颜色
		{
			ImVec4 不可视 = YColor(0xF8F8FF, 0.75f);
			ImVec4 玩家 = YColor(0xFFFF00, 0.75f);
			ImVec4 倒地 = YColor(0xf15b6c, 0.75f);
			ImVec4 预警 = YColor(0xf15b6c, 0.75f);
			ImVec4 准星 = YColor(0x32CD32, 0.75f);
		}

		namespace 透视参数
		{
			float 骨骼线条宽度 = 2.f;
			float 透视有效距离 = 600.f;
		}
	}
	namespace 物资透视
	{
		namespace 透视开关
		{
			bool 启用透视 = true;
			bool 武器 = true;
			bool 配件 = true;
			bool 防具 = true;
			bool 医疗 = true;
			bool 投掷 = true;
			bool 特殊 = true;
		}

		namespace 透视参数
		{
			float 透视有效距离 = 100.f;
		}

		namespace 透视颜色
		{

			ImVec4 武器 = YColor(0xf58220, 0.8f);
			ImVec4 配件 = YColor(0x508a88, 0.8f);
			ImVec4 防具 = YColor(0x2a5caa, 0.8f);
			ImVec4 医疗 = YColor(0x45b97c, 0.8f);
			ImVec4 投掷 = YColor(0xd9d6c3, 0.8f);
			ImVec4 特殊 = YColor(0xef4136, 0.8f);

		}
	}
	namespace 载具透视
	{
		namespace 透视开关
		{
			bool 启用透视 = true;
		}

		namespace 透视参数
		{
			ImVec4 透视颜色 = YColor(0x694d9f, 0.8f);
			float 透视有效距离 = 500.f;
		}
	}

	namespace 其他透视
	{
		namespace 透视开关
		{
			bool 尸盒 = true;
			bool 空投 = true;

		}

		namespace 透视颜色
		{
			ImVec4 尸盒 = YColor(0x77787b, 0.8f);
			ImVec4 空投 = YColor(0xa7324a, 0.8f);
		}

		namespace 透视参数
		{
			float 尸盒 = 100.f;
			float 空投 = 1000.f;
		}
	}
	//namespace 其他设置
	//{
	//	namespace 功能开关
	//	{
	//		bool 跳跃穿墙 = false;
	//		bool 人物遁地 = false;
	//		bool 子弹追踪 = false;
	//		bool 暴力飞车 = false;
	//	}

	//}
}
VOID DrawMenu()
{
	if (ImGui::GetIO().KeysDownDuration[VK_HOME] == 0.0f)Menu::菜单设置::菜单开关 = !Menu::菜单设置::菜单开关;
	if (ImGui::GetIO().KeysDownDuration[VK_OEM_3] == 0.0f)Menu::全局设置::战斗模式 = !Menu::全局设置::战斗模式;

	if (Menu::菜单设置::菜单开关)
	{
		ImGuiStyle* style = &ImGui::GetStyle();


		style->WindowPadding = ImVec2(15, 15);
		style->WindowRounding = 5.0f;
		style->FramePadding = ImVec2(5, 5);
		style->FrameRounding = 4.0f;
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 9.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;


		style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		/*style->Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);*/
		style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		//style->Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		//style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		//style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		//style->Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
		//style->Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
		//style->Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
		style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		/*style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);*/



		ImGui::Begin(u8"HOME显示/隐藏", &Menu::菜单设置::菜单开关, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);

		ImGui::SetWindowSize({ 350,600 });//菜单固定尺寸

		if (ImGui::CollapsingHeader(u8"用户信息7597418", ImGuiTreeNodeFlags_DefaultOpen))
		{
			//static ImTextureID bg_tex_id = 0;
			//ImTextureID my_tex_id = bg_tex_id;
			//float my_tex_w = (float)445;
			//float my_tex_h = (float)50;
			SYSTEMTIME Time;
			GetLocalTime(&Time);

			CHAR FramerateBuffer[64]{ 0 };
			sprintf_s(FramerateBuffer, u8"FPS %d", (ULONG)ImGui::GetIO().Framerate);
			ImGui::BulletText(FramerateBuffer);
			ImGui::BulletText(u8"北京时间 %04d-%02d-%02d %02d:%02d:%02d", Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond);
			/*ImGui::BulletText(u8"更新时间 %d-%02d-%02d %s", YEAR, MONTH + 1, DAY, __TIME__);*/
			//ImGui::BulletText(Menu::ScreenFlag ? u8"反截图处理完成" : u8"反截图处理中请稍等");
			ImGui::BulletText(u8"[~]键开关战斗模式：%s", Menu::全局设置::战斗模式 ? u8"开" : u8"关");
		}
		if (ImGui::CollapsingHeader(u8"自瞄配置", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"漏打自瞄", &Menu::自瞄设置::自瞄开关::启用自瞄); ImGui::SameLine();
			/*ImGui::Checkbox(u8"漏打追踪", &Menu::自瞄设置::自瞄开关::漏打追踪); ImGui::SameLine();*/
			ImGui::Checkbox(u8"十字准星", &Menu::自瞄设置::自瞄开关::辅助瞄准);

			ImGui::Checkbox(u8"攻击队友", &Menu::自瞄设置::自瞄开关::攻击队友); ImGui::SameLine();
			ImGui::Checkbox(u8"攻击倒地", &Menu::自瞄设置::自瞄开关::攻击倒地);
			ImGui::SliderFloat(u8"自瞄速率", &Menu::自瞄设置::自瞄参数::自瞄速度, 10.f, 150.f, "%0.f");
			ImGui::SliderFloat(u8"自瞄范围", &Menu::自瞄设置::自瞄参数::自瞄范围, 50.f, 300.f, "%0.f");
			/*ImGui::TreePop();*/
		}
		if (ImGui::CollapsingHeader(u8"人物配置", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"玩家", &Menu::玩家透视::透视开关::骨骼); ImGui::SameLine();
			ImGui::Checkbox(u8"观战", &Menu::玩家透视::透视开关::观战); ImGui::SameLine();
			ImGui::Checkbox(u8"雷达", &Menu::玩家透视::透视开关::雷达);
			ImGui::Checkbox(u8"敌人详细信息", &Menu::玩家透视::透视开关::详细信息);
			ImGui::ColorEdit4(u8"玩家", (FLOAT*)&Menu::玩家透视::透视颜色::玩家, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"倒地", (FLOAT*)&Menu::玩家透视::透视颜色::倒地, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"预警", (FLOAT*)&Menu::玩家透视::透视颜色::预警, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"不可视", (FLOAT*)&Menu::玩家透视::透视颜色::不可视, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
			ImGui::SliderFloat(u8"透视距离", &Menu::玩家透视::透视参数::透视有效距离, 50.0f, 1000.0f, "%0.f");
			ImGui::SliderFloat(u8"骨骼粗细", &Menu::玩家透视::透视参数::骨骼线条宽度, 1.0f, 5.0f, "%0.f");
		}



		if (ImGui::CollapsingHeader(u8"物品｜车辆配置", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"载具", &Menu::载具透视::透视开关::启用透视); ImGui::SameLine();
			ImGui::Checkbox(u8"尸盒", &Menu::其他透视::透视开关::尸盒); ImGui::SameLine();
			ImGui::Checkbox(u8"空投", &Menu::其他透视::透视开关::空投);

			ImGui::Checkbox(u8"武器", &Menu::物资透视::透视开关::武器); ImGui::SameLine();
			ImGui::Checkbox(u8"配件", &Menu::物资透视::透视开关::配件); ImGui::SameLine();
			ImGui::Checkbox(u8"防具", &Menu::物资透视::透视开关::防具); ImGui::SameLine();
			ImGui::Checkbox(u8"医疗", &Menu::物资透视::透视开关::医疗);

			ImGui::Checkbox(u8"投掷", &Menu::物资透视::透视开关::投掷); ImGui::SameLine();
			ImGui::Checkbox(u8"高级", &Menu::物资透视::透视开关::特殊); ImGui::SameLine();
			ImGui::Checkbox(u8"贴图透视模式", &Menu::全局设置::图标模式);
			ImGui::ColorEdit4(u8"载具", (FLOAT*)&Menu::载具透视::透视参数::透视颜色, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"尸盒", (FLOAT*)&Menu::其他透视::透视颜色::尸盒, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"空投", (FLOAT*)&Menu::其他透视::透视颜色::空投, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::ColorEdit4(u8"武器", (FLOAT*)&Menu::物资透视::透视颜色::武器, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"防具", (FLOAT*)&Menu::物资透视::透视颜色::防具, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"配件", (FLOAT*)&Menu::物资透视::透视颜色::配件, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"医疗", (FLOAT*)&Menu::物资透视::透视颜色::医疗, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::ColorEdit4(u8"投掷", (FLOAT*)&Menu::物资透视::透视颜色::投掷, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"高级", (FLOAT*)&Menu::物资透视::透视颜色::特殊, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
			ImGui::SliderFloat(u8"载具", &Menu::载具透视::透视参数::透视有效距离, 50.0f, 1000.0f, "%0.f");

			ImGui::SliderFloat(u8"物资", &Menu::物资透视::透视参数::透视有效距离, 50.0f, 300.0f, "%0.f");
			ImGui::SliderFloat(u8"尸盒", &Menu::其他透视::透视参数::尸盒, 50.0f, 300.0f, "%0.f");
			ImGui::SliderFloat(u8"空投", &Menu::其他透视::透视参数::空投, 50.0f, 1000.0f, "%0.f");

		}

		

		ImGui::BulletText(u8"独乐乐不如众乐乐!" );
		//if (ImGui::CollapsingHeader(u8"变态功能配置［高危功能 谨慎使用］", ImGuiTreeNodeFlags_DefaultOpen))
		//{
		//	ImGui::Checkbox(u8"跳跃穿墙", &Menu::其他设置::功能开关::跳跃穿墙); ImGui::SameLine();
		//	ImGui::Checkbox(u8"人物遁地", &Menu::其他设置::功能开关::人物遁地); ImGui::SameLine();
		//	ImGui::Checkbox(u8"极品飞车", &Menu::其他设置::功能开关::暴力飞车);

		//}

		ImGui::End();
	}

}
#endif