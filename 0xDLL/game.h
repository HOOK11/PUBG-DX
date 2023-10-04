#pragma once
#include "obfuscation.h"
//bool WriteProtectMemory(UINT64 ptr, PVOID buff, ULONG size);
enum ETraceTypeQuery
{
	TraceTypeQuery1 = 0,
	TraceTypeQuery2 = 1,
	TraceTypeQuery3 = 2,
	TraceTypeQuery4 = 3,
	TraceTypeQuery5 = 4,
	TraceTypeQuery6 = 5,
	TraceTypeQuery7 = 6,
	TraceTypeQuery8 = 7,
	TraceTypeQuery9 = 8,
	TraceTypeQuery10 = 9,
	TraceTypeQuery11 = 10,
	TraceTypeQuery12 = 11,
	TraceTypeQuery13 = 12,
	TraceTypeQuery14 = 13,
	TraceTypeQuery15 = 14,
	TraceTypeQuery16 = 15,
	TraceTypeQuery17 = 16,
	TraceTypeQuery18 = 17,
	TraceTypeQuery19 = 18,
	TraceTypeQuery20 = 19,
	TraceTypeQuery21 = 20,
	TraceTypeQuery22 = 21,
	TraceTypeQuery23 = 22,
	TraceTypeQuery24 = 23,
	TraceTypeQuery25 = 24,
	TraceTypeQuery26 = 25,
	TraceTypeQuery27 = 26,
	TraceTypeQuery28 = 27,
	TraceTypeQuery29 = 28,
	TraceTypeQuery30 = 29,
	TraceTypeQuery31 = 30,
	TraceTypeQuery32 = 31,
	TraceTypeQuery_MAX = 32,
	ETraceTypeQuery_MAX = 33
};
enum EDrawDebugTrace
{
	EDrawDebugTrace__None = 0,
	EDrawDebugTrace__ForOneFrame = 1,
	EDrawDebugTrace__ForDuration = 2,
	EDrawDebugTrace__Persistent = 3,
	EDrawDebugTrace__EDrawDebugTrace_MAX = 4
};
struct FHitResult
{
	unsigned char                                      _0x000000[0x88];
};
struct FLinearColor
{
	float                                              R;
	float                                              G;
	float                                              B;
	float                                              A;

	inline FLinearColor()
		: R(0), G(0), B(0), A(0)
	{ }

	inline FLinearColor(float r, float g, float b, float a)
		: R(r),
		G(g),
		B(b),
		A(a)
	{ }

};
enum Bones : int
{
	Root = 0,
	pelvis,
	spine_01,
	spine_02,
	spine_03,
	neck_01,
	Head,
	face_root,
	eyebrows_pos_root,
	eyebrows_root,
	eyebrows_r,
	eyebrows_l,
	eyebrow_l,
	eyebrow_r,
	forehead_root,
	forehead,
	jaw_pos_root = 26,
	jaw_root,
	jaw,
	mouth_down_pos_root,
	mouth_down_root,
	lip_bm_01,
	lip_bm_02,
	lip_br,
	lip_bl,
	jaw_01,
	jaw_02,
	cheek_pos_root,
	cheek_root,
	cheek_r,
	cheek_l,
	nose_sIDe_root,
	nose_sIDe_r_01,
	nose_sIDe_r_02,
	nose_sIDe_l_01,
	nose_sIDe_l_02,
	eye_pos_r_root,
	eye_r_root,
	eye_rot_r_root,
	eye_lID_u_r,// 39,
	eye_r,// 40,
	eye_lID_b_r,// 41,
	eye_pos_l_root,// 42,
	eye_l_root,// 43,
	eye_rot_l_root,// 44,
	eye_lID_u_l,// 45,
	eye_l,// 46,
	eye_lID_b_l,// 47,
	nose_pos_root,// 48,
	nose,// 49,
	mouth_up_pos_root,// 50,
	mouth_up_root,// 51,
	lip_ul,// 52,
	lip_um_01,// 53,
	lip_um_02,// 54,
	lip_ur,// 55,
	lip_l,// 56,
	lip_r,// 57,
	hair_root,// 58,
	hair_b_01,// 59,
	hair_b_02,// 60,
	hair_l_01,// 61,
	hair_l_02,// 62,
	hair_r_01,// 63,
	hair_r_02,// 64,
	hair_f_02,// 65,
	hair_f_01,// 66,
	hair_b_pt_01,// 67,
	hair_b_pt_02,// 68,
	hair_b_pt_03,// 69,
	hair_b_pt_04,// 70,
	hair_b_pt_05,// 71,
	camera_fpp,// 72,
	GunReferencePoint,// 73,
	GunRef,// 74,
	breast_l,// 75,
	breast_r,// 76,
	clavicle_l,// 77,
	upperarm_l,// 78,
	lowerarm_l,// 79,
	hand_l,// 80,
	thumb_01_l,// 81,
	thumb_02_l,// 82,
	thumb_03_l,// 83,
	thumb_04_l_MBONLY,// 84,
	index_01_l,// 85,
	index_02_l,// 86,
	index_03_l,// 87,
	index_04_l_MBONLY,// 88,
	mIDdle_01_l,// 89,
	mIDdle_02_l,// 90,
	mIDdle_03_l,// 91,
	mIDdle_04_l_MBONLY,// 92,
	ring_01_l,// 93,
	ring_02_l,// 94,
	ring_03_l,// 95,
	ring_04_l_MBONLY,// 96,
	pinky_01_l,// 97,
	pinky_02_l,// 98,
	pinky_03_l,// 99,
	pinky_04_l_MBONLY,// 100,
	item_l,// 101,
	lowerarm_twist_01_l,// 102,
	upperarm_twist_01_l,// 103,
	clavicle_r,// 104,
	upperarm_r,// 105,
	lowerarm_r,// 106,
	hand_r,// 107,
	thumb_01_r,// 108,
	thumb_02_r,// 109,
	thumb_03_r,// 110,
	thumb_04_r_MBONLY,// 111,
	index_01_r,// 112,
	index_02_r,// 113,
	index_03_r,// 114,
	index_04_r_MBONLY,// 115,
	mIDdle_01_r,// 116,
	mIDdle_02_r,// 117,
	mIDdle_03_r,// 118,
	mIDdle_04_r_MBONLY,// 119,
	ring_01_r,// 120,
	ring_02_r,// 121,
	ring_03_r,// 122,
	ring_04_r_MBONLY,// 123,
	pinky_01_r,// 124,
	pinky_02_r,// 125,
	pinky_03_r,// 126,
	pinky_04_r_MBONLY,// 127,
	item_r,// 128,
	lowerarm_twist_01_r,// 129,
	upperarm_twist_01_r,// 130,
	BackPack,// 131,
	backpack_01,// 132,
	backpack_02,// 133,
	Slot_Primary,// 134,
	Slot_Secondary,// 135,
	Slot_Melee,// 136,
	slot_throwable,// 137,
	coat_l_01,// 138,
	coat_l_02,// 139,
	coat_l_03,// 140,
	coat_l_04,// 141,
	coat_fl_01,// 142,
	coat_fl_02,// 143,
	coat_fl_03,// 144,
	coat_fl_04,// 145,
	coat_b_01,// 146,
	coat_b_02,// 147,
	coat_b_03,// 148,
	coat_b_04,// 149,
	coat_r_01,// 150,
	coat_r_02,// 151,
	coat_r_03,// 152,
	coat_r_04,// 153,
	coat_fr_01,// 154,
	coat_fr_02,// 155,
	coat_fr_03,// 156,
	coat_fr_04,// 157,
	thigh_l,// 158,
	calf_l,// 159,
	foot_l,// 160,
	ball_l,// 161,
	calf_twist_01_l,// 162,
	thigh_twist_01_l,// 163,
	thigh_r,// 164,
	calf_r,// 165,
	foot_r,// 166,
	ball_r,// 167,
	calf_twist_01_r,// 168,
	thigh_twist_01_r,// 169,
	Slot_SIDeArm,// 170,
	skirt_l_01,// 171,
	skirt_l_02,// 172,
	skirt_l_03,// 173,
	skirt_f_01,// 174,
	skirt_f_02,// 175,
	skirt_f_03,// 176,
	skirt_b_01,// 177,
	skirt_b_02,// 178,
	skirt_b_03,// 179,
	skirt_r_01,// 180,
	skirt_r_02,
	skirt_r_03,
	ik_hand_root,
	ik_hand_gun,
	ik_hand_r,
	ik_hand_l,
	ik_aim_root,
	ik_aim_l,
	ik_aim_r,
	ik_foot_root,
	ik_foot_l,
	ik_foot_r,
	camera_tpp,
	ik_target_root,
	ik_target_l,
	ik_target_r,
	VB_spine_03_spine_03,
	VB_upperarm_r_lowerarm_r
};
int AimBotBone[28] = {
	Bones::spine_03, Bones::forehead_root, Bones::face_root, Bones::Head, Bones::neck_01, Bones::spine_02, Bones::spine_01, Bones::pelvis,
	Bones::upperarm_r, Bones::lowerarm_r, Bones::hand_r, Bones::index_01_r,
	Bones::upperarm_l, Bones::lowerarm_l, Bones::hand_l, Bones::index_01_l,
	Bones::thigh_r, Bones::thigh_twist_01_r, Bones::calf_r, Bones::calf_twist_01_r, Bones::foot_r, Bones::ball_r,
	Bones::thigh_l, Bones::thigh_twist_01_l, Bones::calf_l, Bones::calf_twist_01_l, Bones::foot_l, Bones::ball_l
};
typedef bool(__thiscall* LineTraceSingle_t)(void* pUworld, Vector3 Start, Vector3 End, ETraceTypeQuery TraceChannel, bool bTraceComplex, void* ActorsToIgnore, EDrawDebugTrace DrawDebugType, FHitResult* Outhit, bool bIgnoreSelf, FLinearColor TraceColor, FLinearColor TraceHitColor, float DrawTime);
LineTraceSingle_t pfnLineTraceSingle = NULL;

bool Isitvisible(Vector3 StartPos, Vector3 EndPos) {
	if (pfnLineTraceSingle == NULL)
		pfnLineTraceSingle = reinterpret_cast<LineTraceSingle_t>(ȫ��::ģ���ַ + _LineTraceSingle);
	FHitResult OutHit = {};
	return !pfnLineTraceSingle((void*)GameData::�����ַ, StartPos, EndPos, TraceTypeQuery1, true, (void*)GameData::����ָ��, EDrawDebugTrace__None, &OutHit, true, FLinearColor(), FLinearColor(), 0.f);
}


BOOL UpdateBase()
{
	// DbgPrint("====================== UpdateBase ======================");
	GameData::����״̬ = Memory::Read<ULONG>(ȫ��::ģ���ַ + _�жϴ���); if (GameData::����״̬ == 1) { return false; }
	//DbgPrint("����״̬��%11X\t%d", ȫ��::ģ���ַ + _�жϴ���, GameData::����״̬);
	GameData::�����ַ = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(ȫ��::ģ���ַ + _Uworld)); if (Memory::ValidPtr(GameData::�����ַ, sizeof(ULONG_PTR))) return false;
	//DbgPrint("�����ַ��%llX", GameData::�����ַ);
	GameData::����һ�� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::�����ַ + _Leve1)); if (Memory::ValidPtr(GameData::����һ��, sizeof(ULONG_PTR))) return false;
	//DbgPrint("����һ����%llX", GameData::����һ��);
	GameData::����һ�� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::�����ַ + _GameInstence)); if (Memory::ValidPtr(GameData::����һ��, sizeof(ULONG_PTR))) return false;
	//DbgPrint("����һ����%llX", GameData::����һ��);
	GameData::���˶��� = Memory::Read<ULONG_PTR>(GameData::����һ�� + _LocalPlayer); if (Memory::ValidPtr(GameData::���˶���, sizeof(ULONG_PTR))) return false;
	//DbgPrint("���˶�����%llX", GameData::���˶���);
	GameData::�������� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::���˶���)); if (Memory::ValidPtr(GameData::��������, sizeof(ULONG_PTR))) return false;
	//DbgPrint("����������%llX", GameData::��������);
	GameData::�����ļ� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::�������� + _PlayerController)); if (Memory::ValidPtr(GameData::�����ļ�, sizeof(ULONG_PTR))) return false;
	//DbgPrint("�����ļ���%llX", GameData::�����ļ�);
	GameData::���ֵ�ַ = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(ȫ��::ģ���ַ + _GNames)); if (Memory::ValidPtr(GameData::���ֵ�ַ, sizeof(ULONG_PTR))) return false;
	//DbgPrint("���ֵ�ַ��%llX", GameData::���ֵ�ַ);
	GameData::����ƫ�� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::���ֵ�ַ)); 	if (Memory::ValidPtr(GameData::����ƫ��, sizeof(ULONG_PTR))) return false;
	//DbgPrint("����ƫ�ƣ�%llX", GameData::����ƫ��);
	GameData::����ָ�� = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::����һ�� + _Actor)); if (Memory::ValidPtr(GameData::����ָ��, sizeof(ULONG_PTR))) return false;
	//DbgPrint("����ָ�룺%llX", GameData::����ָ��);
	GameData::��ʼָ�� = Memory::Read<ULONG_PTR>(GameData::����ָ��); if (Memory::ValidPtr(GameData::��ʼָ��, sizeof(ULONG_PTR))) return false;
	//DbgPrint("��ʼָ�룺%llX", GameData::��ʼָ��);
	GameData::�������� = Memory::Read<ULONG>(GameData::����ָ�� + 0x08); if (GameData::�������� < 100 || GameData::�������� > 9999) return false;
	//DbgPrint("����������%d", GameData::��������);
	GameData::����״̬ = Memory::Read<ULONG>(ȫ��::ģ���ַ + _����״̬);
	return true;//*��������
}
BOOL UpdateCamera()
{
	GameData::ͶӰ��� = Memory::Read<ULONG_PTR>(GameData::�����ļ� + _PlayerCameraManager);
	// DbgPrint("ͶӰ�����%llX", GameData::ͶӰ���);
	if (Memory::ValidPtr(GameData::ͶӰ���, sizeof(ULONG_PTR))) return FALSE;
	GameData::CameraCacheData.POV.FOV = Memory::Read<FLOAT>(GameData::ͶӰ��� + _CameraFov);
	GameData::CameraCacheData.POV.Location = Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos);
	GameData::CameraCacheData.POV.Rotation = Memory::Read<FRotator>(GameData::ͶӰ��� + _CameraRot);
	return TRUE;
}

BOOL UpdateLocalPlayer() {
	ULONG_PTR PlayerPawn = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::�����ļ� + _AcknowledgedPawn));
	if (!Memory::ValidPtr(PlayerPawn, sizeof(ULONG_PTR))) {
		//if (GameData::LoaclPlayerData.PlayerPawn != PlayerPawn && GameData::LoaclPlayerData.PlayerPawn != NULL) {
		//	DbgPrint("�������飺%llX\t%11X", PlayerPawn, GameData::LoaclPlayerData.PlayerPawn);
		//}
		GameData::LoaclPlayerData.PlayerPawn = PlayerPawn;
	}
	GameData::LoaclPlayerData.InVehicle = FALSE;
	// DbgPrint("�������飺%llX", GameData::��������);
	for (ULONG i = 0; i < GameData::��������; i++)
	{
		ULONG_PTR EntityPtr = Memory::Read<ULONG_PTR>(GameData::��ʼָ�� + (static_cast<unsigned long long>(i) * 8)); if (Memory::ValidPtr(EntityPtr, sizeof(ULONG_PTR))) continue;
		ULONG EntityObjID = Decrypt::DecryptObjectID(Memory::Read<ULONG>(EntityPtr + _ObjID)); if (!EntityObjID || EntityObjID > 1000000) continue;
		EntityNameIDTypeMap EntityObjName = FindEntityObjName(EntityObjID); if (EntityObjName.Type == EntityType::Unknowns) continue;
		//DbgPrint("EntityObjName��%s", EntityObjName.Name);
		//PCSTR EntityObjName = CacheGNamesForID(EntityObjID); if (!EntityObjName)  continue;
		if (EntityObjName.Type == EntityType::Player) {
			ULONG_PTR PlayerVehicleComponent = Memory::Read<ULONG_PTR>(EntityPtr + _VehicleRiderComponent);
			ULONG_PTR PlayerVehiclePawn = Memory::Read<ULONG_PTR>(PlayerVehicleComponent + _LastVehiclePawn);

			if (!Memory::ValidPtr(PlayerVehiclePawn, sizeof(ULONG_PTR)) && PlayerVehiclePawn == GameData::LoaclPlayerData.PlayerPawn) {
				//DbgPrint("�����ӽǣ�%llX,%llX", GameData::LoaclPlayerData.PlayerPawn, EntityPtr);
				GameData::LoaclPlayerData.PlayerPawn = EntityPtr; // �����ӽ�
				GameData::LoaclPlayerData.InVehicle = TRUE;
				break;
			}

			if (Memory::ValidPtr(PlayerPawn, sizeof(ULONG_PTR))) {
				ULONG_PTR EntityRootComponent = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(EntityPtr + _m_rootComponent)); if (Memory::ValidPtr(EntityRootComponent, sizeof(ULONG_PTR))) { continue; }
				Vector3 EntityWorldLocation = Memory::Read<Vector3>(EntityRootComponent + _Position_);
				FLOAT EntityDistance = (EntityWorldLocation - GameData::CameraCacheData.POV.Location).Length() / 100.0f;
				if (EntityDistance <= 2.0f) {
					//DbgPrint("�����ӽǣ�%llX,%llX,%.0f", GameData::LoaclPlayerData.PlayerPawn, EntityPtr, EntityDistance);
					GameData::LoaclPlayerData.PlayerPawn = EntityPtr; // �����ӽ�
					break;
				}
			}
		}
	}
	if (Memory::ValidPtr(GameData::LoaclPlayerData.PlayerPawn, sizeof(ULONG_PTR))) return FALSE;
	GameData::LoaclPlayerData.Team = Memory::Read<ULONG>(GameData::LoaclPlayerData.PlayerPawn + _TeamNumber);
	GameData::LoaclPlayerData.Mesh = Memory::Read<ULONG_PTR>(GameData::LoaclPlayerData.PlayerPawn + _Mesh); if (Memory::ValidPtr(GameData::LoaclPlayerData.Mesh, sizeof(ULONG_PTR))) return FALSE;
	GameData::LoaclPlayerData.AnimScript = Memory::Read<ULONG_PTR>(GameData::LoaclPlayerData.Mesh + _AnimScriptInstance); if (Memory::ValidPtr(GameData::LoaclPlayerData.AnimScript, sizeof(ULONG_PTR))) return FALSE;
	ULONG_PTR EntityRootComponent = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(GameData::LoaclPlayerData.PlayerPawn + _m_rootComponent)); if (Memory::ValidPtr(EntityRootComponent, sizeof(ULONG_PTR))) { return FALSE; }
	GameData::LoaclPlayerData.WorldLocation = Memory::Read<Vector3>(EntityRootComponent + _Position_);
	Vector3 Sway = Memory::Read<Vector3>(GameData::LoaclPlayerData.AnimScript + _ControlRotation_CP);
	Vector3 Recoil = Memory::Read<Vector3>(GameData::LoaclPlayerData.AnimScript + _RecoilADSRotation_CP);
	GameData::CameraCacheDataForAimbot.POV.FOV = GameData::CameraCacheData.POV.FOV;
	GameData::CameraCacheDataForAimbot.POV.Location = GameData::CameraCacheData.POV.Location;
	GameData::CameraCacheDataForAimbot.POV.Rotation = FRotator{ Sway.x + Recoil.x, Sway.y + Recoil.y,Sway.z + Recoil.z };
	return TRUE;
}
BOOL UpdateLocalWeapon()
{
	Memory::RtlZeroMemoryEx((BYTE*)&GameData::LoaclWeaponData, sizeof(GameData::LoaclWeaponData));
	ULONG_PTR WeaponProcessor = Memory::Read<ULONG_PTR>(GameData::LoaclPlayerData.PlayerPawn + _WeaponProcessor); if (Memory::ValidPtr(WeaponProcessor, sizeof(ULONG_PTR))) return TRUE;
	ULONG_PTR EquippedWeapons = Memory::Read<ULONG_PTR>(WeaponProcessor + _EquippedWeapons); if (Memory::ValidPtr(EquippedWeapons, sizeof(ULONG_PTR))) return TRUE;
	BYTE WeaponIndex = Memory::Read<BYTE>(WeaponProcessor + _CurrentWeaponIndex); if (WeaponIndex < 0 || WeaponIndex > 4) return TRUE;
	ULONG_PTR LocalWeaponPtr = Memory::Read<ULONG_PTR>(EquippedWeapons + (WeaponIndex * 8)); if (Memory::ValidPtr(LocalWeaponPtr, sizeof(ULONG_PTR))) return TRUE;
	ULONG_PTR WeaponTrajectoryData = Memory::Read<ULONG_PTR>(LocalWeaponPtr + _WeaponTrajectoryData); if (Memory::ValidPtr(WeaponTrajectoryData, sizeof(ULONG_PTR))) return TRUE;
	ULONG WeaponObjID = Decrypt::DecryptObjectID(Memory::Read<ULONG>(LocalWeaponPtr + _ObjID)); if (WeaponObjID <= 0 && WeaponObjID >= 1000000) return TRUE;
	EntityNameIDTypeMap EntityObjName = FindEntityObjName(WeaponObjID);
	GameData::LoaclWeaponData.WeaponName = EntityObjName.Name;
	GameData::LoaclWeaponData.TrajectoryGravityZ = Memory::Read<FLOAT>(LocalWeaponPtr + _TrajectoryGravityZ);
	GameData::LoaclWeaponData.TrajectoryConfig = Memory::Read<FWeaponTrajectoryConfig>(WeaponTrajectoryData + _TrajectoryConfig);
	GameData::LoaclWeaponData.WeaponInitialSpeed = GetAimSpeed();
	GameData::LoaclWeaponData.WeaponBullet = Memory::Read<ULONG>(LocalWeaponPtr + _�ӵ�����);
	GameData::LoaclWeaponData.WeaponHold = TRUE;
	return TRUE;
}
EntityNameIDTypeMap GetPlayerHoldWeapon(ULONG_PTR PlayerPawn)
{
	ULONG_PTR WeaponProcessor = Memory::Read<ULONG_PTR>(PlayerPawn + _WeaponProcessor); if (Memory::ValidPtr(WeaponProcessor, sizeof(ULONG_PTR))) return EntityNameIDTypeMap(EntityType::Unknowns, "");
	// Draw::TextEx(10, 0 * 24 + 10.f, ImVec4(1.f, 1.f, 1.f, 0.85f), 22.f, u8"WeaponProcessor��%llX", WeaponProcessor);
	ULONG_PTR EquippedWeapons = Memory::Read<ULONG_PTR>(WeaponProcessor + _EquippedWeapons); if (Memory::ValidPtr(EquippedWeapons, sizeof(ULONG_PTR))) return EntityNameIDTypeMap(EntityType::Unknowns, "");
	// Draw::TextEx(10, 1 * 24 + 10.f, ImVec4(1.f, 1.f, 1.f, 0.85f), 22.f, u8"EquippedWeapons��%llX", EquippedWeapons);
	BYTE WeaponIndex = Memory::Read<BYTE>(WeaponProcessor + _CurrentWeaponIndex); if (WeaponIndex < 0 || WeaponIndex > 4) return EntityNameIDTypeMap(EntityType::Unknowns, "");
	// Draw::TextEx(10, 2 * 24 + 10.f, ImVec4(1.f, 1.f, 1.f, 0.85f), 22.f, u8"WeaponIndex��%d", WeaponIndex);  
	ULONG_PTR LocalWeaponPtr = Memory::Read<ULONG_PTR>(EquippedWeapons + (WeaponIndex * 8)); if (Memory::ValidPtr(LocalWeaponPtr, sizeof(ULONG_PTR))) return EntityNameIDTypeMap(EntityType::Unknowns, "");
	// Draw::TextEx(10, 3 * 24 + 10.f, ImVec4(1.f, 1.f, 1.f, 0.85f), 22.f, u8"LocalWeaponPtr��%llX", LocalWeaponPtr);
	ULONG WeaponObjID = Decrypt::DecryptObjectID(Memory::Read<ULONG>(LocalWeaponPtr + _ObjID)); if (WeaponObjID <= 0 && WeaponObjID >= 1000000) return EntityNameIDTypeMap(EntityType::Unknowns, "");
	// Draw::TextEx(10, 4 * 24 + 10.f, ImVec4(1.f, 1.f, 1.f, 0.85f), 22.f, u8"WeaponObjID��%d", WeaponObjID);
	EntityNameIDTypeMap EntityObjName = FindEntityObjName(WeaponObjID); if (EntityObjName.Type == EntityType::Unknowns) { return EntityNameIDTypeMap(EntityType::Unknowns, ""); };
	return EntityObjName;
}
VOID DrawPlayerBone(ULONG_PTR Mesh, ImVec4 Color, FLOAT Width, BOOL �Ƿ����)
{
	Vector3 NeckPosition = GetBonePosition(Mesh, Bone::����);
	Vector3 WaistPosition = GetBonePosition(Mesh, Bone::����);
	Vector3 previous, current;
	Vector2 p1, c1;
	for (auto i : Bone::ƴ�ӹ���)
	{
		previous = Vector3(0, 0, 0);
		for (int bone : i)
		{
			current = bone == Bone::���� ? NeckPosition : (bone == Bone::���� ? WaistPosition : GetBonePosition(Mesh, bone));
			if (previous.x == 0.f)
			{
				previous = current;
				continue;
			}
			ImVec4 ColorTemp = �Ƿ���� && Isitvisible(Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos), GameData::CameraCacheData.POV.Location) ? Color : Menu::���͸��::͸����ɫ::������;
			p1 = WorldToScreen(previous);
			c1 = WorldToScreen(current);
			Draw::Line(p1.x, p1.y, c1.x, c1.y, Color, Width);
			previous = current;
		}
	}
}
VOID DrawPlayerInfo(EntityNameIDTypeMap PlayerHoldWeapon, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, DWORD TeamColor, ImVec4 ͸����ɫ, FLOAT PlayerHealth, Vector2 PlayerHeadScreenPosition, ULONG PlayerKill, ULONG PlayerTeam, const string& PlayerName) {
	FLOAT HealthMaxWidth = 80.0f - EntityDistance / (12.0f + EntityDistance / 100.0f * 8.0f);
	FLOAT IntervalWidth = 20.0f - EntityDistance / 15.0f;
	IntervalWidth = IntervalWidth < 15.0f ? 15.0f : IntervalWidth;
	FLOAT HealthX = PlayerHeadScreenPosition.x - (HealthMaxWidth / 2.0f);
	FLOAT HealthY = PlayerHeadScreenPosition.y - IntervalWidth + 5.0f;
	FLOAT HealthWidth = (HealthMaxWidth * (PlayerHealth / 100.f));
	HealthWidth = HealthWidth < 1 ? 1 : HealthWidth;

	char PlayerTeamStr[4]; sprintf_s(PlayerTeamStr, PlayerTeam == 0 || EntityObjName.Type == EntityType::AI ? "AI" : "%2d", (int)PlayerTeam);

	if (PlayerHoldWeapon.ICON != NULL) {
		Draw::Image(PlayerHoldWeapon.ICON, PlayerHeadScreenPosition.x, HealthY - 26, HealthMaxWidth, 28, ImVec4(255.f, 255.f, 255.f, 0.75f));
	}

	Draw::FilledRect(HealthX - 2, HealthY - 22, HealthMaxWidth + 4, 28, YColor(TeamColor, 0.50f));
	Draw::TextMaxWidth(HealthX + 3, HealthY - 21.f, HealthMaxWidth - 6, Menu::���͸��::͸����ɫ::���, 16.f, u8"%s", PlayerName.c_str());

	Draw::FilledRect(HealthX - 33, HealthY - 22, 30, 28, YColor(TeamColor, 0.50f));
	Draw::TextCenter(HealthX - (PlayerTeam >= 10 ? 15.0f : 18.0), HealthY - 18.5f, Menu::���͸��::͸����ɫ::���, 20.f, u8"%s", PlayerTeamStr);


	Draw::FilledRect(HealthX + HealthMaxWidth + 3, HealthY - 22, 30, 28, YColor(TeamColor, 0.50f));
	Draw::TextCenter(HealthX + HealthMaxWidth + (PlayerKill >= 10 ? 18.5f : 16.5f), HealthY - 18.5f, PlayerKill >= 4 ? Menu::���͸��::͸����ɫ::Ԥ�� : Menu::���͸��::͸����ɫ::���, 22.f, u8"%2d", PlayerKill);

	Draw::Line(HealthX, HealthY, HealthX + HealthMaxWidth, HealthY, YColor(0x000000, 0.35f), 6);
	Draw::Line(HealthX, HealthY, HealthX + HealthWidth, HealthY, ͸����ɫ, 6);
}
VOID DrawVehicle(ULONG_PTR EntityPtr, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, Vector2 EntityScreenLocation, BOOL SkipValidation = FALSE) {
	if (((Menu::�ؾ�͸��::͸�ӿ���::����͸�� && EntityDistance <= Menu::�ؾ�͸��::͸�Ӳ���::͸����Ч����) || SkipValidation) && EntityDistance >= 1.f)
	{
		//if (EntityObjName.PNG_ID != NULL) {
		//	Draw::Image(EntityObjName.PNG_ID, EntityScreenLocation.x - 48, EntityScreenLocation.y - 64, 96, 64);
		//	Draw::TextExCenter(EntityScreenLocation.x, EntityScreenLocation.y, Menu::�ؾ�͸��::͸�Ӳ���::͸����ɫ, 22.f, u8"[%.0f]", EntityDistance);
		//}
		for (ULONG i = 0; i < GameData::DrawOverlay::VehicleList.size(); i++) {
			if (GameData::DrawOverlay::VehicleList[i] == EntityPtr) {
				return;
			}
		}
		FLOAT EntityScreenDistance = sqrtf(powf(EntityScreenLocation.x - g_d3dViewPort.TopLeftX, 2) + powf(EntityScreenLocation.y - g_d3dViewPort.TopLeftY, 2));
		Draw::TextCenterEx(EntityScreenLocation.x, EntityScreenLocation.y, Menu::�ؾ�͸��::͸�Ӳ���::͸����ɫ, 16.f, u8"%s[%.0f]", EntityObjName.Name, EntityDistance);
		GameData::DrawOverlay::VehicleList.push_back(EntityPtr);
	}
}
double Radians(double Angle)
{
	return (Angle * 0.01745329251994);
}

VOID DrawPlayer(ULONG_PTR EntityPtr, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, Vector3 EntityWorldLocation, Vector2 EntityScreenLocation) {
	if (Menu::���͸��::͸�ӿ���::����͸�� == true && EntityDistance >= 1.f && EntityDistance <= Menu::���͸��::͸�Ӳ���::͸����Ч����)
	{
		ULONG_PTR PlayerMesh = Memory::Read<ULONG_PTR>(EntityPtr + _Mesh); if (Memory::ValidPtr(PlayerMesh, sizeof(ULONG_PTR)) || PlayerMesh == GameData::LoaclPlayerData.Mesh) { return; }
		ULONG PlayerTeam = Memory::Read<ULONG>(EntityPtr + _TeamNumber) % 10000; if (PlayerTeam == GameData::LoaclPlayerData.Team && !Menu::��������::���鿪��::��������) { return; } if (PlayerTeam <= 0 || PlayerTeam >= 10000) { PlayerTeam = 0; }
		FLOAT PlayerHealth = Memory::Read<FLOAT>(EntityPtr + _Health);
		FLOAT PlayerHealthDie = Memory::Read<FLOAT>(EntityPtr + _Health_Die);
		if ((PlayerHealth + PlayerHealthDie <= 0.f || PlayerHealth + PlayerHealthDie > 200.f)) { return; }
		BOOL PlayerDie = PlayerHealth <= 0.f || PlayerHealth > 100.f;
		PlayerHealth = PlayerDie ? PlayerHealthDie : PlayerHealth;

		DWORD TeamColor = GetTeamColor(EntityObjName.Type == EntityType::AI ? 0 : PlayerTeam);

		ULONG_PTR PlayerState = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(EntityPtr + _PlayerState)); //if (Memory::ValidPtr(PlayerState, sizeof(ULONG_PTR))) { continue; }
		LPCWCH PlayerNamePtr = Memory::Read<LPCWCH>(EntityPtr + _Playname); if (Memory::ValidPtr((ULONG_PTR)PlayerNamePtr, sizeof(ULONG_PTR))) { return; }
		CHAR PlayerName[64];
		WideCharToMultiByte(CP_ACP, 0, PlayerNamePtr, -1, PlayerName, WideCharToMultiByte(CP_ACP, 0, PlayerNamePtr, -1, NULL, 0, NULL, NULL), NULL, NULL);
		ULONG PlayerKill = PlayerState == 0 ? 0 : Memory::Read<ULONG>(PlayerState + _PlayerSatisitc); PlayerKill = PlayerKill >= 0 && PlayerKill <= 99 ? PlayerKill : 0;

		Vector3 PlayerHeadWorldPosition = GetBonePosition(PlayerMesh, Bone::ͷ��);
		Vector2 PlayerHeadScreenPosition = WorldToScreen(PlayerHeadWorldPosition);
		Vector3 PlayerWaistWorldPosition = GetBonePosition(PlayerMesh, Bone::�ŵ�);
		Vector2 PlayerWaistScreenPosition = WorldToScreen(PlayerWaistWorldPosition);

		if (Menu::���͸��::͸�ӿ���::Σ��Ԥ��) { // ������ʾ
			Vector3 AimFov = ����Ƕ�(EntityWorldLocation, GameData::LoaclPlayerData.WorldLocation);
			Vector3 AngDelta = Memory::Read<Vector3>(EntityPtr + _����ƫ��);
			FRotator AmiMz = FRotator(AngDelta.x, AngDelta.y, AngDelta.z);
			AmiMz.Clamp();
			int32_t AimX = int32_t(abs(AimFov.x - AmiMz.Yaw));
			int32_t AimY = int32_t(abs(AimFov.y - AmiMz.Pitch));
			if (AimX <= 2 && AimY <= 2)
			{
				Draw::Line(EntityScreenLocation.x, EntityScreenLocation.y, g_d3dViewPort.Width / 2, g_d3dViewPort.Height / 2, Menu::���͸��::͸����ɫ::Ԥ��, 1);
			}
		}

		if (Menu::���͸��::͸�ӿ���::�״� == true) {
			FLOAT ���˳��� = Memory::Read<FLOAT>(GameData::LoaclPlayerData.PlayerPawn + _���ﳯ��);
			FLOAT ���˳��� = Memory::Read<FLOAT>(EntityPtr + _���ﳯ��);
			float Distance = 0.f;
			ULONG_PTR ObjectMesh = Memory::Read<ULONG_PTR>(EntityPtr + _Mesh);
			ULONG Team = Memory::Read<ULONG>(EntityPtr + _TeamNumber);
			ULONG myteam = Memory::Read<ULONG>(GameData::LoaclPlayerData.PlayerPawn + _MyTeam);
			Vector3 Pos = GetBonePosition(ObjectMesh, Bone::ͷ��);
			Vector3 MyPos = GetBonePosition(GameData::LoaclPlayerData.Mesh, Bone::ͷ��);

			Distance = (MyPos - Pos).Length() / 100.f;
			ULONG DistanceFW = (ULONG)(MyPos - Pos).Length() / 100.0f;
			if (myteam != Team)
			{

				Vector3 Mpostion = Memory::Read<Vector3>(Memory::Read<ULONG_PTR>(GameData::LoaclPlayerData.PlayerPawn + _Mesh) + _Position_);
				Vector3 postion = Memory::Read<Vector3>(Memory::Read<ULONG_PTR>(EntityPtr + _Mesh) + _Position_);
				/*Vector3 Location = Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos);*/
				DOUBLE iMapPosScreenX, iMapPosScreenY;
				ULONG MapColor;
				float x = ImGui::GetIO().DisplaySize.x;
				float y = ImGui::GetIO().DisplaySize.y;
				ULONG ��ͼ�ж� = Memory::Read<ULONG>(GameData::�����ļ� + _��ͼ�ж�);
				float MapRadio;
				string Mapname = CacheGNamesForID(Decrypt::DecryptObjectID(Memory::Read<ULONG>(GameData::�����ַ + _ObjID)));
				if (Mapname == XorString("Range_Main"))//ѵ����Range_Main
				{
					MapRadio = 140.0f;
				}
				if (Mapname == XorString("Baltic_Main"))//���׸�Baltic_Main
				{
					MapRadio = 564.5f;
				}
				if (Mapname == XorString("Desert_Main"))//ɳĮDesert_Main
				{
					MapRadio = 564.5f;
				}
				if (Mapname == XorString("Savage_Main"))//����Savage_Main
				{
					MapRadio = 281.0f;
				}
				if (Mapname == XorString("DihorOtok_Main"))//ѩ�� DihorOtok_Main
				{
					MapRadio = 424.9f;
				}
				if (Mapname == XorString("Chimera_Main"))//����Ī Chimera_Main  
				{
					MapRadio = 211.0f;
				}
				if (Mapname == XorString("Summerland_Main"))//������  Summerland_Main
				{
					MapRadio = 140.0f;
				}
				if (Mapname == XorString("Tiger_Main"))// Tiger_Main 
				{
					MapRadio = 564.0f;
				}
				int X = Memory::Read<ULONG>(GameData::�����ַ + _����תС��ͼ);
				int Y = Memory::Read<ULONG>(GameData::�����ַ + _����תС��ͼ + 0x4);
				Vector3 Mpos = Vector3((float)X, (float)Y, 0);
				Vector3 MYPOS = GetBonePosition(ObjectMesh, Bone::ͷ��);
				MYPOS = MYPOS + Mpos;
				char buffinfo[64];
				if (��ͼ�ж� == 3 || ��ͼ�ж� == 75)
				{
					if (ImGui::GetIO().DisplaySize.x <= 1920 || ImGui::GetIO().DisplaySize.y <= 1080)
					{
						ImVec2 mmmm = ImVec2(MYPOS.x / (MapRadio * 1.3342f) + 420.f, MYPOS.y / (MapRadio * 1.3342f));//140   141.5fѵ����    564.5  564.5 ���׸�/ɳĮ     281.0f   281.0f����  424.9f 424.9f ѩ��
						Draw::CircleFilled(mmmm.x, mmmm.y, 6, YColor(0xFF0000, 0.80f), 100);
						Draw::Line(mmmm.x, mmmm.y, mmmm.x + cos(Radians(���˳���)) * 9, mmmm.y + sin(Radians(���˳���)) * 15, YColor(0xFF0000, 0.80f), 1);
					}
					else
					{
						ImVec2 mmmm = ImVec2(MYPOS.x / MapRadio + 560.f, MYPOS.y / MapRadio);//140   141.5fѵ����    564.5  564.5 ���׸�/ɳĮ     281.0f   281.0f����  424.9f 424.9f ѩ��
						Draw::CircleFilled(mmmm.x, mmmm.y, 6, YColor(0xFF0000, 0.80f), 100);
						Draw::Line(mmmm.x, mmmm.y, mmmm.x + cos(Radians(���˳���)) * 9, mmmm.y + sin(Radians(���˳���)) * 15, YColor(0xFF0000, 0.80f), 1);

					}

				}

				if (EntityDistance <= 200.f)
				{
					if (ImGui::GetIO().DisplaySize.x <= 1920 || ImGui::GetIO().DisplaySize.y <= 1080)
					{
						iMapPosScreenX = (postion.x - Mpostion.x) / 158.f + x - x * 0.08542f;
						iMapPosScreenY = (postion.y - Mpostion.y) / 158.f + y - y * 0.14444f;
					}
					else
					{
						iMapPosScreenX = (postion.x - Mpostion.x) / 117.f + x - x * 0.08542f;
						iMapPosScreenY = (postion.y - Mpostion.y) / 117.f + y - y * 0.14444f;
					}
					Draw::CircleFilled(iMapPosScreenX - 4, iMapPosScreenY - 4, 6, YColor(0xFF0000, 0.80f), 100);
				}
			}


		}

		if (EntityScreenLocation.x < 1.0f || EntityScreenLocation.x > g_d3dViewPort.Width || EntityScreenLocation.y < 1.0f || EntityScreenLocation.y > g_d3dViewPort.Height)
		{
			GameData::DrawOverlay::ä����������++;
			if (EntityDistance < GameData::DrawOverlay::������� || GameData::DrawOverlay::������� == 0)
			{
				GameData::DrawOverlay::������� = EntityDistance;
			}
			return;
		}
		
		
		ULONG LoaclPlayerMeshEyes = Memory::Read<ULONG>(GameData::LoaclPlayerData.Mesh + _Eyes);
		ULONG PlayerMeshEyes = Memory::Read<ULONG>(PlayerMesh + _Eyes);

		BOOL �Ƿ���� = PlayerMeshEyes >= LoaclPlayerMeshEyes;

		ImVec4 ����͸����ɫ = PlayerDie ? Menu::���͸��::͸����ɫ::���� : Menu::���͸��::͸����ɫ::���;
		/*ImVec4 ����͸����ɫ = PlayerDie ? Menu::���͸��::͸����ɫ::���� : �Ƿ���� ? Menu::���͸��::͸����ɫ::��� : Menu::���͸��::͸����ɫ::������;*/
		if (Menu::���͸��::͸�ӿ���::���� == true)
		{
			DrawPlayerBone(PlayerMesh, ����͸����ɫ, Menu::���͸��::͸�Ӳ���::�����������, �Ƿ����);
		}
		if (Menu::���͸��::͸�ӿ���::��ϸ��Ϣ == true)
		{
			DrawPlayerInfo(GetPlayerHoldWeapon(EntityPtr), EntityObjName, EntityDistance, TeamColor, ����͸����ɫ, PlayerHealth, PlayerHeadScreenPosition, PlayerKill, PlayerTeam, PlayerName);

		}
		
		
		ULONG_PTR PlayerVehicleComponent = Memory::Read<ULONG_PTR>(EntityPtr + _VehicleRiderComponent);
		ULONG_PTR PlayerVehiclePawn = Memory::Read<ULONG_PTR>(PlayerVehicleComponent + _LastVehiclePawn);

		if (Memory::ValidPtr(PlayerVehiclePawn, sizeof(ULONG_PTR))) {
			FLOAT IntervalWidth = 20 - EntityDistance / 15;
			IntervalWidth = IntervalWidth < 15 ? 15 : IntervalWidth;
			//Draw::FilledRect(PlayerHeadScreenPosition.x - 6, PlayerWaistScreenPosition.y - 4, 12, 8, YColor(TeamColor, .50f));
			if (Menu::���͸��::͸�ӿ���::��ϸ��Ϣ == true)
			{
				Draw::TextCenterEx(PlayerHeadScreenPosition.x, PlayerWaistScreenPosition.y + IntervalWidth - 15, ����͸����ɫ, 18.f, u8"[%.0f]", EntityDistance);
				ULONG Audience = Memory::Read<ULONG>(EntityPtr + _Audience);
				if (Audience < 100 && Audience > 0)
				{
					if (Audience < 0)
					{
						Audience = 0;
					}
					Draw::TextCenterEx(PlayerHeadScreenPosition.x, PlayerWaistScreenPosition.y + IntervalWidth + 10, ����͸����ɫ, 18.f, u8"��ս��%d", Audience);
					/*return;*/
			}
			
			}
		}
		else
		{
			do {
				for (ULONG i = 0; i < GameData::DrawOverlay::VehicleList.size(); i++) {
					if (GameData::DrawOverlay::VehicleList[i] == PlayerVehiclePawn) {
						continue;
					}
				}
				ULONG VehicleEntityObjID = Decrypt::DecryptObjectID(Memory::Read<ULONG>(PlayerVehiclePawn + _ObjID)); if (!VehicleEntityObjID || VehicleEntityObjID > 1000000) { continue; }
				EntityNameIDTypeMap VehicleEntityObjName = FindEntityObjName(VehicleEntityObjID); if (VehicleEntityObjName.Type == EntityType::Unknowns) { continue; }
				ULONG_PTR VehicleEntityRootComponent = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(PlayerVehiclePawn + _m_rootComponent)); if (Memory::ValidPtr(VehicleEntityRootComponent, sizeof(ULONG_PTR))) { continue; }
				Vector3 VehicleEntityWorldLocation = Memory::Read<Vector3>(VehicleEntityRootComponent + _Position_);
				FLOAT VehicleEntityDistance = (VehicleEntityWorldLocation - GameData::CameraCacheData.POV.Location).Length() / 100.0f; if (VehicleEntityDistance <= 2.f || VehicleEntityDistance > 2000.f) { continue; }
				Vector2 VehicleEntityScreenLocation = WorldToScreen(VehicleEntityWorldLocation);
				DrawVehicle(PlayerVehiclePawn, VehicleEntityObjName, VehicleEntityDistance, VehicleEntityScreenLocation, TRUE);
			} while (FALSE);
		}


	}
}
BOOL DrawItem(ULONG PackageItemObjID, OUT Vector3* ItemScreenLocation, FLOAT EntityDistance) {
	EntityNameIDTypeMap PackageEntityObjName = FindEntityObjName(PackageItemObjID); if (PackageEntityObjName.Type == EntityType::Unknowns) { return false; }
	ImVec4 ͸����ɫ;
	if (PackageEntityObjName.Follow) { if (Menu::����͸��::͸�ӿ���::����) ͸����ɫ = Menu::����͸��::͸����ɫ::����; else return false; }
	else if (PackageEntityObjName.Type == EntityType::Weapon) { if (Menu::����͸��::͸�ӿ���::����) ͸����ɫ = Menu::����͸��::͸����ɫ::����; else return false; }
	else if (PackageEntityObjName.Type == EntityType::Accessories) { if (Menu::����͸��::͸�ӿ���::���) ͸����ɫ = Menu::����͸��::͸����ɫ::���; else return false; }
	else if (PackageEntityObjName.Type == EntityType::Drug) { if (Menu::����͸��::͸�ӿ���::ҽ��) ͸����ɫ = Menu::����͸��::͸����ɫ::ҽ��; else return false; }
	else if (PackageEntityObjName.Type == EntityType::Armor) { if (Menu::����͸��::͸�ӿ���::����) ͸����ɫ = Menu::����͸��::͸����ɫ::����; else return false; }
	else if (PackageEntityObjName.Type == EntityType::Grenade) { if (Menu::����͸��::͸�ӿ���::Ͷ��) ͸����ɫ = Menu::����͸��::͸����ɫ::Ͷ��; else return false; }
	else return false;

	if (Menu::ȫ������::ͼ��ģʽ) {
		if (PackageEntityObjName.ICON == NULL) return false;
		Draw::ImageEx(PackageEntityObjName.ICON, ItemScreenLocation->x, ItemScreenLocation->y, 48, 48, ImVec4(͸����ɫ.x, ͸����ɫ.y, ͸����ɫ.z, 0.5f));
		if (EntityDistance > 1.0f) Draw::TextCenterEx(ItemScreenLocation->x + 48, ItemScreenLocation->y - 28, ͸����ɫ, 16.f, u8"[%.0f]", EntityDistance);
	}
	else {
		if (EntityDistance > 1.0f) ItemScreenLocation->z = Draw::TextCenterEx(ItemScreenLocation->x, ItemScreenLocation->y, ͸����ɫ, 18.f, u8"%s[%.0f]", PackageEntityObjName.Name, EntityDistance);
		else {
			FLOAT ItemScreenLocationX = ItemScreenLocation->z > 0.0f ? ItemScreenLocation->z : ItemScreenLocation->x;
			Draw::TextEx(ItemScreenLocationX, ItemScreenLocation->y, ͸����ɫ, 16.f, u8"|%s", PackageEntityObjName.Name);
		}
	}

	return true;
}
BOOL DrawItem(ULONG PackageItemObjID, Vector2 ItemScreenLocation, FLOAT EntityDistance) {
	FLOAT ItemScreenLocationX = ItemScreenLocation.x;
	FLOAT ItemScreenLocationY = ItemScreenLocation.y;
	Vector3 ItemScreenLocation3 = Vector3(ItemScreenLocationX, ItemScreenLocationY, 0.0f);
	ItemScreenLocation3 = ������Ʒ(ItemScreenLocation3);
	EntityDistance = ItemScreenLocationX != ItemScreenLocation3.x || ItemScreenLocationY != ItemScreenLocation3.y ? 0 : EntityDistance;
	if (DrawItem(PackageItemObjID, &ItemScreenLocation3, EntityDistance)) {
		GameData::DrawOverlay::ItemList.push_back(ItemScreenLocation3);
		return true;
	}
	return false;

}
VOID DrawBox(ULONG_PTR EntityPtr, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, Vector2 EntityScreenLocation) {
	if ((EntityObjName.Type == EntityType::AirPack && Menu::����͸��::͸�ӿ���::��Ͷ && EntityDistance <= Menu::����͸��::͸�Ӳ���::��Ͷ)
		|| (EntityObjName.Type == EntityType::DeadBox && Menu::����͸��::͸�ӿ���::ʬ�� && EntityDistance <= Menu::����͸��::͸�Ӳ���::ʬ��)) {
		ULONG_PTR PackageItemArray = Memory::Read<ULONG_PTR>(EntityPtr + _Packge - 8); if (Memory::ValidPtr(PackageItemArray, sizeof(ULONG_PTR))) { return; }
		ULONG PackageItemCount = Memory::Read<ULONG>(EntityPtr + _Packge); if (PackageItemCount < 0 || PackageItemCount > 100) return;
		FLOAT EntityScreenLocationX = 0;
		FLOAT EntityScreenLocationY = 0;
		if (EntityObjName.Type == EntityType::AirPack && EntityObjName.ICON != NULL) {
			EntityScreenLocationY = Menu::ȫ������::ͼ��ģʽ ? 24 : 0;
			if (Menu::ȫ������::ͼ��ģʽ) Draw::Image(EntityObjName.ICON, EntityScreenLocation.x, EntityScreenLocation.y, 32, 32);
			EntityScreenLocationX = Draw::TextCenterEx(EntityScreenLocation.x, EntityScreenLocation.y - EntityScreenLocationY, Menu::����͸��::͸����ɫ::��Ͷ, 16.f, u8"%s[%.0f]", EntityObjName.Name, EntityDistance);
		}
		else if (EntityObjName.Type == EntityType::DeadBox && EntityObjName.ICON != NULL) {
			EntityScreenLocationY = Menu::ȫ������::ͼ��ģʽ ? 48 : 0;
			if (Menu::ȫ������::ͼ��ģʽ) Draw::Image(EntityObjName.ICON, EntityScreenLocation.x, EntityScreenLocation.y, 120, 80);
			EntityScreenLocationX = Draw::TextCenterEx(EntityScreenLocation.x, EntityScreenLocation.y - EntityScreenLocationY, Menu::����͸��::͸����ɫ::ʬ��, 16.f, u8"%s[%.0f]", EntityObjName.Name, EntityDistance);
		}
		int n = 1;
		for (ULONG_PTR i = 0; i < PackageItemCount; i++)
		{
			ULONG_PTR PackageItemPtr = Memory::Read<ULONG_PTR>(PackageItemArray + i * 0x08); if (Memory::ValidPtr(PackageItemPtr, sizeof(ULONG_PTR))) { continue; }
			ULONG PackageItemObjID = Memory::Read<ULONG>(Memory::Read<ULONG_PTR>(PackageItemPtr + _��Ʒһ) + _��Ʒ��); if (!PackageItemObjID || PackageItemObjID > 1000000) continue;
			Vector3 ItemScreenLocation = Vector3(EntityScreenLocation.x, EntityScreenLocation.y - EntityScreenLocationY - n * 18.f, EntityScreenLocationX);
			if (DrawItem(PackageItemObjID, &ItemScreenLocation, 0.f)) n++;
		}
	}
	
}
VOID DrawDropItem(ULONG_PTR EntityPtr, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, Vector2 EntityScreenLocation) {
	if (Menu::����͸��::͸�ӿ���::����͸�� && EntityDistance >= 1.f && EntityDistance <= Menu::����͸��::͸�Ӳ���::͸����Ч����) {
		ULONG_PTR PackageItemPtr = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(EntityPtr + _DroppedItem)); if (Memory::ValidPtr(PackageItemPtr, sizeof(ULONG_PTR))) { return; }
		ULONG PackageItemObjID = Memory::Read<ULONG>(Memory::Read<ULONG_PTR>(PackageItemPtr + _��Ʒһ) + _��Ʒ��); if (!PackageItemObjID || PackageItemObjID > 1000000) { return; }
		//EntityNameIDTypeMap PackageEntityObjName = FindEntityObjName(PackageItemObjID);
		DrawItem(PackageItemObjID, EntityScreenLocation, EntityDistance);
	}
}
VOID DrawDroppedItemGroup(ULONG_PTR EntityPtr, EntityNameIDTypeMap EntityObjName, FLOAT EntityDistance, Vector2 EntityScreenLocation) {
	if (Menu::����͸��::͸�ӿ���::����͸��) {
		ULONG_PTR DroppedItemArray = Memory::Read<ULONG_PTR>(EntityPtr + _DroppedItemGroup); if (Memory::ValidPtr(DroppedItemArray, sizeof(ULONG_PTR))) { return; }
		// DbgPrint("DroppedItemArray��%llX", DroppedItemArray);
		ULONG DroppedItemCount = Memory::Read<ULONG>(EntityPtr + _DroppedItemGroup_Count); if (DroppedItemCount < 0 || DroppedItemCount > 100) return;
		// DbgPrint("DroppedItemCount��%llX", DroppedItemCount);
		for (ULONG_PTR i = 0; i < DroppedItemCount; i++)
		{
			ULONG_PTR DroppedItemPtr = Memory::Read<ULONG_PTR>(DroppedItemArray + i * 0x10); if (Memory::ValidPtr(DroppedItemPtr, sizeof(ULONG_PTR))) { continue; }
			Vector3 DroppedItemWorldLocation = Memory::Read<Vector3>(DroppedItemPtr + _Position_);
			Vector2 DroppedItemScreenLocation = WorldToScreen(DroppedItemWorldLocation);
			FLOAT DroppedItemDistance = (DroppedItemWorldLocation - GameData::CameraCacheData.POV.Location).Length() / 100.0f; if (DroppedItemDistance < 1.f || DroppedItemDistance > Menu::����͸��::͸�Ӳ���::͸����Ч����) { continue; }
			ULONG_PTR DroppedItemObj = Memory::Read<ULONG_PTR>(DroppedItemPtr + _DroppedItemGroup_UItem); if (Memory::ValidPtr(DroppedItemObj, sizeof(ULONG_PTR))) { continue; }
			ULONG DroppedItemObjID = Memory::Read<ULONG>(Memory::Read<ULONG_PTR>(DroppedItemObj + _��Ʒһ) + _��Ʒ��); if (!DroppedItemObjID || DroppedItemObjID > 1000000) { continue; }
			DrawItem(DroppedItemObjID, DroppedItemScreenLocation, DroppedItemDistance);
		}
		
	}

}
VOID PushAimbot(ULONG_PTR EntityPtr, ULONG_PTR EntityRootComponent, FLOAT EntityDistance) {
	if (Menu::��������::���鿪��::�������� && GameData::����״̬ != 1 && GameData::LoaclWeaponData.WeaponHold && GameData::LoaclPlayerData.InVehicle == FALSE)
	{
		FLOAT PlayerHealth = Memory::Read<FLOAT>(EntityPtr + _Health);
		FLOAT PlayerHealthDie = Memory::Read<FLOAT>(EntityPtr + _Health_Die);
		if ((PlayerHealth + PlayerHealthDie <= 0.f || PlayerHealth + PlayerHealthDie > 200.f)) { return; }
		BOOL PlayerDie = PlayerHealth <= 0.f || PlayerHealth > 100.f;

		if (PlayerDie && Menu::��������::���鿪��::�������� == FALSE) return;

		ULONG PlayerTeam = Memory::Read<ULONG>(EntityPtr + _TeamNumber) % 10000; if (PlayerTeam == GameData::LoaclPlayerData.Team && !Menu::��������::���鿪��::��������) { return; }
		ULONG_PTR PlayerMesh = Memory::Read<ULONG_PTR>(EntityPtr + _Mesh); if (Memory::ValidPtr(PlayerMesh, sizeof(ULONG_PTR)) || PlayerMesh == GameData::LoaclPlayerData.Mesh) { return; }
		ULONG PlayerMeshEyes = Memory::Read<ULONG>(PlayerMesh + _Eyes);
		ULONG LoaclPlayerMeshEyes = Memory::Read<ULONG>(GameData::LoaclPlayerData.Mesh + _Eyes);
		BOOL �Ƿ����;// = PlayerMeshEyes >= LoaclPlayerMeshEyes; if (�Ƿ���� == FALSE) return;
		ULONG_PTR PlayerVehicleComponent = Memory::Read<ULONG_PTR>(EntityPtr + _VehicleRiderComponent);
		ULONG_PTR  PPP = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(EntityPtr + _ActorRootComp));
		INT PlayerVehicleSeat = Memory::ValidPtr(PlayerMesh, sizeof(ULONG_PTR)) ? -1 : Memory::Read<INT>(PlayerVehicleComponent + _SeatIndex);
		Vector3 PlayerVelocity = (PlayerVehicleSeat == -1 ? Memory::Read<Vector3>(PPP + _Veloctity)
			: Memory::Read<Vector3>(Memory::Read<ULONG_PTR>(PlayerVehicleComponent + _LastVehiclePawn) + _ReplicatedMovement));
		Vector3 PlayerVelocityUp = (PlayerVehicleSeat == -1 ? Memory::Read<Vector3>(PPP + _Veloctity - 0x28)
			: Memory::Read<Vector3>(Memory::Read<ULONG_PTR>(PlayerVehicleComponent + _LastVehiclePawn) + _ReplicatedMovement - 0x28));


		Vector3 HeadWorldPosition;
		if (GameData::NtUserGetAsyncKeyState(VK_SHIFT))
		{
			HeadWorldPosition = GetBonePosition(PlayerMesh, Bone::ͷ��);
			�Ƿ���� = Isitvisible(Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos), HeadWorldPosition);
		}
		else
		{
			HeadWorldPosition = GetBonePosition(PlayerMesh, GameData::NtUserGetAsyncKeyState(VK_SHIFT) ? 15 : 4);
			for (int i = 0; i < 28; i++)
			{
				if (GameData::NtUserGetAsyncKeyState(VK_SHIFT))
				{
					HeadWorldPosition = GetBonePosition(PlayerMesh, 15);
					if (Isitvisible(Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos), HeadWorldPosition))
					{
						�Ƿ���� = true;
						break;
					}
				}
				HeadWorldPosition = GetBonePosition(PlayerMesh, AimBotBone[i]);
				if (Isitvisible(Memory::Read<Vector3>(GameData::ͶӰ��� + _CameraPos), HeadWorldPosition))
				{
					�Ƿ���� = true;
					break;
				}
				else
					�Ƿ���� = false;
			}
		}
		if (!�Ƿ����) return;
		Vector3 Predicted = PredictedPosition(PlayerVelocity, PlayerVelocityUp, EntityDistance);
		Vector3 HeadWorldLocation = HeadWorldPosition + Predicted;
		Vector2 HeadScreenPosition = WorldToScreenForAimbot(HeadWorldLocation);
		FLOAT ScreenDistance = sqrtf(powf(HeadScreenPosition.x - g_d3dViewPort.TopLeftX, 2) + powf(HeadScreenPosition.y - g_d3dViewPort.TopLeftY, 2));
		if (GameData::AimbotEntityPtr == EntityPtr || ScreenDistance <= Menu::��������::�������::���鷶Χ) {
			Aim::AimEntityPtrList.push_back(EntityPtr);
			Aim::AimDistanceList.push_back(GameData::AimbotEntityPtr == EntityPtr ? 0 : EntityDistance + ScreenDistance * 10);
			Aim::AimPositionList.push_back(HeadScreenPosition);
		}
	}
}


VOID EntityWhile()
{
	if (UpdateBase() && UpdateCamera() && UpdateLocalPlayer() && UpdateLocalWeapon()) {
		GameData::DrawOverlay::VehicleList.clear(); // ���Ƴ���
		GameData::DrawOverlay::ItemList.clear(); // ��������
		GameData::DrawOverlay::������� = 0; GameData::DrawOverlay::ä���������� = 0;
		if (Menu::��������::���鿪��::��������)
		{
			Aim::AimEntityPtrList.clear();
			Aim::AimDistanceList.clear();
			Aim::AimPositionList.clear();
		}
		if (Menu::���͸��::͸�ӿ���::��ս) {
			ULONG Audience = Memory::Read<ULONG>(GameData::LoaclPlayerData.PlayerPawn + _Audience);
			if (Audience < 100 && Audience > 0) {
				Draw::TextEx(10, 30, Menu::���͸��::͸����ɫ::Ԥ��, 22.f, u8"��ս������%d", Audience);
			}
		}
		for (ULONG i = 0; i < GameData::��������; i++)
		{
			ULONG_PTR EntityPtr = Memory::Read<ULONG_PTR>(GameData::��ʼָ�� + (static_cast<unsigned long long>(i) * 8)); if (Memory::ValidPtr(EntityPtr, sizeof(ULONG_PTR))) { continue; }
			ULONG EntityObjID = Decrypt::DecryptObjectID(Memory::Read<ULONG>(EntityPtr + _ObjID)); if (!EntityObjID || EntityObjID > 1000000) { continue; }
			EntityNameIDTypeMap EntityObjName = FindEntityObjName(EntityObjID); if (EntityObjName.Type == EntityType::Unknowns) { continue; }

			ULONG_PTR EntityRootComponent = Decrypt::DecryptPtr(Memory::Read<ULONG_PTR>(EntityPtr + _m_rootComponent)); if (Memory::ValidPtr(EntityRootComponent, sizeof(ULONG_PTR))) { continue; }
			Vector3 EntityWorldLocation = Memory::Read<Vector3>(EntityRootComponent + _Position_);
			FLOAT EntityDistance = (EntityWorldLocation - GameData::CameraCacheData.POV.Location).Length() / 100.0f; if (EntityDistance <= 2.f || EntityDistance > 2000.f) { continue; }
			Vector2 EntityScreenLocation = WorldToScreen(EntityWorldLocation);

			if (EntityObjName.Type == EntityType::Player || EntityObjName.Type == EntityType::AI) {
				DrawPlayer(EntityPtr, EntityObjName, EntityDistance, EntityWorldLocation, EntityScreenLocation);
				PushAimbot(EntityPtr, EntityRootComponent, EntityDistance);
			}
			if (EntityObjName.Type == EntityType::Vehicle && (
				strcmp(EntityObjName.Name, u8"��Ͷ�ɻ�A") == 0 
				|| strcmp(EntityObjName.Name, u8"��Ͷ�ɻ�S") == 0
				|| strcmp(EntityObjName.Name, u8"��Ͷ�ɻ�T") == 0 
				|| strcmp(EntityObjName.Name, u8"��Ͷ�ɻ�R") == 0
				|| strcmp(EntityObjName.Name, u8"��Ͷ�ɻ�C") == 0)) {
				DrawVehicle(EntityPtr, EntityObjName, EntityDistance, EntityScreenLocation, TRUE);
			}

			if (Menu::ȫ������::Ԥ������)
			{
				if (EntityObjName.Type == EntityType::toudan)
				{
					if (EntityDistance < 100.f)
					{
						Draw::CircleFilled(EntityScreenLocation.x, EntityScreenLocation.y, 5.f, EntityDistance < 20.f ? YColor(0xFF0000, 0.75f) : (EntityDistance < 40.f ? YColor(0xFF4500, 0.75f) : YColor(0xFF4500, 0.75f)), 100);

						Draw::TextEx(EntityScreenLocation.x + 10.f, EntityScreenLocation.y - 15.f / 2, EntityDistance < 20.f ? YColor(0xFF0000, 0.75f) : (EntityDistance < 40.f ? YColor(0xFF4500, 0.75f) : YColor(0xFF4500, 0.75f)), 15.f, "%.0fm", EntityDistance);
					}

					continue;
				}
			}
			if (Menu::ȫ������::ս��ģʽ) continue;
			if (EntityObjName.Type == EntityType::Vehicle) DrawVehicle(EntityPtr, EntityObjName, EntityDistance, EntityScreenLocation);
			if (EntityObjName.Type == EntityType::AirPack || EntityObjName.Type == EntityType::DeadBox) DrawBox(EntityPtr, EntityObjName, EntityDistance, EntityScreenLocation);
			if (EntityObjName.Type == EntityType::DropItem) DrawDropItem(EntityPtr, EntityObjName, EntityDistance, EntityScreenLocation);
			if (EntityObjName.Type == EntityType::DroppedItemGroup) DrawDroppedItemGroup(EntityPtr, EntityObjName, EntityDistance, EntityScreenLocation);
			
			
		}

		if (Menu::���͸��::͸�ӿ���::Σ��Ԥ�� && GameData::DrawOverlay::ä���������� > 0) {
			Draw::TextCenterEx(g_d3dViewPort.Width / 2, g_d3dViewPort.Height - 200, Menu::���͸��::͸����ɫ::Ԥ��, 22.f, u8"ä������������%d | ������룺%.0f", GameData::DrawOverlay::ä����������, GameData::DrawOverlay::�������);
		}


		if (Menu::��������::���鿪��::�������� == true && GameData::����״̬ != 1)
		{
			do {
				SIZE_T ListLen = Aim::AimDistanceList.size();
				if (ListLen > 0)
				{
					ULONG MinIndex = 0;
					FLOAT MinDistance = Aim::AimDistanceList[0];
					for (ULONG ListIndex = 1; ListIndex < ListLen; ListIndex++)
					{
						if (Aim::AimDistanceList[ListIndex] < MinDistance)
						{
							MinDistance = Aim::AimDistanceList[ListIndex];
							MinIndex = ListIndex;
						}
					}
					
				



					if (GameData::NtUserGetAsyncKeyState(VK_RBUTTON) != 0)
					{
						GameData::AimbotEntityPtr = Aim::AimEntityPtrList[MinIndex];

						Aim::AimPositionList[MinIndex].x = (Aim::AimPositionList[MinIndex].x - g_d3dViewPort.TopLeftX) * 0.01 * Menu::��������::�������::�����ٶ�;
						Aim::AimPositionList[MinIndex].y = (Aim::AimPositionList[MinIndex].y - g_d3dViewPort.TopLeftY) * 0.01 * Menu::��������::�������::�����ٶ�;
						INPUT input;
						input.type = 0;
						input.mi.dx = Aim::AimPositionList[MinIndex].x;
						input.mi.dy = Aim::AimPositionList[MinIndex].y;
						input.mi.dwFlags = 1;

						GameData::NtUserSendInput(1, &input, sizeof(INPUT));


						/*SmoothingAimbot(Aim::AimPositionList[MinIndex]);*/
						break;
					}
				}
				GameData::AimbotEntityPtr = 0;
			} while (FALSE);
		}
	}
	else {
		GameData::LoaclPlayerData.PlayerPawn = 0;
	}
	if (Menu::��������::���鿪��::������׼) {
		Draw::Line(g_d3dViewPort.TopLeftX - 20, g_d3dViewPort.TopLeftY, g_d3dViewPort.TopLeftX + 20, g_d3dViewPort.TopLeftY, Menu::���͸��::͸����ɫ::׼��, 2);
		Draw::Line(g_d3dViewPort.TopLeftX, g_d3dViewPort.TopLeftY - 20, g_d3dViewPort.TopLeftX, g_d3dViewPort.TopLeftY + 20, Menu::���͸��::͸����ɫ::׼��, 2);
	}


}