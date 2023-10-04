#include "pch.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

typedef struct ICON {
	ID3D11ShaderResourceView* PNG_ID; int Width; int Height;
	ICON() :PNG_ID(NULL), Width(NULL), Height(NULL) {}
	ICON(ID3D11ShaderResourceView* id, int width, int height) :PNG_ID(id), Width(width), Height(height) {};
}*PICON;

bool LoadTextureFromMemory(ID3D11Device* device,stbi_uc const* buffer, int len, PICON icon)
{
	// Load from disk into a raw RGBA buffer
	int image_width = 0;
	int image_height = 0;
	int image_comp = 0;
	unsigned char* image_data = stbi_load_from_memory(buffer, len, &image_width, &image_height, &image_comp, 4);

	if (image_data == NULL) return false;


	//for (int dx = 0; dx < 10; ++dx)
	//{
	//	image_data[image_comp * image_width * 10 + dx * image_comp + 0] = 255;
	//	image_data[image_comp * image_width * 10 + dx * image_comp + 1] = 0;
	//	image_data[image_comp * image_width * 10 + dx * image_comp + 2] = 0;
	//	image_data[image_comp * image_width * 10 + dx * image_comp + 3] = 255;
 //    }

	// Create texture
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = image_width;
	desc.Height = image_height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;

	ID3D11Texture2D* pTexture = NULL;
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = image_data;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;
	device->CreateTexture2D(&desc, &subResource, &pTexture);

	// Create texture view
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;
	device->CreateShaderResourceView(pTexture, &srvDesc, &icon->PNG_ID);
	pTexture->Release();

	icon->Width = image_width;
	icon->Height = image_height;
	stbi_image_free(image_data);

	return true;
}

extern ICON pAirPack;
extern ICON pWeapon_BluezoneGrenade_C;
extern ICON pWeapon_C4_C;
extern ICON pWeapon_DecoyGrenade_C;
extern ICON pWeapon_FlashBang_c;
extern ICON pWeapon_Grenade_C;
extern ICON pWeapon_Molotov_C;
extern ICON pWeapon_SmokeBomb_C;
extern ICON pWeapon_SpikeTrap_C;
extern ICON pWeapon_StickyGrenade_C;
extern ICON pWeapon_DesertEagle_C;
extern ICON pWeapon_FlareGun_C;
extern ICON pWeapon_G18_C;
extern ICON pWeapon_M1911_C;
extern ICON pWeapon_M9_C;
extern ICON pWeapon_NagantM1895_C;
extern ICON pWeapon_Rhino_C;
extern ICON pWeapon_Sawnoff_C;
extern ICON pWeapon_vz61Skorpion_C;
extern ICON pWeapon_AK47_C;
extern ICON pWeapon_AUG_C;
extern ICON pWeapon_AWM_C;
extern ICON pWeapon_Berreta686_C;
extern ICON pWeapon_BerylM762_C;
extern ICON pWeapon_BizonPP19_C;
extern ICON pWeapon_Crossbow_C;
extern ICON pWeapon_DP12_C;
extern ICON pWeapon_DP28_C;
extern ICON pWeapon_FNFal_C;
extern ICON pWeapon_G36C_C;
extern ICON pWeapon_Groza_C;
extern ICON pWeapon_HK416_C;
extern ICON pWeapon_K2_C;
extern ICON pWeapon_Kar98k_C;
extern ICON pWeapon_L6_C;
extern ICON pWeapon_M16A4_C;
extern ICON pWeapon_M249_C;
extern ICON pWeapon_M24_C;
extern ICON pWeapon_MG3_C;
extern ICON pWeapon_Mini14_C;
extern ICON pWeapon_Mk12_C;
extern ICON pWeapon_Mk14_C;
extern ICON pWeapon_Mk47Mutant_C;
extern ICON pWeapon_Mosin_C;
extern ICON pWeapon_MP5K_C;
extern ICON pWeapon_P90_C;
extern ICON pWeapon_PanzerFaust100M_C;
extern ICON pWeapon_QBU88_C;
extern ICON pWeapon_QBZ95_C;
extern ICON pWeapon_Saiga12_C;
extern ICON pWeapon_SCAR_L_C;
extern ICON pWeapon_SKS_C;
extern ICON pWeapon_Thompson_C;
extern ICON pWeapon_UMP_C;
extern ICON pWeapon_UZI_C;
extern ICON pWeapon_Vector_C;
extern ICON pWeapon_VSS_C;
extern ICON pWeapon_Win1894_C;
extern ICON pWeapon_Winchester_C;
extern ICON pWeapon_Cowbar_C;
extern ICON pWeapon_Machete_C;
extern ICON pWeapon_Pan_C;
extern ICON pWeapon_Sickle_C;
extern ICON pGroggy;
extern ICON pPunch;
extern ICON pItem_Ammo_12Guage_C;
extern ICON pItem_Ammo_300Magnum_C;
extern ICON pItem_Ammo_303Ball_C;
extern ICON pItem_Ammo_44Magnum_C;
extern ICON pItem_Ammo_45ACP_C;
extern ICON pItem_Ammo_556mm_C;
extern ICON pItem_Ammo_762mm_C;
extern ICON pItem_Ammo_9mm_C;
extern ICON pItem_Ammo_Bolt_C;
extern ICON pItem_Ammo_Flare_C;
extern ICON pItem_Attach_Weapon_Lower_AngledForeGrip_C;
extern ICON pItem_Attach_Weapon_Lower_Foregrip_C;
extern ICON pItem_Attach_Weapon_Lower_Foregrip_Crossbow;
extern ICON pItem_Attach_Weapon_Lower_HalfGrip_C;
extern ICON pItem_Attach_Weapon_Lower_LaserPointer_C;
extern ICON pItem_Attach_Weapon_Lower_LightweightForeGrip_C;
extern ICON pItem_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C;
extern ICON pItem_Attach_Weapon_Lower_Sniper_CheekPad_Vss_setting;
extern ICON pItem_Attach_Weapon_Lower_ThumbGrip_C;
extern ICON pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C;
extern ICON pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C;
extern ICON pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C;
extern ICON pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C;
extern ICON pItem_Attach_Weapon_Magazine_Extended_DrumMagazine;
extern ICON pItem_Attach_Weapon_Magazine_Extended_Large_C;
extern ICON pItem_Attach_Weapon_Magazine_Extended_Medium_C;
extern ICON pItem_Attach_Weapon_Magazine_Extended_Small_C;
extern ICON pItem_Attach_Weapon_Magazine_Extended_SniperRifle_C;
extern ICON pItem_Attach_Weapon_Magazine_QuickDraw_Large_C;
extern ICON pItem_Attach_Weapon_Magazine_QuickDraw_Medium_C;
extern ICON pItem_Attach_Weapon_Magazine_QuickDraw_Small_C;
extern ICON pItem_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C;
extern ICON pItem_Attach_Weapon_Magazine_SR_ExtendedQuick_Mag_Vss_setting;
extern ICON pItem_Attach_Weapon_Magazine_SR_Extended_Mag_Vss_setting;
extern ICON pItem_Attach_Weapon_Magazine_SR_QucikDraw_Magazine_Vss_setting;
extern ICON pItem_Attach_Weapon_Medium_ExtendedQuickDraw_Magazine_Vector;
extern ICON pItem_Attach_Weapon_Medium_Extended_Magazine_Vector;
extern ICON pItem_Attach_Weapon_Medium_QuickDraw_Magazine_Vector;
extern ICON pItem_Attach_Weapon_Muzzle_Choke_C;
extern ICON pItem_Attach_Weapon_Muzzle_Compensator_Large_C;
extern ICON pItem_Attach_Weapon_Muzzle_Compensator_Medium_C;
extern ICON pItem_Attach_Weapon_Muzzle_Compensator_SniperRifle_C;
extern ICON pItem_Attach_Weapon_Muzzle_Duckbill_C;
extern ICON pItem_Attach_Weapon_Muzzle_FlashHider_Large_C;
extern ICON pItem_Attach_Weapon_Muzzle_FlashHider_Medium_C;
extern ICON pItem_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C;
extern ICON pItem_Attach_Weapon_Muzzle_Suppressor_Large_C;
extern ICON pItem_Attach_Weapon_Muzzle_Suppressor_Medium_C;
extern ICON pItem_Attach_Weapon_Muzzle_Suppressor_Small_C;
extern ICON pItem_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C;
extern ICON pItem_Attach_Weapon_SideRail_DotSight_RMR_C;
extern ICON pItem_Attach_Weapon_Stock_AR_Composite_C;
extern ICON pItem_Attach_Weapon_Stock_Shotgun_BulletLoops_C;
extern ICON pItem_Attach_Weapon_Stock_SniperRifle_BulletLoops_C;
extern ICON pItem_Attach_Weapon_Stock_SniperRifle_CheekPad_C;
extern ICON pItem_Attach_Weapon_Stock_UZI_C;
extern ICON pItem_Attach_Weapon_Upper_ACOG_01_C;
extern ICON pItem_Attach_Weapon_Upper_Aimpoint_C;
extern ICON pItem_Attach_Weapon_Upper_CQBSS_C;
extern ICON pItem_Attach_Weapon_Upper_DotSight_01_C;
extern ICON pItem_Attach_Weapon_Upper_Holosight_C;
extern ICON pItem_Attach_Weapon_Upper_PM2_01_C;
extern ICON pItem_Attach_Weapon_Upper_Scope3x_C;
extern ICON pItem_Attach_Weapon_Upper_Scope6x_C;
extern ICON pItem_Attach_Weapon_Vector_VerGrip;
extern ICON pItem_Back_BlueBlocker;
extern ICON pItem_Back_B_01_StartParachutePack_C;
extern ICON pItem_Back_C_01_Lv3_C;
extern ICON pItem_Back_C_02_Lv3_C;
extern ICON pItem_Back_E_01_Lv1_C;
extern ICON pItem_Back_E_02_Lv1_C;
extern ICON pItem_Back_F_01_Lv2_C;
extern ICON pItem_Back_F_02_Lv2_C;
extern ICON pItem_Head_E_01_Lv1_C;
extern ICON pItem_Head_E_02_Lv1_C;
extern ICON pItem_Head_F_01_Lv2_C;
extern ICON pItem_Head_F_02_Lv2_C;
extern ICON pItem_Head_G_01_Lv3_C;
extern ICON pItem_Ghillie_01_C;
extern ICON pItem_Ghillie_02_C;
extern ICON pItem_Ghillie_03_C;
extern ICON pItem_Ghillie_04_C;
extern ICON pItem_Ghillie_05_C;
extern ICON pItem_Ghillie_06_C;
extern ICON pItem_Weapon_Apple_C;
extern ICON pItem_Weapon_BluezoneGrenade_C;
extern ICON pItem_Weapon_C4_C;
extern ICON pItem_Weapon_DecoyGrenade_C;
extern ICON pItem_Weapon_FlashBang_C;
extern ICON pItem_Weapon_Grenade_C;
extern ICON pItem_Weapon_Molotov_C;
extern ICON pItem_Weapon_Rock_C;
extern ICON pItem_Weapon_SmokeBomb_C;
extern ICON pItem_Weapon_Snowball_C;
extern ICON pItem_Weapon_SpikeTrap_C;
extern ICON pItem_Weapon_StickyGrenade_C;
extern ICON pItem_Armor_C_01_Lv3_C;
extern ICON pItem_Armor_D_01_Lv2_C;
extern ICON pItem_Armor_E_01_Lv1_C;
extern ICON pItem_Boost_AdrenalineSyringe_C;
extern ICON pItem_Boost_EnergyDrink_C;
extern ICON pItem_Boost_PainKiller_C;
extern ICON pItem_JerryCan_C;
extern ICON pItem_Heal_Bandage_C;
extern ICON pItem_Heal_FirstAid_C;
extern ICON pItem_Heal_MedKit_C;
extern ICON pItem_Weapon_DesertEagle_C;
extern ICON pItem_Weapon_FlareGun_C;
extern ICON pItem_Weapon_G18_C;
extern ICON pItem_Weapon_M1911_C;
extern ICON pItem_Weapon_M79_C;
extern ICON pItem_Weapon_M9_C;
extern ICON pItem_Weapon_NagantM1895_C;
extern ICON pItem_Weapon_Rhino_C;
extern ICON pItem_Weapon_Sawnoff_C;
extern ICON pItem_Weapon_vz61Skorpion_C;
extern ICON pItem_Weapon_AK47_C;
extern ICON pItem_Weapon_AUG_C;
extern ICON pItem_Weapon_AWM_C;
extern ICON pItem_Weapon_Berreta686_C;
extern ICON pItem_Weapon_BerylM762_C;
extern ICON pItem_Weapon_BizonPP19_C;
extern ICON pItem_Weapon_Crossbow_C;
extern ICON pItem_Weapon_DP12_C;
extern ICON pItem_Weapon_DP28_C;
extern ICON pItem_Weapon_FNFal_C;
extern ICON pItem_Weapon_G36C_C;
extern ICON pItem_Weapon_Groza_C;
extern ICON pItem_Weapon_HK416_C;
extern ICON pItem_Weapon_K2_C;
extern ICON pItem_Weapon_Kar98k_C;
extern ICON pItem_Weapon_L6_C;
extern ICON pItem_Weapon_M16A4_C;
extern ICON pItem_Weapon_M249_C;
extern ICON pItem_Weapon_M24_C;
extern ICON pItem_Weapon_MG3_C;
extern ICON pItem_Weapon_Mini14_C;
extern ICON pItem_Weapon_Mk12_C;
extern ICON pItem_Weapon_Mk14_C;
extern ICON pItem_Weapon_Mk47Mutant_C;
extern ICON pItem_Weapon_Mortar_C;
extern ICON pItem_Weapon_Mosin_C;
extern ICON pItem_Weapon_MP5K_C;
extern ICON pItem_Weapon_P90_C;
extern ICON pItem_Weapon_PanzerFaust100M_C;
extern ICON pItem_Weapon_QBU88_C;
extern ICON pItem_Weapon_QBZ95_C;
extern ICON pItem_Weapon_Saiga12_C;
extern ICON pItem_Weapon_SCAR_L_C;
extern ICON pItem_Weapon_SKS_C;
extern ICON pItem_Weapon_Thompson_C;
extern ICON pItem_Weapon_UMP_C;
extern ICON pItem_Weapon_UZI_C;
extern ICON pItem_Weapon_Vector_C;
extern ICON pItem_Weapon_VSS_C;
extern ICON pItem_Weapon_Win1894_C;
extern ICON pItem_Weapon_Winchester_C;
extern ICON pItem_Weapon_Cowbar_C;
extern ICON pItem_Weapon_Machete_C;
extern ICON pItem_Weapon_Pan_C;
extern ICON pItem_Weapon_Sickle_C;

#include "../资源文件/png/\Icons\CarePackage\AirPack.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_BluezoneGrenade_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_C4_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_DecoyGrenade_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_FlashBang_c.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_Grenade_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_Molotov_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_SmokeBomb_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_SpikeTrap_C.h"
#include "../资源文件/png/\Icons\Item\Equipment\Throwable\Weapon_StickyGrenade_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_DesertEagle_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_FlareGun_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_G18_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_M1911_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_M9_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_NagantM1895_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_Rhino_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_Sawnoff_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Handgun\Weapon_vz61Skorpion_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_AK47_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_AUG_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_AWM_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Berreta686_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_BerylM762_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_BizonPP19_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Crossbow_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_DP12_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_DP28_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_FNFal_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_G36C_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Groza_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_HK416_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_K2_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Kar98k_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_L6_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_M16A4_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_M249_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_M24_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_MG3_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Mini14_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Mk12_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Mk14_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Mk47Mutant_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Mosin_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_MP5K_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_P90_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_PanzerFaust100M_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_QBU88_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_QBZ95_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Saiga12_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_SCAR-L_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_SKS_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Thompson_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_UMP_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_UZI_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Vector_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_VSS_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Win1894_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Main\Weapon_Winchester_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Melee\Weapon_Cowbar_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Melee\Weapon_Machete_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Melee\Weapon_Pan_C.h"
#include "../资源文件/png/\Icons\Item\Weapon\Melee\Weapon_Sickle_C.h"
#include "../资源文件/png/\Icons\Killfeed\Groggy.h"
#include "../资源文件/png/\Icons\Killfeed\Punch.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_12Guage_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_300Magnum_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_303Ball_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_44Magnum_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_45ACP_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_556mm_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_762mm_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_9mm_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_Bolt_C.h"
#include "../资源文件/png/\Item\Ammunition\None\Item_Ammo_Flare_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_AngledForeGrip_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_Foregrip_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_Foregrip_Crossbow.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_HalfGrip_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_LaserPointer_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_LightweightForeGrip_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_Sniper_CheekPad_Vss_setting.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Lower_ThumbGrip_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_Extended_DrumMagazine.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_Extended_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_Extended_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_Extended_Small_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_Extended_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_QuickDraw_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_QuickDraw_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_QuickDraw_Small_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_SR_ExtendedQuick_Mag_Vss_setting.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_SR_Extended_Mag_Vss_setting.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Magazine_SR_QucikDraw_Magazine_Vss_setting.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Medium_ExtendedQuickDraw_Magazine_Vector.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Medium_Extended_Magazine_Vector.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Medium_QuickDraw_Magazine_Vector.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Choke_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Compensator_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Compensator_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Compensator_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Duckbill_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_FlashHider_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_FlashHider_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Suppressor_Large_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Suppressor_Medium_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Suppressor_Small_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_SideRail_DotSight_RMR_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Stock_AR_Composite_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Stock_Shotgun_BulletLoops_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Stock_SniperRifle_BulletLoops_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Stock_SniperRifle_CheekPad_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Stock_UZI_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_ACOG_01_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_Aimpoint_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_CQBSS_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_DotSight_01_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_Holosight_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_PM2_01_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_Scope3x_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Upper_Scope6x_C.h"
#include "../资源文件/png/\Item\Attachment\Item_Attach_Weapon_Vector_VerGrip.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_BlueBlocker.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_B_01_StartParachutePack_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_C_01_Lv3_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_C_02_Lv3_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_E_01_Lv1_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_E_02_Lv1_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_F_01_Lv2_C.h"
#include "../资源文件/png/\Item\Equipment\Backpack\Item_Back_F_02_Lv2_C.h"
#include "../资源文件/png/\Item\Equipment\Headgear\Item_Head_E_01_Lv1_C.h"
#include "../资源文件/png/\Item\Equipment\Headgear\Item_Head_E_02_Lv1_C.h"
#include "../资源文件/png/\Item\Equipment\Headgear\Item_Head_F_01_Lv2_C.h"
#include "../资源文件/png/\Item\Equipment\Headgear\Item_Head_F_02_Lv2_C.h"
#include "../资源文件/png/\Item\Equipment\Headgear\Item_Head_G_01_Lv3_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_01_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_02_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_03_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_04_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_05_C.h"
#include "../资源文件/png/\Item\Equipment\Jacket\Item_Ghillie_06_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_Apple_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_BluezoneGrenade_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_C4_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_DecoyGrenade_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_FlashBang_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_Grenade_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_Molotov_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_Rock_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_SmokeBomb_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_Snowball_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_SpikeTrap_C.h"
#include "../资源文件/png/\Item\Equipment\Throwable\Item_Weapon_StickyGrenade_C.h"
#include "../资源文件/png/\Item\Equipment\Vest\Item_Armor_C_01_Lv3_C.h"
#include "../资源文件/png/\Item\Equipment\Vest\Item_Armor_D_01_Lv2_C.h"
#include "../资源文件/png/\Item\Equipment\Vest\Item_Armor_E_01_Lv1_C.h"
#include "../资源文件/png/\Item\Use\Boost\Item_Boost_AdrenalineSyringe_C.h"
#include "../资源文件/png/\Item\Use\Boost\Item_Boost_EnergyDrink_C.h"
#include "../资源文件/png/\Item\Use\Boost\Item_Boost_PainKiller_C.h"
#include "../资源文件/png/\Item\Use\Fuel\Item_JerryCan_C.h"
#include "../资源文件/png/\Item\Use\Heal\Item_Heal_Bandage_C.h"
#include "../资源文件/png/\Item\Use\Heal\Item_Heal_FirstAid_C.h"
#include "../资源文件/png/\Item\Use\Heal\Item_Heal_MedKit_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_DesertEagle_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_FlareGun_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_G18_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_M1911_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_M79_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_M9_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_NagantM1895_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_Rhino_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_Sawnoff_C.h"
#include "../资源文件/png/\Item\Weapon\Handgun\Item_Weapon_vz61Skorpion_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_AK47_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_AUG_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_AWM_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Berreta686_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_BerylM762_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_BizonPP19_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Crossbow_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_DP12_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_DP28_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_FNFal_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_G36C_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Groza_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_HK416_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_K2_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Kar98k_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_L6_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_M16A4_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_M249_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_M24_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_MG3_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mini14_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mk12_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mk14_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mk47Mutant_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mortar_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Mosin_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_MP5K_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_P90_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_PanzerFaust100M_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_QBU88_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_QBZ95_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Saiga12_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_SCAR-L_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_SKS_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Thompson_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_UMP_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_UZI_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Vector_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_VSS_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Win1894_C.h"
#include "../资源文件/png/\Item\Weapon\Main\Item_Weapon_Winchester_C.h"
#include "../资源文件/png/\Item\Weapon\Melee\Item_Weapon_Cowbar_C.h"
#include "../资源文件/png/\Item\Weapon\Melee\Item_Weapon_Machete_C.h"
#include "../资源文件/png/\Item\Weapon\Melee\Item_Weapon_Pan_C.h"
#include "../资源文件/png/\Item\Weapon\Melee\Item_Weapon_Sickle_C.h"


void InitPNG(ID3D11Device* device)
{
	LoadTextureFromMemory(device, AirPack, sizeof(AirPack), &pAirPack);
	LoadTextureFromMemory(device, Weapon_BluezoneGrenade_C, sizeof(Weapon_BluezoneGrenade_C), &pWeapon_BluezoneGrenade_C);
	LoadTextureFromMemory(device, Weapon_C4_C, sizeof(Weapon_C4_C), &pWeapon_C4_C);
	LoadTextureFromMemory(device, Weapon_DecoyGrenade_C, sizeof(Weapon_DecoyGrenade_C), &pWeapon_DecoyGrenade_C);
	LoadTextureFromMemory(device, Weapon_FlashBang_c, sizeof(Weapon_FlashBang_c), &pWeapon_FlashBang_c);
	LoadTextureFromMemory(device, Weapon_Grenade_C, sizeof(Weapon_Grenade_C), &pWeapon_Grenade_C);
	LoadTextureFromMemory(device, Weapon_Molotov_C, sizeof(Weapon_Molotov_C), &pWeapon_Molotov_C);
	LoadTextureFromMemory(device, Weapon_SmokeBomb_C, sizeof(Weapon_SmokeBomb_C), &pWeapon_SmokeBomb_C);
	LoadTextureFromMemory(device, Weapon_SpikeTrap_C, sizeof(Weapon_SpikeTrap_C), &pWeapon_SpikeTrap_C);
	LoadTextureFromMemory(device, Weapon_StickyGrenade_C, sizeof(Weapon_StickyGrenade_C), &pWeapon_StickyGrenade_C);
	LoadTextureFromMemory(device, Weapon_DesertEagle_C, sizeof(Weapon_DesertEagle_C), &pWeapon_DesertEagle_C);
	LoadTextureFromMemory(device, Weapon_FlareGun_C, sizeof(Weapon_FlareGun_C), &pWeapon_FlareGun_C);
	LoadTextureFromMemory(device, Weapon_G18_C, sizeof(Weapon_G18_C), &pWeapon_G18_C);
	LoadTextureFromMemory(device, Weapon_M1911_C, sizeof(Weapon_M1911_C), &pWeapon_M1911_C);
	LoadTextureFromMemory(device, Weapon_M9_C, sizeof(Weapon_M9_C), &pWeapon_M9_C);
	LoadTextureFromMemory(device, Weapon_NagantM1895_C, sizeof(Weapon_NagantM1895_C), &pWeapon_NagantM1895_C);
	LoadTextureFromMemory(device, Weapon_Rhino_C, sizeof(Weapon_Rhino_C), &pWeapon_Rhino_C);
	LoadTextureFromMemory(device, Weapon_Sawnoff_C, sizeof(Weapon_Sawnoff_C), &pWeapon_Sawnoff_C);
	LoadTextureFromMemory(device, Weapon_vz61Skorpion_C, sizeof(Weapon_vz61Skorpion_C), &pWeapon_vz61Skorpion_C);
	LoadTextureFromMemory(device, Weapon_AK47_C, sizeof(Weapon_AK47_C), &pWeapon_AK47_C);
	LoadTextureFromMemory(device, Weapon_AUG_C, sizeof(Weapon_AUG_C), &pWeapon_AUG_C);
	LoadTextureFromMemory(device, Weapon_AWM_C, sizeof(Weapon_AWM_C), &pWeapon_AWM_C);
	LoadTextureFromMemory(device, Weapon_Berreta686_C, sizeof(Weapon_Berreta686_C), &pWeapon_Berreta686_C);
	LoadTextureFromMemory(device, Weapon_BerylM762_C, sizeof(Weapon_BerylM762_C), &pWeapon_BerylM762_C);
	LoadTextureFromMemory(device, Weapon_BizonPP19_C, sizeof(Weapon_BizonPP19_C), &pWeapon_BizonPP19_C);
	LoadTextureFromMemory(device, Weapon_Crossbow_C, sizeof(Weapon_Crossbow_C), &pWeapon_Crossbow_C);
	LoadTextureFromMemory(device, Weapon_DP12_C, sizeof(Weapon_DP12_C), &pWeapon_DP12_C);
	LoadTextureFromMemory(device, Weapon_DP28_C, sizeof(Weapon_DP28_C), &pWeapon_DP28_C);
	LoadTextureFromMemory(device, Weapon_FNFal_C, sizeof(Weapon_FNFal_C), &pWeapon_FNFal_C);
	LoadTextureFromMemory(device, Weapon_G36C_C, sizeof(Weapon_G36C_C), &pWeapon_G36C_C);
	LoadTextureFromMemory(device, Weapon_Groza_C, sizeof(Weapon_Groza_C), &pWeapon_Groza_C);
	LoadTextureFromMemory(device, Weapon_HK416_C, sizeof(Weapon_HK416_C), &pWeapon_HK416_C);
	LoadTextureFromMemory(device, Weapon_K2_C, sizeof(Weapon_K2_C), &pWeapon_K2_C);
	LoadTextureFromMemory(device, Weapon_Kar98k_C, sizeof(Weapon_Kar98k_C), &pWeapon_Kar98k_C);
	LoadTextureFromMemory(device, Weapon_L6_C, sizeof(Weapon_L6_C), &pWeapon_L6_C);
	LoadTextureFromMemory(device, Weapon_M16A4_C, sizeof(Weapon_M16A4_C), &pWeapon_M16A4_C);
	LoadTextureFromMemory(device, Weapon_M249_C, sizeof(Weapon_M249_C), &pWeapon_M249_C);
	LoadTextureFromMemory(device, Weapon_M24_C, sizeof(Weapon_M24_C), &pWeapon_M24_C);
	LoadTextureFromMemory(device, Weapon_MG3_C, sizeof(Weapon_MG3_C), &pWeapon_MG3_C);
	LoadTextureFromMemory(device, Weapon_Mini14_C, sizeof(Weapon_Mini14_C), &pWeapon_Mini14_C);
	LoadTextureFromMemory(device, Weapon_Mk12_C, sizeof(Weapon_Mk12_C), &pWeapon_Mk12_C);
	LoadTextureFromMemory(device, Weapon_Mk14_C, sizeof(Weapon_Mk14_C), &pWeapon_Mk14_C);
	LoadTextureFromMemory(device, Weapon_Mk47Mutant_C, sizeof(Weapon_Mk47Mutant_C), &pWeapon_Mk47Mutant_C);
	LoadTextureFromMemory(device, Weapon_Mosin_C, sizeof(Weapon_Mosin_C), &pWeapon_Mosin_C);
	LoadTextureFromMemory(device, Weapon_MP5K_C, sizeof(Weapon_MP5K_C), &pWeapon_MP5K_C);
	LoadTextureFromMemory(device, Weapon_P90_C, sizeof(Weapon_P90_C), &pWeapon_P90_C);
	LoadTextureFromMemory(device, Weapon_PanzerFaust100M_C, sizeof(Weapon_PanzerFaust100M_C), &pWeapon_PanzerFaust100M_C);
	LoadTextureFromMemory(device, Weapon_QBU88_C, sizeof(Weapon_QBU88_C), &pWeapon_QBU88_C);
	LoadTextureFromMemory(device, Weapon_QBZ95_C, sizeof(Weapon_QBZ95_C), &pWeapon_QBZ95_C);
	LoadTextureFromMemory(device, Weapon_Saiga12_C, sizeof(Weapon_Saiga12_C), &pWeapon_Saiga12_C);
	LoadTextureFromMemory(device, Weapon_SCAR_L_C, sizeof(Weapon_SCAR_L_C), &pWeapon_SCAR_L_C);
	LoadTextureFromMemory(device, Weapon_SKS_C, sizeof(Weapon_SKS_C), &pWeapon_SKS_C);
	LoadTextureFromMemory(device, Weapon_Thompson_C, sizeof(Weapon_Thompson_C), &pWeapon_Thompson_C);
	LoadTextureFromMemory(device, Weapon_UMP_C, sizeof(Weapon_UMP_C), &pWeapon_UMP_C);
	LoadTextureFromMemory(device, Weapon_UZI_C, sizeof(Weapon_UZI_C), &pWeapon_UZI_C);
	LoadTextureFromMemory(device, Weapon_Vector_C, sizeof(Weapon_Vector_C), &pWeapon_Vector_C);
	LoadTextureFromMemory(device, Weapon_VSS_C, sizeof(Weapon_VSS_C), &pWeapon_VSS_C);
	LoadTextureFromMemory(device, Weapon_Win1894_C, sizeof(Weapon_Win1894_C), &pWeapon_Win1894_C);
	LoadTextureFromMemory(device, Weapon_Winchester_C, sizeof(Weapon_Winchester_C), &pWeapon_Winchester_C);
	LoadTextureFromMemory(device, Weapon_Cowbar_C, sizeof(Weapon_Cowbar_C), &pWeapon_Cowbar_C);
	LoadTextureFromMemory(device, Weapon_Machete_C, sizeof(Weapon_Machete_C), &pWeapon_Machete_C);
	LoadTextureFromMemory(device, Weapon_Pan_C, sizeof(Weapon_Pan_C), &pWeapon_Pan_C);
	LoadTextureFromMemory(device, Weapon_Sickle_C, sizeof(Weapon_Sickle_C), &pWeapon_Sickle_C);
	LoadTextureFromMemory(device, Groggy, sizeof(Groggy), &pGroggy);
	LoadTextureFromMemory(device, Punch, sizeof(Punch), &pPunch);
	LoadTextureFromMemory(device, Item_Ammo_12Guage_C, sizeof(Item_Ammo_12Guage_C), &pItem_Ammo_12Guage_C);
	LoadTextureFromMemory(device, Item_Ammo_300Magnum_C, sizeof(Item_Ammo_300Magnum_C), &pItem_Ammo_300Magnum_C);
	LoadTextureFromMemory(device, Item_Ammo_303Ball_C, sizeof(Item_Ammo_303Ball_C), &pItem_Ammo_303Ball_C);
	LoadTextureFromMemory(device, Item_Ammo_44Magnum_C, sizeof(Item_Ammo_44Magnum_C), &pItem_Ammo_44Magnum_C);
	LoadTextureFromMemory(device, Item_Ammo_45ACP_C, sizeof(Item_Ammo_45ACP_C), &pItem_Ammo_45ACP_C);
	LoadTextureFromMemory(device, Item_Ammo_556mm_C, sizeof(Item_Ammo_556mm_C), &pItem_Ammo_556mm_C);
	LoadTextureFromMemory(device, Item_Ammo_762mm_C, sizeof(Item_Ammo_762mm_C), &pItem_Ammo_762mm_C);
	LoadTextureFromMemory(device, Item_Ammo_9mm_C, sizeof(Item_Ammo_9mm_C), &pItem_Ammo_9mm_C);
	LoadTextureFromMemory(device, Item_Ammo_Bolt_C, sizeof(Item_Ammo_Bolt_C), &pItem_Ammo_Bolt_C);
	LoadTextureFromMemory(device, Item_Ammo_Flare_C, sizeof(Item_Ammo_Flare_C), &pItem_Ammo_Flare_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_AngledForeGrip_C, sizeof(Item_Attach_Weapon_Lower_AngledForeGrip_C), &pItem_Attach_Weapon_Lower_AngledForeGrip_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_Foregrip_C, sizeof(Item_Attach_Weapon_Lower_Foregrip_C), &pItem_Attach_Weapon_Lower_Foregrip_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_Foregrip_Crossbow, sizeof(Item_Attach_Weapon_Lower_Foregrip_Crossbow), &pItem_Attach_Weapon_Lower_Foregrip_Crossbow);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_HalfGrip_C, sizeof(Item_Attach_Weapon_Lower_HalfGrip_C), &pItem_Attach_Weapon_Lower_HalfGrip_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_LaserPointer_C, sizeof(Item_Attach_Weapon_Lower_LaserPointer_C), &pItem_Attach_Weapon_Lower_LaserPointer_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_LightweightForeGrip_C, sizeof(Item_Attach_Weapon_Lower_LightweightForeGrip_C), &pItem_Attach_Weapon_Lower_LightweightForeGrip_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C, sizeof(Item_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C), &pItem_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_Sniper_CheekPad_Vss_setting, sizeof(Item_Attach_Weapon_Lower_Sniper_CheekPad_Vss_setting), &pItem_Attach_Weapon_Lower_Sniper_CheekPad_Vss_setting);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Lower_ThumbGrip_C, sizeof(Item_Attach_Weapon_Lower_ThumbGrip_C), &pItem_Attach_Weapon_Lower_ThumbGrip_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C, sizeof(Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C), &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C, sizeof(Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C), &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C, sizeof(Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C), &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C, sizeof(Item_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C), &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_Extended_DrumMagazine, sizeof(Item_Attach_Weapon_Magazine_Extended_DrumMagazine), &pItem_Attach_Weapon_Magazine_Extended_DrumMagazine);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_Extended_Large_C, sizeof(Item_Attach_Weapon_Magazine_Extended_Large_C), &pItem_Attach_Weapon_Magazine_Extended_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_Extended_Medium_C, sizeof(Item_Attach_Weapon_Magazine_Extended_Medium_C), &pItem_Attach_Weapon_Magazine_Extended_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_Extended_Small_C, sizeof(Item_Attach_Weapon_Magazine_Extended_Small_C), &pItem_Attach_Weapon_Magazine_Extended_Small_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_Extended_SniperRifle_C, sizeof(Item_Attach_Weapon_Magazine_Extended_SniperRifle_C), &pItem_Attach_Weapon_Magazine_Extended_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_QuickDraw_Large_C, sizeof(Item_Attach_Weapon_Magazine_QuickDraw_Large_C), &pItem_Attach_Weapon_Magazine_QuickDraw_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_QuickDraw_Medium_C, sizeof(Item_Attach_Weapon_Magazine_QuickDraw_Medium_C), &pItem_Attach_Weapon_Magazine_QuickDraw_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_QuickDraw_Small_C, sizeof(Item_Attach_Weapon_Magazine_QuickDraw_Small_C), &pItem_Attach_Weapon_Magazine_QuickDraw_Small_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C, sizeof(Item_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C), &pItem_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_SR_ExtendedQuick_Mag_Vss_setting, sizeof(Item_Attach_Weapon_Magazine_SR_ExtendedQuick_Mag_Vss_setting), &pItem_Attach_Weapon_Magazine_SR_ExtendedQuick_Mag_Vss_setting);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_SR_Extended_Mag_Vss_setting, sizeof(Item_Attach_Weapon_Magazine_SR_Extended_Mag_Vss_setting), &pItem_Attach_Weapon_Magazine_SR_Extended_Mag_Vss_setting);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Magazine_SR_QucikDraw_Magazine_Vss_setting, sizeof(Item_Attach_Weapon_Magazine_SR_QucikDraw_Magazine_Vss_setting), &pItem_Attach_Weapon_Magazine_SR_QucikDraw_Magazine_Vss_setting);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Medium_ExtendedQuickDraw_Magazine_Vector, sizeof(Item_Attach_Weapon_Medium_ExtendedQuickDraw_Magazine_Vector), &pItem_Attach_Weapon_Medium_ExtendedQuickDraw_Magazine_Vector);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Medium_Extended_Magazine_Vector, sizeof(Item_Attach_Weapon_Medium_Extended_Magazine_Vector), &pItem_Attach_Weapon_Medium_Extended_Magazine_Vector);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Medium_QuickDraw_Magazine_Vector, sizeof(Item_Attach_Weapon_Medium_QuickDraw_Magazine_Vector), &pItem_Attach_Weapon_Medium_QuickDraw_Magazine_Vector);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Choke_C, sizeof(Item_Attach_Weapon_Muzzle_Choke_C), &pItem_Attach_Weapon_Muzzle_Choke_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Compensator_Large_C, sizeof(Item_Attach_Weapon_Muzzle_Compensator_Large_C), &pItem_Attach_Weapon_Muzzle_Compensator_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Compensator_Medium_C, sizeof(Item_Attach_Weapon_Muzzle_Compensator_Medium_C), &pItem_Attach_Weapon_Muzzle_Compensator_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Compensator_SniperRifle_C, sizeof(Item_Attach_Weapon_Muzzle_Compensator_SniperRifle_C), &pItem_Attach_Weapon_Muzzle_Compensator_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Duckbill_C, sizeof(Item_Attach_Weapon_Muzzle_Duckbill_C), &pItem_Attach_Weapon_Muzzle_Duckbill_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_FlashHider_Large_C, sizeof(Item_Attach_Weapon_Muzzle_FlashHider_Large_C), &pItem_Attach_Weapon_Muzzle_FlashHider_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_FlashHider_Medium_C, sizeof(Item_Attach_Weapon_Muzzle_FlashHider_Medium_C), &pItem_Attach_Weapon_Muzzle_FlashHider_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C, sizeof(Item_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C), &pItem_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Suppressor_Large_C, sizeof(Item_Attach_Weapon_Muzzle_Suppressor_Large_C), &pItem_Attach_Weapon_Muzzle_Suppressor_Large_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Suppressor_Medium_C, sizeof(Item_Attach_Weapon_Muzzle_Suppressor_Medium_C), &pItem_Attach_Weapon_Muzzle_Suppressor_Medium_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Suppressor_Small_C, sizeof(Item_Attach_Weapon_Muzzle_Suppressor_Small_C), &pItem_Attach_Weapon_Muzzle_Suppressor_Small_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C, sizeof(Item_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C), &pItem_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_SideRail_DotSight_RMR_C, sizeof(Item_Attach_Weapon_SideRail_DotSight_RMR_C), &pItem_Attach_Weapon_SideRail_DotSight_RMR_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Stock_AR_Composite_C, sizeof(Item_Attach_Weapon_Stock_AR_Composite_C), &pItem_Attach_Weapon_Stock_AR_Composite_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Stock_Shotgun_BulletLoops_C, sizeof(Item_Attach_Weapon_Stock_Shotgun_BulletLoops_C), &pItem_Attach_Weapon_Stock_Shotgun_BulletLoops_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Stock_SniperRifle_BulletLoops_C, sizeof(Item_Attach_Weapon_Stock_SniperRifle_BulletLoops_C), &pItem_Attach_Weapon_Stock_SniperRifle_BulletLoops_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Stock_SniperRifle_CheekPad_C, sizeof(Item_Attach_Weapon_Stock_SniperRifle_CheekPad_C), &pItem_Attach_Weapon_Stock_SniperRifle_CheekPad_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Stock_UZI_C, sizeof(Item_Attach_Weapon_Stock_UZI_C), &pItem_Attach_Weapon_Stock_UZI_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_ACOG_01_C, sizeof(Item_Attach_Weapon_Upper_ACOG_01_C), &pItem_Attach_Weapon_Upper_ACOG_01_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_Aimpoint_C, sizeof(Item_Attach_Weapon_Upper_Aimpoint_C), &pItem_Attach_Weapon_Upper_Aimpoint_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_CQBSS_C, sizeof(Item_Attach_Weapon_Upper_CQBSS_C), &pItem_Attach_Weapon_Upper_CQBSS_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_DotSight_01_C, sizeof(Item_Attach_Weapon_Upper_DotSight_01_C), &pItem_Attach_Weapon_Upper_DotSight_01_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_Holosight_C, sizeof(Item_Attach_Weapon_Upper_Holosight_C), &pItem_Attach_Weapon_Upper_Holosight_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_PM2_01_C, sizeof(Item_Attach_Weapon_Upper_PM2_01_C), &pItem_Attach_Weapon_Upper_PM2_01_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_Scope3x_C, sizeof(Item_Attach_Weapon_Upper_Scope3x_C), &pItem_Attach_Weapon_Upper_Scope3x_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Upper_Scope6x_C, sizeof(Item_Attach_Weapon_Upper_Scope6x_C), &pItem_Attach_Weapon_Upper_Scope6x_C);
	LoadTextureFromMemory(device, Item_Attach_Weapon_Vector_VerGrip, sizeof(Item_Attach_Weapon_Vector_VerGrip), &pItem_Attach_Weapon_Vector_VerGrip);
	LoadTextureFromMemory(device, Item_Back_BlueBlocker, sizeof(Item_Back_BlueBlocker), &pItem_Back_BlueBlocker);
	LoadTextureFromMemory(device, Item_Back_B_01_StartParachutePack_C, sizeof(Item_Back_B_01_StartParachutePack_C), &pItem_Back_B_01_StartParachutePack_C);
	LoadTextureFromMemory(device, Item_Back_C_01_Lv3_C, sizeof(Item_Back_C_01_Lv3_C), &pItem_Back_C_01_Lv3_C);
	LoadTextureFromMemory(device, Item_Back_C_02_Lv3_C, sizeof(Item_Back_C_02_Lv3_C), &pItem_Back_C_02_Lv3_C);
	LoadTextureFromMemory(device, Item_Back_E_01_Lv1_C, sizeof(Item_Back_E_01_Lv1_C), &pItem_Back_E_01_Lv1_C);
	LoadTextureFromMemory(device, Item_Back_E_02_Lv1_C, sizeof(Item_Back_E_02_Lv1_C), &pItem_Back_E_02_Lv1_C);
	LoadTextureFromMemory(device, Item_Back_F_01_Lv2_C, sizeof(Item_Back_F_01_Lv2_C), &pItem_Back_F_01_Lv2_C);
	LoadTextureFromMemory(device, Item_Back_F_02_Lv2_C, sizeof(Item_Back_F_02_Lv2_C), &pItem_Back_F_02_Lv2_C);
	LoadTextureFromMemory(device, Item_Head_E_01_Lv1_C, sizeof(Item_Head_E_01_Lv1_C), &pItem_Head_E_01_Lv1_C);
	LoadTextureFromMemory(device, Item_Head_E_02_Lv1_C, sizeof(Item_Head_E_02_Lv1_C), &pItem_Head_E_02_Lv1_C);
	LoadTextureFromMemory(device, Item_Head_F_01_Lv2_C, sizeof(Item_Head_F_01_Lv2_C), &pItem_Head_F_01_Lv2_C);
	LoadTextureFromMemory(device, Item_Head_F_02_Lv2_C, sizeof(Item_Head_F_02_Lv2_C), &pItem_Head_F_02_Lv2_C);
	LoadTextureFromMemory(device, Item_Head_G_01_Lv3_C, sizeof(Item_Head_G_01_Lv3_C), &pItem_Head_G_01_Lv3_C);
	LoadTextureFromMemory(device, Item_Ghillie_01_C, sizeof(Item_Ghillie_01_C), &pItem_Ghillie_01_C);
	LoadTextureFromMemory(device, Item_Ghillie_02_C, sizeof(Item_Ghillie_02_C), &pItem_Ghillie_02_C);
	LoadTextureFromMemory(device, Item_Ghillie_03_C, sizeof(Item_Ghillie_03_C), &pItem_Ghillie_03_C);
	LoadTextureFromMemory(device, Item_Ghillie_04_C, sizeof(Item_Ghillie_04_C), &pItem_Ghillie_04_C);
	LoadTextureFromMemory(device, Item_Ghillie_05_C, sizeof(Item_Ghillie_05_C), &pItem_Ghillie_05_C);
	LoadTextureFromMemory(device, Item_Ghillie_06_C, sizeof(Item_Ghillie_06_C), &pItem_Ghillie_06_C);
	LoadTextureFromMemory(device, Item_Weapon_Apple_C, sizeof(Item_Weapon_Apple_C), &pItem_Weapon_Apple_C);
	LoadTextureFromMemory(device, Item_Weapon_BluezoneGrenade_C, sizeof(Item_Weapon_BluezoneGrenade_C), &pItem_Weapon_BluezoneGrenade_C);
	LoadTextureFromMemory(device, Item_Weapon_C4_C, sizeof(Item_Weapon_C4_C), &pItem_Weapon_C4_C);
	LoadTextureFromMemory(device, Item_Weapon_DecoyGrenade_C, sizeof(Item_Weapon_DecoyGrenade_C), &pItem_Weapon_DecoyGrenade_C);
	LoadTextureFromMemory(device, Item_Weapon_FlashBang_C, sizeof(Item_Weapon_FlashBang_C), &pItem_Weapon_FlashBang_C);
	LoadTextureFromMemory(device, Item_Weapon_Grenade_C, sizeof(Item_Weapon_Grenade_C), &pItem_Weapon_Grenade_C);
	LoadTextureFromMemory(device, Item_Weapon_Molotov_C, sizeof(Item_Weapon_Molotov_C), &pItem_Weapon_Molotov_C);
	LoadTextureFromMemory(device, Item_Weapon_Rock_C, sizeof(Item_Weapon_Rock_C), &pItem_Weapon_Rock_C);
	LoadTextureFromMemory(device, Item_Weapon_SmokeBomb_C, sizeof(Item_Weapon_SmokeBomb_C), &pItem_Weapon_SmokeBomb_C);
	LoadTextureFromMemory(device, Item_Weapon_Snowball_C, sizeof(Item_Weapon_Snowball_C), &pItem_Weapon_Snowball_C);
	LoadTextureFromMemory(device, Item_Weapon_SpikeTrap_C, sizeof(Item_Weapon_SpikeTrap_C), &pItem_Weapon_SpikeTrap_C);
	LoadTextureFromMemory(device, Item_Weapon_StickyGrenade_C, sizeof(Item_Weapon_StickyGrenade_C), &pItem_Weapon_StickyGrenade_C);
	LoadTextureFromMemory(device, Item_Armor_C_01_Lv3_C, sizeof(Item_Armor_C_01_Lv3_C), &pItem_Armor_C_01_Lv3_C);
	LoadTextureFromMemory(device, Item_Armor_D_01_Lv2_C, sizeof(Item_Armor_D_01_Lv2_C), &pItem_Armor_D_01_Lv2_C);
	LoadTextureFromMemory(device, Item_Armor_E_01_Lv1_C, sizeof(Item_Armor_E_01_Lv1_C), &pItem_Armor_E_01_Lv1_C);
	LoadTextureFromMemory(device, Item_Boost_AdrenalineSyringe_C, sizeof(Item_Boost_AdrenalineSyringe_C), &pItem_Boost_AdrenalineSyringe_C);
	LoadTextureFromMemory(device, Item_Boost_EnergyDrink_C, sizeof(Item_Boost_EnergyDrink_C), &pItem_Boost_EnergyDrink_C);
	LoadTextureFromMemory(device, Item_Boost_PainKiller_C, sizeof(Item_Boost_PainKiller_C), &pItem_Boost_PainKiller_C);
	LoadTextureFromMemory(device, Item_JerryCan_C, sizeof(Item_JerryCan_C), &pItem_JerryCan_C);
	LoadTextureFromMemory(device, Item_Heal_Bandage_C, sizeof(Item_Heal_Bandage_C), &pItem_Heal_Bandage_C);
	LoadTextureFromMemory(device, Item_Heal_FirstAid_C, sizeof(Item_Heal_FirstAid_C), &pItem_Heal_FirstAid_C);
	LoadTextureFromMemory(device, Item_Heal_MedKit_C, sizeof(Item_Heal_MedKit_C), &pItem_Heal_MedKit_C);
	LoadTextureFromMemory(device, Item_Weapon_DesertEagle_C, sizeof(Item_Weapon_DesertEagle_C), &pItem_Weapon_DesertEagle_C);
	LoadTextureFromMemory(device, Item_Weapon_FlareGun_C, sizeof(Item_Weapon_FlareGun_C), &pItem_Weapon_FlareGun_C);
	LoadTextureFromMemory(device, Item_Weapon_G18_C, sizeof(Item_Weapon_G18_C), &pItem_Weapon_G18_C);
	LoadTextureFromMemory(device, Item_Weapon_M1911_C, sizeof(Item_Weapon_M1911_C), &pItem_Weapon_M1911_C);
	LoadTextureFromMemory(device, Item_Weapon_M79_C, sizeof(Item_Weapon_M79_C), &pItem_Weapon_M79_C);
	LoadTextureFromMemory(device, Item_Weapon_M9_C, sizeof(Item_Weapon_M9_C), &pItem_Weapon_M9_C);
	LoadTextureFromMemory(device, Item_Weapon_NagantM1895_C, sizeof(Item_Weapon_NagantM1895_C), &pItem_Weapon_NagantM1895_C);
	LoadTextureFromMemory(device, Item_Weapon_Rhino_C, sizeof(Item_Weapon_Rhino_C), &pItem_Weapon_Rhino_C);
	LoadTextureFromMemory(device, Item_Weapon_Sawnoff_C, sizeof(Item_Weapon_Sawnoff_C), &pItem_Weapon_Sawnoff_C);
	LoadTextureFromMemory(device, Item_Weapon_vz61Skorpion_C, sizeof(Item_Weapon_vz61Skorpion_C), &pItem_Weapon_vz61Skorpion_C);
	LoadTextureFromMemory(device, Item_Weapon_AK47_C, sizeof(Item_Weapon_AK47_C), &pItem_Weapon_AK47_C);
	LoadTextureFromMemory(device, Item_Weapon_AUG_C, sizeof(Item_Weapon_AUG_C), &pItem_Weapon_AUG_C);
	LoadTextureFromMemory(device, Item_Weapon_AWM_C, sizeof(Item_Weapon_AWM_C), &pItem_Weapon_AWM_C);
	LoadTextureFromMemory(device, Item_Weapon_Berreta686_C, sizeof(Item_Weapon_Berreta686_C), &pItem_Weapon_Berreta686_C);
	LoadTextureFromMemory(device, Item_Weapon_BerylM762_C, sizeof(Item_Weapon_BerylM762_C), &pItem_Weapon_BerylM762_C);
	LoadTextureFromMemory(device, Item_Weapon_BizonPP19_C, sizeof(Item_Weapon_BizonPP19_C), &pItem_Weapon_BizonPP19_C);
	LoadTextureFromMemory(device, Item_Weapon_Crossbow_C, sizeof(Item_Weapon_Crossbow_C), &pItem_Weapon_Crossbow_C);
	LoadTextureFromMemory(device, Item_Weapon_DP12_C, sizeof(Item_Weapon_DP12_C), &pItem_Weapon_DP12_C);
	LoadTextureFromMemory(device, Item_Weapon_DP28_C, sizeof(Item_Weapon_DP28_C), &pItem_Weapon_DP28_C);
	LoadTextureFromMemory(device, Item_Weapon_FNFal_C, sizeof(Item_Weapon_FNFal_C), &pItem_Weapon_FNFal_C);
	LoadTextureFromMemory(device, Item_Weapon_G36C_C, sizeof(Item_Weapon_G36C_C), &pItem_Weapon_G36C_C);
	LoadTextureFromMemory(device, Item_Weapon_Groza_C, sizeof(Item_Weapon_Groza_C), &pItem_Weapon_Groza_C);
	LoadTextureFromMemory(device, Item_Weapon_HK416_C, sizeof(Item_Weapon_HK416_C), &pItem_Weapon_HK416_C);
	LoadTextureFromMemory(device, Item_Weapon_K2_C, sizeof(Item_Weapon_K2_C), &pItem_Weapon_K2_C);
	LoadTextureFromMemory(device, Item_Weapon_Kar98k_C, sizeof(Item_Weapon_Kar98k_C), &pItem_Weapon_Kar98k_C);
	LoadTextureFromMemory(device, Item_Weapon_L6_C, sizeof(Item_Weapon_L6_C), &pItem_Weapon_L6_C);
	LoadTextureFromMemory(device, Item_Weapon_M16A4_C, sizeof(Item_Weapon_M16A4_C), &pItem_Weapon_M16A4_C);
	LoadTextureFromMemory(device, Item_Weapon_M249_C, sizeof(Item_Weapon_M249_C), &pItem_Weapon_M249_C);
	LoadTextureFromMemory(device, Item_Weapon_M24_C, sizeof(Item_Weapon_M24_C), &pItem_Weapon_M24_C);
	LoadTextureFromMemory(device, Item_Weapon_MG3_C, sizeof(Item_Weapon_MG3_C), &pItem_Weapon_MG3_C);
	LoadTextureFromMemory(device, Item_Weapon_Mini14_C, sizeof(Item_Weapon_Mini14_C), &pItem_Weapon_Mini14_C);
	LoadTextureFromMemory(device, Item_Weapon_Mk12_C, sizeof(Item_Weapon_Mk12_C), &pItem_Weapon_Mk12_C);
	LoadTextureFromMemory(device, Item_Weapon_Mk14_C, sizeof(Item_Weapon_Mk14_C), &pItem_Weapon_Mk14_C);
	LoadTextureFromMemory(device, Item_Weapon_Mk47Mutant_C, sizeof(Item_Weapon_Mk47Mutant_C), &pItem_Weapon_Mk47Mutant_C);
	LoadTextureFromMemory(device, Item_Weapon_Mortar_C, sizeof(Item_Weapon_Mortar_C), &pItem_Weapon_Mortar_C);
	LoadTextureFromMemory(device, Item_Weapon_Mosin_C, sizeof(Item_Weapon_Mosin_C), &pItem_Weapon_Mosin_C);
	LoadTextureFromMemory(device, Item_Weapon_MP5K_C, sizeof(Item_Weapon_MP5K_C), &pItem_Weapon_MP5K_C);
	LoadTextureFromMemory(device, Item_Weapon_P90_C, sizeof(Item_Weapon_P90_C), &pItem_Weapon_P90_C);
	LoadTextureFromMemory(device, Item_Weapon_PanzerFaust100M_C, sizeof(Item_Weapon_PanzerFaust100M_C), &pItem_Weapon_PanzerFaust100M_C);
	LoadTextureFromMemory(device, Item_Weapon_QBU88_C, sizeof(Item_Weapon_QBU88_C), &pItem_Weapon_QBU88_C);
	LoadTextureFromMemory(device, Item_Weapon_QBZ95_C, sizeof(Item_Weapon_QBZ95_C), &pItem_Weapon_QBZ95_C);
	LoadTextureFromMemory(device, Item_Weapon_Saiga12_C, sizeof(Item_Weapon_Saiga12_C), &pItem_Weapon_Saiga12_C);
	LoadTextureFromMemory(device, Item_Weapon_SCAR_L_C, sizeof(Item_Weapon_SCAR_L_C), &pItem_Weapon_SCAR_L_C);
	LoadTextureFromMemory(device, Item_Weapon_SKS_C, sizeof(Item_Weapon_SKS_C), &pItem_Weapon_SKS_C);
	LoadTextureFromMemory(device, Item_Weapon_Thompson_C, sizeof(Item_Weapon_Thompson_C), &pItem_Weapon_Thompson_C);
	LoadTextureFromMemory(device, Item_Weapon_UMP_C, sizeof(Item_Weapon_UMP_C), &pItem_Weapon_UMP_C);
	LoadTextureFromMemory(device, Item_Weapon_UZI_C, sizeof(Item_Weapon_UZI_C), &pItem_Weapon_UZI_C);
	LoadTextureFromMemory(device, Item_Weapon_Vector_C, sizeof(Item_Weapon_Vector_C), &pItem_Weapon_Vector_C);
	LoadTextureFromMemory(device, Item_Weapon_VSS_C, sizeof(Item_Weapon_VSS_C), &pItem_Weapon_VSS_C);
	LoadTextureFromMemory(device, Item_Weapon_Win1894_C, sizeof(Item_Weapon_Win1894_C), &pItem_Weapon_Win1894_C);
	LoadTextureFromMemory(device, Item_Weapon_Winchester_C, sizeof(Item_Weapon_Winchester_C), &pItem_Weapon_Winchester_C);
	LoadTextureFromMemory(device, Item_Weapon_Cowbar_C, sizeof(Item_Weapon_Cowbar_C), &pItem_Weapon_Cowbar_C);
	LoadTextureFromMemory(device, Item_Weapon_Machete_C, sizeof(Item_Weapon_Machete_C), &pItem_Weapon_Machete_C);
	LoadTextureFromMemory(device, Item_Weapon_Pan_C, sizeof(Item_Weapon_Pan_C), &pItem_Weapon_Pan_C);
	LoadTextureFromMemory(device, Item_Weapon_Sickle_C, sizeof(Item_Weapon_Sickle_C), &pItem_Weapon_Sickle_C);

}