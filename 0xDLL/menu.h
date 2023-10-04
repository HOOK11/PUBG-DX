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
	namespace �˵�����
	{
		bool �˵����� = true;
	}

	namespace ȫ������
	{
		bool ս��ģʽ = false;
		bool ͼ��ģʽ = false;
		bool Ԥ������ = true;
	}

	namespace ��������
	{
		namespace ���鿪��
		{
			bool �������� = true;
			bool ©��׷�� = false;
			bool �������� = true;
			bool ©������ = true;
			bool ������׼ = false;
			bool �������� = false;
		}

		namespace �������
		{
			float �����ٶ� = 50.f;
			float ���鷶Χ = 150.f;
		}
	}

	namespace ���͸��
	{
		namespace ͸�ӿ���
		{
			bool ����͸�� = true;
			bool ���� = true;
			bool ��ս = true;
			bool �״� = true;
			bool ��ϸ��Ϣ = true;
			bool Σ��Ԥ�� = true;
		}

		namespace ͸����ɫ
		{
			ImVec4 ������ = YColor(0xF8F8FF, 0.75f);
			ImVec4 ��� = YColor(0xFFFF00, 0.75f);
			ImVec4 ���� = YColor(0xf15b6c, 0.75f);
			ImVec4 Ԥ�� = YColor(0xf15b6c, 0.75f);
			ImVec4 ׼�� = YColor(0x32CD32, 0.75f);
		}

		namespace ͸�Ӳ���
		{
			float ����������� = 2.f;
			float ͸����Ч���� = 600.f;
		}
	}
	namespace ����͸��
	{
		namespace ͸�ӿ���
		{
			bool ����͸�� = true;
			bool ���� = true;
			bool ��� = true;
			bool ���� = true;
			bool ҽ�� = true;
			bool Ͷ�� = true;
			bool ���� = true;
		}

		namespace ͸�Ӳ���
		{
			float ͸����Ч���� = 100.f;
		}

		namespace ͸����ɫ
		{

			ImVec4 ���� = YColor(0xf58220, 0.8f);
			ImVec4 ��� = YColor(0x508a88, 0.8f);
			ImVec4 ���� = YColor(0x2a5caa, 0.8f);
			ImVec4 ҽ�� = YColor(0x45b97c, 0.8f);
			ImVec4 Ͷ�� = YColor(0xd9d6c3, 0.8f);
			ImVec4 ���� = YColor(0xef4136, 0.8f);

		}
	}
	namespace �ؾ�͸��
	{
		namespace ͸�ӿ���
		{
			bool ����͸�� = true;
		}

		namespace ͸�Ӳ���
		{
			ImVec4 ͸����ɫ = YColor(0x694d9f, 0.8f);
			float ͸����Ч���� = 500.f;
		}
	}

	namespace ����͸��
	{
		namespace ͸�ӿ���
		{
			bool ʬ�� = true;
			bool ��Ͷ = true;

		}

		namespace ͸����ɫ
		{
			ImVec4 ʬ�� = YColor(0x77787b, 0.8f);
			ImVec4 ��Ͷ = YColor(0xa7324a, 0.8f);
		}

		namespace ͸�Ӳ���
		{
			float ʬ�� = 100.f;
			float ��Ͷ = 1000.f;
		}
	}
	//namespace ��������
	//{
	//	namespace ���ܿ���
	//	{
	//		bool ��Ծ��ǽ = false;
	//		bool ����ݵ� = false;
	//		bool �ӵ�׷�� = false;
	//		bool �����ɳ� = false;
	//	}

	//}
}
VOID DrawMenu()
{
	if (ImGui::GetIO().KeysDownDuration[VK_HOME] == 0.0f)Menu::�˵�����::�˵����� = !Menu::�˵�����::�˵�����;
	if (ImGui::GetIO().KeysDownDuration[VK_OEM_3] == 0.0f)Menu::ȫ������::ս��ģʽ = !Menu::ȫ������::ս��ģʽ;

	if (Menu::�˵�����::�˵�����)
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



		ImGui::Begin(u8"HOME��ʾ/����", &Menu::�˵�����::�˵�����, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);

		ImGui::SetWindowSize({ 350,600 });//�˵��̶��ߴ�

		if (ImGui::CollapsingHeader(u8"�û���Ϣ7597418", ImGuiTreeNodeFlags_DefaultOpen))
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
			ImGui::BulletText(u8"����ʱ�� %04d-%02d-%02d %02d:%02d:%02d", Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond);
			/*ImGui::BulletText(u8"����ʱ�� %d-%02d-%02d %s", YEAR, MONTH + 1, DAY, __TIME__);*/
			//ImGui::BulletText(Menu::ScreenFlag ? u8"����ͼ�������" : u8"����ͼ���������Ե�");
			ImGui::BulletText(u8"[~]������ս��ģʽ��%s", Menu::ȫ������::ս��ģʽ ? u8"��" : u8"��");
		}
		if (ImGui::CollapsingHeader(u8"��������", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"©������", &Menu::��������::���鿪��::��������); ImGui::SameLine();
			/*ImGui::Checkbox(u8"©��׷��", &Menu::��������::���鿪��::©��׷��); ImGui::SameLine();*/
			ImGui::Checkbox(u8"ʮ��׼��", &Menu::��������::���鿪��::������׼);

			ImGui::Checkbox(u8"��������", &Menu::��������::���鿪��::��������); ImGui::SameLine();
			ImGui::Checkbox(u8"��������", &Menu::��������::���鿪��::��������);
			ImGui::SliderFloat(u8"��������", &Menu::��������::�������::�����ٶ�, 10.f, 150.f, "%0.f");
			ImGui::SliderFloat(u8"���鷶Χ", &Menu::��������::�������::���鷶Χ, 50.f, 300.f, "%0.f");
			/*ImGui::TreePop();*/
		}
		if (ImGui::CollapsingHeader(u8"��������", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"���", &Menu::���͸��::͸�ӿ���::����); ImGui::SameLine();
			ImGui::Checkbox(u8"��ս", &Menu::���͸��::͸�ӿ���::��ս); ImGui::SameLine();
			ImGui::Checkbox(u8"�״�", &Menu::���͸��::͸�ӿ���::�״�);
			ImGui::Checkbox(u8"������ϸ��Ϣ", &Menu::���͸��::͸�ӿ���::��ϸ��Ϣ);
			ImGui::ColorEdit4(u8"���", (FLOAT*)&Menu::���͸��::͸����ɫ::���, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"����", (FLOAT*)&Menu::���͸��::͸����ɫ::����, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"Ԥ��", (FLOAT*)&Menu::���͸��::͸����ɫ::Ԥ��, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"������", (FLOAT*)&Menu::���͸��::͸����ɫ::������, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
			ImGui::SliderFloat(u8"͸�Ӿ���", &Menu::���͸��::͸�Ӳ���::͸����Ч����, 50.0f, 1000.0f, "%0.f");
			ImGui::SliderFloat(u8"������ϸ", &Menu::���͸��::͸�Ӳ���::�����������, 1.0f, 5.0f, "%0.f");
		}



		if (ImGui::CollapsingHeader(u8"��Ʒ����������", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox(u8"�ؾ�", &Menu::�ؾ�͸��::͸�ӿ���::����͸��); ImGui::SameLine();
			ImGui::Checkbox(u8"ʬ��", &Menu::����͸��::͸�ӿ���::ʬ��); ImGui::SameLine();
			ImGui::Checkbox(u8"��Ͷ", &Menu::����͸��::͸�ӿ���::��Ͷ);

			ImGui::Checkbox(u8"����", &Menu::����͸��::͸�ӿ���::����); ImGui::SameLine();
			ImGui::Checkbox(u8"���", &Menu::����͸��::͸�ӿ���::���); ImGui::SameLine();
			ImGui::Checkbox(u8"����", &Menu::����͸��::͸�ӿ���::����); ImGui::SameLine();
			ImGui::Checkbox(u8"ҽ��", &Menu::����͸��::͸�ӿ���::ҽ��);

			ImGui::Checkbox(u8"Ͷ��", &Menu::����͸��::͸�ӿ���::Ͷ��); ImGui::SameLine();
			ImGui::Checkbox(u8"�߼�", &Menu::����͸��::͸�ӿ���::����); ImGui::SameLine();
			ImGui::Checkbox(u8"��ͼ͸��ģʽ", &Menu::ȫ������::ͼ��ģʽ);
			ImGui::ColorEdit4(u8"�ؾ�", (FLOAT*)&Menu::�ؾ�͸��::͸�Ӳ���::͸����ɫ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"ʬ��", (FLOAT*)&Menu::����͸��::͸����ɫ::ʬ��, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"��Ͷ", (FLOAT*)&Menu::����͸��::͸����ɫ::��Ͷ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::ColorEdit4(u8"����", (FLOAT*)&Menu::����͸��::͸����ɫ::����, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"����", (FLOAT*)&Menu::����͸��::͸����ɫ::����, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"���", (FLOAT*)&Menu::����͸��::͸����ɫ::���, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"ҽ��", (FLOAT*)&Menu::����͸��::͸����ɫ::ҽ��, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::ColorEdit4(u8"Ͷ��", (FLOAT*)&Menu::����͸��::͸����ɫ::Ͷ��, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar); ImGui::SameLine();
			ImGui::ColorEdit4(u8"�߼�", (FLOAT*)&Menu::����͸��::͸����ɫ::����, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
			ImGui::SliderFloat(u8"�ؾ�", &Menu::�ؾ�͸��::͸�Ӳ���::͸����Ч����, 50.0f, 1000.0f, "%0.f");

			ImGui::SliderFloat(u8"����", &Menu::����͸��::͸�Ӳ���::͸����Ч����, 50.0f, 300.0f, "%0.f");
			ImGui::SliderFloat(u8"ʬ��", &Menu::����͸��::͸�Ӳ���::ʬ��, 50.0f, 300.0f, "%0.f");
			ImGui::SliderFloat(u8"��Ͷ", &Menu::����͸��::͸�Ӳ���::��Ͷ, 50.0f, 1000.0f, "%0.f");

		}

		

		ImGui::BulletText(u8"�����ֲ���������!" );
		//if (ImGui::CollapsingHeader(u8"��̬�������ã۸�Σ���� ����ʹ�ã�", ImGuiTreeNodeFlags_DefaultOpen))
		//{
		//	ImGui::Checkbox(u8"��Ծ��ǽ", &Menu::��������::���ܿ���::��Ծ��ǽ); ImGui::SameLine();
		//	ImGui::Checkbox(u8"����ݵ�", &Menu::��������::���ܿ���::����ݵ�); ImGui::SameLine();
		//	ImGui::Checkbox(u8"��Ʒ�ɳ�", &Menu::��������::���ܿ���::�����ɳ�);

		//}

		ImGui::End();
	}

}
#endif