#pragma once
using namespace std;

typedef enum : ULONG
{
	Unknowns = 0,// 未知
	Player, // 玩家
	AI, //  AI
	DropItem, // 掉落物品
	DroppedItemGroup, // 刷新物品
	Item, // 普通物品
	Vehicle, // 汽车
	Drug, // 药物
	Armor, // 防具
	toudan,
	Accessories, // 配件
	Weapon, // 手持武器
	AirPack,// 空投
	DeadBox, // 死亡盒子
	Grenade, // 投掷物品
}EntityType, * PEntityType;

typedef struct EntityNameIDTypeMap
{
	EntityType Type;
	const char* Name;
	bool Follow;
	PICON ICON;
	EntityNameIDTypeMap() :Type(EntityType::Unknowns), Name(""), ICON(NULL), Follow(false) {}
	EntityNameIDTypeMap(EntityType type, const char* name) :Type(type), Name(name), ICON(NULL), Follow(false) {}
	EntityNameIDTypeMap(EntityType type, const char* name, const bool follow) :Type(type), Name(name), ICON(NULL), Follow(follow) {}
	EntityNameIDTypeMap(EntityType type, const char* name, PICON icon) :Type(type), Name(name), ICON(icon), Follow(false) {}
	EntityNameIDTypeMap(EntityType type, const char* name, PICON icon, const bool follow) :Type(type), Name(name), ICON(icon), Follow(follow) {}
}*PEntityNameIDTypeMap;

struct Vector2
{
public:
	Vector2() : x(0.f), y(0.f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	float x;
	float y;

	Vector2 operator+(Vector2 v)
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 operator-(Vector2 v)
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator*(float v)
	{
		return Vector2(x * v, y * v);
	}

	Vector2 operator/(float v)
	{
		return Vector2(x / v, y / v);
	}
};

struct Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f) {}

	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x;
	float y;
	float z;

	inline Vector3 ToFRotator()
	{
		float RADPI = (float)(180 / 3.1415926f);
		float Yaw = (float)atan2f(y, x) * RADPI;
		float Pitch = (float)atan2f(z, sqrtf(powf(x, 2) + powf(y, 2))) * RADPI;
		float Roll = 0;
		return Vector3(Pitch, Yaw, Roll);
	}

	inline float Dot(Vector3 v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v)
	{
		return float(sqrtf(powf(v.x - x, 2) + powf(v.y - y, 2) + powf(v.z - z, 2)));
	}

	inline float Length()
	{
		return float(sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2)));
	}

	Vector3 operator+(Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(Vector3 v)
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	Vector3 operator/(Vector3 v)
	{
		return Vector3(x / v.x, y / v.y, z / v.z);
	}
};
struct Vector4
{
public:
	Vector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}

	Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

	float x;
	float y;
	float z;
	float w;
};
#ifndef D3DMATRIX_DEFINED
typedef struct _D3DMATRIX {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};
} D3DMATRIX;
#define D3DMATRIX_DEFINED
#endif
struct FRotator
{
public:
	FRotator() : Pitch(0.f), Yaw(0.f), Roll(0.f) {}

	FRotator(float _pitch, float _yaw, float _roll) : Pitch(_pitch), Yaw(_yaw), Roll(_roll) {}

	~FRotator() {}

	float Pitch;
	float Yaw;
	float Roll;

	inline double Length()
	{
		return sqrtf(powf(Pitch, 2.0) + powf(Yaw, 2.0) + powf(Roll, 2.0));
	};

	void Clamp()
	{
		if (Pitch > 180)
			Pitch -= 360;

		else if (Pitch < -180)
			Pitch += 360;

		if (Yaw > 180)
			Yaw -= 360;

		else if (Yaw < -180)
			Yaw += 360;

		if (Pitch < -89)
			Pitch = -89;

		if (Pitch > 89)
			Pitch = 89;

		while (Yaw < -180.0f)
			Yaw += 360.0f;

		while (Yaw > 180.0f)
			Yaw -= 360.0f;

		Roll = 0;
		return;
	}

	Vector3 ToVector()
	{
		float radPitch = (float)(Pitch * 3.1415926f / 180.f);
		float radYaw = (float)(Yaw * 3.1415926f / 180.f);

		float SP = (float)sinf(radPitch);
		float CP = (float)cosf(radPitch);
		float SY = (float)sinf(radYaw);
		float CY = (float)cosf(radYaw);

		return  Vector3(CP * CY, CP * SY, SP);
	}

	D3DMATRIX GetAxes()
	{
		auto tempMatrix = Matrix();
		return tempMatrix;
	}

	D3DMATRIX Matrix(Vector3 origin = Vector3(0, 0, 0))
	{
		float radPitch = (Pitch * 3.1415926f / 180.f);
		float radYaw = (Yaw * 3.1415926f / 180.f);
		float radRoll = (Roll * 3.1415926f / 180.f);
		float SP = sinf(radPitch);
		float CP = cosf(radPitch);
		float SY = sinf(radYaw);
		float CY = cosf(radYaw);
		float SR = sinf(radRoll);
		float CR = cosf(radRoll);

		D3DMATRIX matrix;
		matrix.m[0][0] = CP * CY;
		matrix.m[0][1] = CP * SY;
		matrix.m[0][2] = SP;
		matrix.m[0][3] = 0.f;

		matrix.m[1][0] = SR * SP * CY - CR * SY;
		matrix.m[1][1] = SR * SP * SY + CR * CY;
		matrix.m[1][2] = -SR * CP;
		matrix.m[1][3] = 0.f;

		matrix.m[2][0] = -(CR * SP * CY + SR * SY);
		matrix.m[2][1] = CY * SR - CR * SP * SY;
		matrix.m[2][2] = CR * CP;
		matrix.m[2][3] = 0.f;

		matrix.m[3][0] = origin.x;
		matrix.m[3][1] = origin.y;
		matrix.m[3][2] = origin.z;
		matrix.m[3][3] = 1.f;

		return matrix;
	}

	FRotator operator+(FRotator v)
	{
		return FRotator(Pitch + v.Pitch, Yaw + v.Yaw, Roll + v.Roll);
	}

	FRotator operator-(FRotator v)
	{
		return FRotator(Pitch - v.Pitch, Yaw - v.Yaw, Roll - v.Roll);
	}

	FRotator operator*(FRotator v)
	{
		return FRotator(Pitch * v.Pitch, Yaw * v.Yaw, Roll * v.Roll);
	}

	FRotator operator/(FRotator v)
	{
		return FRotator(Pitch / v.Pitch, Yaw / v.Yaw, Roll / v.Roll);
	}
};
struct FMinimalViewInfo
{
	Vector3 Location;
	FRotator Rotation;
	float FOV;
};
struct FCameraCacheData
{
	FMinimalViewInfo POV;
};
struct FWeaponTrajectoryConfig {
	float                                              InitialSpeed;                                             // 0x0000(0x0004) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	int                                                HitDamage;                                                // 0x0004(0x0004) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              VehicleDamageScalar;                                      // 0x0008(0x0004) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              LowerClampDamage;                                         // 0x000C(0x0004) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	DWORD64                                            BallisticCurve;                                           // 0x0010(0x0008) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              RangeModifier;                                            // 0x0018(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              ReferenceDistance;                                        // 0x001C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              TravelDistanceMax;                                        // 0x0020(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      bUseMaxDamageDistance : 1;                                // 0x0024(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
	float                                              SimulationSubstepTime;                                    // 0x0028(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              VDragCoefficient;                                         // 0x002C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	float                                              BDS;                                                      // 0x0030(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      bUseAdvancedBallistics : 1;                               // 0x0034(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      bCanProduceCrackSound : 1;                                // 0x0035(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      IsPenetrable : 1;                                         // 0x0036(0x0001) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      UnknownData01[0x1];                                       // 0x0037(0x0001) MISSED OFFSET
	DWORD64                                            DamageType;                                               // 0x0038(0x0008) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char                                      bIsTrajectoryReplicationEnabled : 1;                      // 0x0040(0x0001) (CPF_Edit, CPF_DisableEditOnInstance)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0041(0x0003) MISSED OFFSET
	float                                              WeaponSpread;                                             // 0x0044(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
};
struct FLoaclWeaponData
{
	BOOL WeaponHold;
	PCSTR WeaponName;
	ULONG WeaponBullet;
	FLOAT WeaponInitialSpeed;
	FLOAT TrajectoryGravityZ;
	FWeaponTrajectoryConfig TrajectoryConfig;
};
struct FPackageItemDraw
{
	ULONG ItemObjID;
	EntityNameIDTypeMap ItemObjName;
};
struct FLoaclPlayerData
{
	ULONG_PTR PlayerPawn;
	ULONG_PTR AnimScript;
	ULONG_PTR Mesh;
	ULONG_PTR Team;
	ULONG_PTR InVehicle;
	Vector3 WorldLocation;
};
struct FTransform
{
public:
	Vector4 Rotation;
	Vector3 Translation;
	char Pad_1[4];
	Vector3 Scale3D;
	char Pad_2[4];
	D3DMATRIX ToMatrixWithScale()
	{
		D3DMATRIX m;
		m._41 = Translation.x;
		m._42 = Translation.y;
		m._43 = Translation.z;

		float x2 = Rotation.x + Rotation.x;
		float y2 = Rotation.y + Rotation.y;
		float z2 = Rotation.z + Rotation.z;

		float xx2 = Rotation.x * x2;
		float yy2 = Rotation.y * y2;
		float zz2 = Rotation.z * z2;
		m._11 = (1.0f - (yy2 + zz2)) * Scale3D.x;
		m._22 = (1.0f - (xx2 + zz2)) * Scale3D.y;
		m._33 = (1.0f - (xx2 + yy2)) * Scale3D.z;

		float yz2 = Rotation.y * z2;
		float wx2 = Rotation.w * x2;
		m._32 = (yz2 - wx2) * Scale3D.z;
		m._23 = (yz2 + wx2) * Scale3D.y;

		float xy2 = Rotation.x * y2;
		float wz2 = Rotation.w * z2;
		m._21 = (xy2 - wz2) * Scale3D.y;
		m._12 = (xy2 + wz2) * Scale3D.x;

		float xz2 = Rotation.x * z2;
		float wy2 = Rotation.w * y2;
		m._31 = (xz2 + wy2) * Scale3D.z;
		m._13 = (xz2 - wy2) * Scale3D.x;

		m._14 = 0.0f;
		m._24 = 0.0f;
		m._34 = 0.0f;
		m._44 = 1.0f;

		return m;
	}
};

D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}

D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(3.14159265) / 180);
	float radYaw = (rot.y * float(3.14159265) / 180);
	float radRoll = (rot.z * float(3.14159265) / 180);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX Matrix;
	Matrix._11 = CP * CY;
	Matrix._12 = CP * SY;
	Matrix._13 = SP;
	Matrix._14 = 0.f;

	Matrix._21 = SR * SP * CY - CR * SY;
	Matrix._22 = SR * SP * SY + CR * CY;
	Matrix._23 = -SR * CP;
	Matrix._24 = 0.f;

	Matrix._31 = -(CR * SP * CY + SR * SY);
	Matrix._32 = CY * SR - CR * SP * SY;
	Matrix._33 = CR * CP;
	Matrix._34 = 0.f;

	Matrix._41 = origin.x;
	Matrix._42 = origin.y;
	Matrix._43 = origin.z;
	Matrix._44 = 1.f;

	return Matrix;
}
namespace 全局
{
	std::unordered_map<std::string, EntityNameIDTypeMap> EntityNameIDMap = std::unordered_map<std::string, EntityNameIDTypeMap>();

	ULONG_PTR 模块地址 = 0;
	ULONG_PTR 绘制挂接 = 0;

	namespace Tools
	{
		ULONG_PTR SendInput = 0;
	}
	void InitEntityNameIDMap() {
		/*主类*/
		{
			EntityNameIDMap["AIPawn_Base_Female_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["AIPawn_Base_Male_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_Female_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_Male_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_Pillar_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_Female_Pillar_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["UltAIPawn_Base_Male_Pillar_C"] = EntityNameIDTypeMap(EntityType::AI, u8"AI");
			EntityNameIDMap["RegistedPlayer"] = EntityNameIDTypeMap(EntityType::Player, u8"Player");
			EntityNameIDMap["PlayerMale_A"] = EntityNameIDTypeMap(EntityType::Player, u8"Player");
			EntityNameIDMap["PlayerMale_A_C"] = EntityNameIDTypeMap(EntityType::Player, u8"Player");
			EntityNameIDMap["PlayerFemale_A"] = EntityNameIDTypeMap(EntityType::Player, u8"Player");
			EntityNameIDMap["PlayerFemale_A_C"] = EntityNameIDTypeMap(EntityType::Player, u8"Player");
			EntityNameIDMap["DroppedItem"] = EntityNameIDTypeMap(EntityType::DropItem, u8"丢弃物品");
			EntityNameIDMap["DroppedItemGroup"] = EntityNameIDTypeMap(EntityType::DroppedItemGroup, u8"分组物品");
		}
		/*载具*/
		{
			EntityNameIDMap["BP_Bicycle_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"自行车", true);
			//EntityNameIDMap["BP_BicycleDeployCastMesh_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"自行车", true);
			EntityNameIDMap["AquaRail_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托艇");
			EntityNameIDMap["AquaRail_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托艇");
			EntityNameIDMap["AquaRail_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托艇");
			EntityNameIDMap["Boat_PG117_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"冲锋艇");
			EntityNameIDMap["BP_ATV_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车(越野)");
			EntityNameIDMap["BP_BRDM_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"装甲车");
			EntityNameIDMap["BP_CoupeRB_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利(双人)");
			EntityNameIDMap["BP_Dirtbike_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车(杂技)");
			EntityNameIDMap["BP_DO_Circle_Train_Merged_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"火车");
			EntityNameIDMap["BP_DO_Line_Train_Dino_Merged_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"火车");
			EntityNameIDMap["BP_DO_Line_Train_Merged_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"火车");
			EntityNameIDMap["BP_EmergencyPickupVehicle_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"紧急呼救器");
			EntityNameIDMap["BP_KillTruck_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"物资车(损坏)");
			EntityNameIDMap["BP_LootTruck_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"物资车");
			EntityNameIDMap["BP_M_Rony_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"小货车");
			EntityNameIDMap["BP_M_Rony_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"小货车");
			EntityNameIDMap["BP_M_Rony_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"小货车");
			EntityNameIDMap["BP_Mirado_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利");
			EntityNameIDMap["BP_Mirado_A_03_Esports_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利");
			EntityNameIDMap["BP_Mirado_Open_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利(敞篷)");
			EntityNameIDMap["BP_Mirado_Open_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利(敞篷)");
			EntityNameIDMap["BP_Mirado_Open_05_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"法拉利(敞篷)");
			EntityNameIDMap["BP_Motorbike_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车");
			EntityNameIDMap["BP_Motorbike_04_Desert_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车");
			EntityNameIDMap["BP_Motorbike_04_SideCar_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"三蹦子");
			EntityNameIDMap["BP_Motorbike_04_SideCar_Desert_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"三蹦子");
			EntityNameIDMap["BP_Motorbike_Solitario_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车");
			EntityNameIDMap["BP_Motorglider_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"滑翔机", true);
			EntityNameIDMap["BP_Motorglider_Green_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"滑翔机", true);
			EntityNameIDMap["BP_Niva_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_05_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_06_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_Niva_07_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"野拉达");
			EntityNameIDMap["BP_PickupTruck_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_A_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_A_05_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_A_esports_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车");
			EntityNameIDMap["BP_PickupTruck_B_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车(敞篷)");
			EntityNameIDMap["BP_PickupTruck_B_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车(敞篷)");
			EntityNameIDMap["BP_PickupTruck_B_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车(敞篷)");
			EntityNameIDMap["BP_PickupTruck_B_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车(敞篷)");
			EntityNameIDMap["BP_PickupTruck_B_05_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"皮卡车(敞篷)");
			EntityNameIDMap["BP_PonyCoupe_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"超级跑车");
			EntityNameIDMap["BP_Porter_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"小货车");
			EntityNameIDMap["BP_TukTukTuk_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"三轮车");
			EntityNameIDMap["BP_TukTukTuk_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"三轮车");
			EntityNameIDMap["BP_TukTukTuk_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"三轮车");
			EntityNameIDMap["BP_Van_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"公交车");
			EntityNameIDMap["BP_Van_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"公交车");
			EntityNameIDMap["BP_Van_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"公交车");
			EntityNameIDMap["BP_MiniBus_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"公交车");
			EntityNameIDMap["BP_Scooter_01_A_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"电瓶车");
			EntityNameIDMap["BP_Scooter_02_A_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"电瓶车");
			EntityNameIDMap["BP_Scooter_03_A_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"电瓶车");
			EntityNameIDMap["BP_Scooter_04_A_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"电瓶车");
			EntityNameIDMap["BP_Snowbike_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车(雪地)");
			EntityNameIDMap["BP_Snowbike_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"摩托车(雪地)");
			EntityNameIDMap["BP_Snowmobile_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"雪地车");
			EntityNameIDMap["BP_Snowmobile_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"雪地车");
			EntityNameIDMap["BP_Snowmobile_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"雪地车");
			EntityNameIDMap["Buggy_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Buggy_A_02_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Buggy_A_03_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Buggy_A_04_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Buggy_A_05_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Buggy_A_06_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"蹦蹦车");
			EntityNameIDMap["Dacia_A_01_v2_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			EntityNameIDMap["Dacia_A_01_v2_snow_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			EntityNameIDMap["Dacia_A_02_v2_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			EntityNameIDMap["Dacia_A_03_v2_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			EntityNameIDMap["Dacia_A_03_v2_Esports_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			EntityNameIDMap["Dacia_A_04_v2_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"AE86");
			//EntityNameIDMap["DummyTransportAircraft_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"飞机D");
			EntityNameIDMap["EmergencyAircraft_Tiger_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"紧急坠机");
			// AircraftCarePackage_Desert_C 
			EntityNameIDMap["MortarPawn_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"迫击炮");
			//EntityNameIDMap["ParachutePlayer_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"降落伞");
			EntityNameIDMap["BP_Motorglider_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"滑翔机");
			EntityNameIDMap["PG117_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"冲锋艇");
			EntityNameIDMap["AircraftCarePackage_Desert_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"空投飞机A", true);
			EntityNameIDMap["AircraftCarePackage_Savage_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"空投飞机S", true);
			EntityNameIDMap["AircraftCarePackage_Test_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"空投飞机T", true);
			EntityNameIDMap["RedeployAircraft_Tiger_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"空投飞机R", true);
			EntityNameIDMap["TransportAircraft_Chimera_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"空投飞机C", true);
			//EntityNameIDMap["TransportAircraft_Tiger_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"飞机T", true);
			EntityNameIDMap["Uaz_A_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"越野车(敞篷)");
			EntityNameIDMap["Uaz_Armored_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"越野车(装甲)");
			EntityNameIDMap["Uaz_B_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"越野车(软顶)");
			EntityNameIDMap["Uaz_B_01_esports_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"越野车(软顶)");
			EntityNameIDMap["Uaz_C_01_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"越野车(硬顶)");
			
			EntityNameIDMap["WarModeTransportAircraft_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"物资运输机", true);

		}
		/*物资*/
		{
			EntityNameIDMap["Item_Mountainbike_C"] = EntityNameIDTypeMap(EntityType::Vehicle, u8"自行车", true);
			//EntityNameIDMap["InstantRevivalKit_C"] = EntityNameIDTypeMap(EntityType::Item, u8"快速救人套件");
			//EntityNameIDMap["Item_Ammo_12Guage_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(喷子)");
			//EntityNameIDMap["Item_Ammo_300Magnum_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(AWM)");
			//EntityNameIDMap["Item_Ammo_40mm_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(40mm)");
			//EntityNameIDMap["Item_Ammo_45ACP_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(.45mm)");
			//EntityNameIDMap["Item_Ammo_556mm_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(556mm)");
			//EntityNameIDMap["Item_Ammo_762mm_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(762mm)");
			//EntityNameIDMap["Item_Ammo_9mm_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(9mm)");
			//EntityNameIDMap["Item_Ammo_Bolt_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(箭)");
			//EntityNameIDMap["Item_Ammo_Flare_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(信号弹)", true);
			//EntityNameIDMap["Item_Ammo_Mortar_C"] = EntityNameIDTypeMap(EntityType::Item, u8"子弹(迫击炮)");
			EntityNameIDMap["Item_Armor_C_01_Lv3_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"护甲(Lv3)", &pItem_Armor_C_01_Lv3_C, true);
			EntityNameIDMap["Item_Armor_D_01_Lv2_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"护甲(Lv2)", &pItem_Armor_D_01_Lv2_C);
			//EntityNameIDMap["Item_Armor_E_01_Lv1_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"护甲(Lv1)");
			EntityNameIDMap["Item_Attach_Weapon_Lower_AngledForeGrip_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"三角握把", &pItem_Attach_Weapon_Lower_AngledForeGrip_C);
			EntityNameIDMap["Item_Attach_Weapon_Lower_Foregrip_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"垂直握把", &pItem_Attach_Weapon_Lower_Foregrip_C);
			EntityNameIDMap["Item_Attach_Weapon_Lower_HalfGrip_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"红色握把", &pItem_Attach_Weapon_Lower_HalfGrip_C);
			/*EntityNameIDMap["Item_Attach_Weapon_Lower_LaserPointer_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"激光瞄准器", &pItem_Attach_Weapon_Lower_LaserPointer_C);*/
			EntityNameIDMap["Item_Attach_Weapon_Lower_LightweightForeGrip_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"轻型握把", &pItem_Attach_Weapon_Lower_LightweightForeGrip_C);
			//EntityNameIDMap["Item_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"箭袋", &pItem_Attach_Weapon_Lower_QuickDraw_Large_Crossbow_C);
			EntityNameIDMap["Item_Attach_Weapon_Lower_ThumbGrip_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"拇指握把", &pItem_Attach_Weapon_Lower_ThumbGrip_C);
			EntityNameIDMap["Item_Attach_Weapon_Magazine_Extended_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪扩容", &pItem_Attach_Weapon_Magazine_Extended_Large_C);
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_Extended_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪扩容");
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_Extended_Small_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"手枪扩容");
			EntityNameIDMap["Item_Attach_Weapon_Magazine_Extended_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪扩容", &pItem_Attach_Weapon_Magazine_Extended_SniperRifle_C);
			EntityNameIDMap["Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪快扩", &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_Large_C, true);
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪快扩");
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_ExtendedQuickDraw_Small_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"手枪快扩");
			EntityNameIDMap["Item_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪快扩", &pItem_Attach_Weapon_Magazine_ExtendedQuickDraw_SniperRifle_C, true);
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_QuickDraw_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪快速");
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_QuickDraw_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪快速");
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_QuickDraw_Small_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"手枪快速");
			//EntityNameIDMap["Item_Attach_Weapon_Magazine_QuickDraw_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪快速");
			//EntityNameIDMap["Item_Attach_Weapon_Muzzle_Choke_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"扼流圈", &pItem_Attach_Weapon_Muzzle_Choke_C);
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_Compensator_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪补偿", &pItem_Attach_Weapon_Muzzle_Compensator_Large_C);
			//EntityNameIDMap["Item_Attach_Weapon_Muzzle_Compensator_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪补偿");
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_Compensator_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪补偿", &pItem_Attach_Weapon_Muzzle_Compensator_SniperRifle_C);
			/*EntityNameIDMap["Item_Attach_Weapon_Muzzle_Duckbill_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"鸭嘴枪口", &pItem_Attach_Weapon_Muzzle_Duckbill_C);*/
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_FlashHider_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪消焰", &pItem_Attach_Weapon_Muzzle_FlashHider_Large_C);
			//EntityNameIDMap["Item_Attach_Weapon_Muzzle_FlashHider_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪消焰");
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪消焰", &pItem_Attach_Weapon_Muzzle_FlashHider_SniperRifle_C);
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_Suppressor_Large_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"步枪消音", &pItem_Attach_Weapon_Muzzle_Suppressor_Large_C, true);
			/*EntityNameIDMap["Item_Attach_Weapon_Muzzle_Suppressor_Medium_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"冲锋枪消音", &pItem_Attach_Weapon_Muzzle_Suppressor_Medium_C);*/
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_Suppressor_Small_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"手枪消音", &pItem_Attach_Weapon_Muzzle_Suppressor_Small_C);
			EntityNameIDMap["Item_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"狙击枪消音", &pItem_Attach_Weapon_Muzzle_Suppressor_SniperRifle_C, true);
			EntityNameIDMap["Item_Attach_Weapon_SideRail_DotSight_RMR_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"侧面瞄具", &pItem_Attach_Weapon_SideRail_DotSight_RMR_C);
			EntityNameIDMap["Item_Attach_Weapon_Stock_AR_Composite_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"战术枪托", &pItem_Attach_Weapon_Stock_AR_Composite_C);
			//EntityNameIDMap["Item_Attach_Weapon_Stock_Shotgun_BulletLoops_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"子弹袋(散弹枪)");
			EntityNameIDMap["Item_Attach_Weapon_Stock_SniperRifle_BulletLoops_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"子弹袋", &pItem_Attach_Weapon_Stock_SniperRifle_BulletLoops_C);
			EntityNameIDMap["Item_Attach_Weapon_Stock_SniperRifle_CheekPad_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"托腮板", &pItem_Attach_Weapon_Stock_SniperRifle_CheekPad_C);
			//EntityNameIDMap["Item_Attach_Weapon_Stock_UZI_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"UZI枪托");
			EntityNameIDMap["Item_Attach_Weapon_Upper_ACOG_01_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"4倍镜", &pItem_Attach_Weapon_Upper_ACOG_01_C);
			//EntityNameIDMap["Item_Attach_Weapon_Upper_Aimpoint_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"2倍镜");
			EntityNameIDMap["Item_Attach_Weapon_Upper_CQBSS_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"8倍镜", &pItem_Attach_Weapon_Upper_CQBSS_C, true);
			EntityNameIDMap["Item_Attach_Weapon_Upper_DotSight_01_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"红点", &pItem_Attach_Weapon_Upper_DotSight_01_C);
			EntityNameIDMap["Item_Attach_Weapon_Upper_Holosight_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"全息", &pItem_Attach_Weapon_Upper_Holosight_C);
			EntityNameIDMap["Item_Attach_Weapon_Upper_PM2_01_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"15倍镜", &pItem_Attach_Weapon_Upper_PM2_01_C, true);
			//EntityNameIDMap["Item_Attach_Weapon_Upper_Scope3x_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"3倍镜");
			EntityNameIDMap["Item_Attach_Weapon_Upper_Scope6x_C"] = EntityNameIDTypeMap(EntityType::Accessories, u8"6倍镜", &pItem_Attach_Weapon_Upper_Scope6x_C);
			//EntityNameIDMap["Item_Back_B_01_StartParachutePack_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"降落伞");
			EntityNameIDMap["Item_Back_B_08_Lv3_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv3)", &pItem_Back_C_02_Lv3_C, true);
			//EntityNameIDMap["Item_Back_BackupParachute_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"降落伞(备用)");
			EntityNameIDMap["Item_Back_BlueBlocker"] = EntityNameIDTypeMap(EntityType::Armor, u8"干扰背包", &pItem_Back_BlueBlocker);
			EntityNameIDMap["Item_Back_C_01_Lv3_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv3)", &pItem_Back_C_01_Lv3_C, true);
			EntityNameIDMap["Item_Back_C_02_Lv3_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv3)", &pItem_Back_C_02_Lv3_C, true);
			//EntityNameIDMap["Item_Back_E_01_Lv1_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv1)");
			//EntityNameIDMap["Item_Back_E_02_Lv1_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv1)");
			EntityNameIDMap["Item_Back_F_01_Lv2_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv2)", &pItem_Back_F_01_Lv2_C);
			EntityNameIDMap["Item_Back_F_02_Lv2_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"背包(Lv2)", &pItem_Back_F_02_Lv2_C);
			EntityNameIDMap["Item_Boost_AdrenalineSyringe_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"肾上腺素", &pItem_Boost_AdrenalineSyringe_C);
			EntityNameIDMap["Item_Boost_EnergyDrink_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"饮料", &pItem_Boost_EnergyDrink_C);
			EntityNameIDMap["Item_Boost_PainKiller_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"止痛药", &pItem_Boost_PainKiller_C);
			EntityNameIDMap["Item_Chimera_Key_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"密室钥匙", &pItem_Weapon_FlareGun_C, true);
			EntityNameIDMap["Item_EmergencyPickup_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"紧急呼救器", &pItem_Back_B_01_StartParachutePack_C, true);
			EntityNameIDMap["Item_Ghillie_01_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(草地)", &pItem_Ghillie_01_C);
			EntityNameIDMap["Item_Ghillie_02_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(草地)", &pItem_Ghillie_02_C);
			EntityNameIDMap["Item_Ghillie_03_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(草地)", &pItem_Ghillie_03_C);
			EntityNameIDMap["Item_Ghillie_04_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(雪地)", &pItem_Ghillie_04_C);
			EntityNameIDMap["Item_Ghillie_05_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(沼泽)", &pItem_Ghillie_05_C);
			EntityNameIDMap["Item_Ghillie_06_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"吉利服(火山)", &pItem_Ghillie_06_C);
			//EntityNameIDMap["Item_Head_E_01_Lv1_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"头盔(Lv1)");
			//EntityNameIDMap["Item_Head_E_02_Lv1_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"头盔(Lv1)");
			EntityNameIDMap["Item_Head_F_01_Lv2_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"头盔(Lv2)", &pItem_Head_F_01_Lv2_C);
			EntityNameIDMap["Item_Head_F_02_Lv2_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"头盔(Lv2)", &pItem_Head_F_02_Lv2_C);
			EntityNameIDMap["Item_Head_G_01_Lv3_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"头盔(Lv3)", &pItem_Head_G_01_Lv3_C, true);
			EntityNameIDMap["Item_Heal_Bandage_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"绷带", &pItem_Heal_Bandage_C);
			EntityNameIDMap["Item_Heal_FirstAid_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"医疗包", &pItem_Heal_FirstAid_C);
			EntityNameIDMap["Item_Heal_MedKit_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"医疗箱", &pItem_Heal_MedKit_C);
			EntityNameIDMap["Item_Heaven_Key_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"密室钥匙", &pItem_Weapon_FlareGun_C, true);
			EntityNameIDMap["Item_JerryCan_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"汽油桶", &pItem_JerryCan_C);
			EntityNameIDMap["Item_Tiger_Key_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"密室钥匙", &pItem_Weapon_FlareGun_C, true);
			EntityNameIDMap["Item_Tiger_SelfRevive_C"] = EntityNameIDTypeMap(EntityType::Drug, u8"自救器", &pItem_Weapon_Apple_C, true);
			EntityNameIDMap["Item_Weapon_AK47_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AKM", &pItem_Weapon_AK47_C);
			//EntityNameIDMap["Item_Weapon_Apple_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"苹果");
			EntityNameIDMap["Item_Weapon_AUG_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AUG", &pItem_Weapon_AUG_C, true);
			EntityNameIDMap["Item_Weapon_AWM_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AWM", &pItem_Weapon_AWM_C, true);
			//EntityNameIDMap["Item_Weapon_Berreta686_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S686", &pItem_Weapon_Berreta686_C);
			EntityNameIDMap["Item_Weapon_BerylM762_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"BerylM762", &pItem_Weapon_BerylM762_C);
			EntityNameIDMap["Item_Weapon_BizonPP19_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"野牛冲锋枪", &pItem_Weapon_BizonPP19_C);
			EntityNameIDMap["Item_Weapon_BluezoneGrenade_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"篮圈手雷", &pItem_Weapon_BluezoneGrenade_C);
			EntityNameIDMap["Item_Weapon_C4_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"C4", &pItem_Weapon_C4_C);
			/*EntityNameIDMap["Item_Weapon_Cowbar_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"撬棍", &pItem_Weapon_Cowbar_C);*/
			//EntityNameIDMap["Item_Weapon_Crossbow_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"十字弩", &pItem_Weapon_Crossbow_C);
			EntityNameIDMap["Item_Weapon_DecoyGrenade_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"诱饵弹", &pItem_Weapon_DecoyGrenade_C);
			/*EntityNameIDMap["Item_Weapon_DesertEagle_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"沙漠之鹰", &pItem_Weapon_DesertEagle_C);*/
			EntityNameIDMap["Item_Weapon_DP12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"DBS", &pItem_Weapon_DP12_C);
			EntityNameIDMap["Item_Weapon_DP28_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"DP-28", &pItem_Weapon_DP12_C);
			EntityNameIDMap["Item_Weapon_Duncans_M416_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M416", &pItem_Weapon_HK416_C);
			EntityNameIDMap["Item_Weapon_FlareGun_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"信号枪", &pItem_Weapon_FlareGun_C, true);
			EntityNameIDMap["Item_Weapon_FlashBang_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"闪光弹", &pItem_Weapon_FlashBang_C);
			EntityNameIDMap["Item_Weapon_FNFal_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SLR", &pItem_Weapon_FNFal_C);
			/*EntityNameIDMap["Item_Weapon_G18_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P18C", &pItem_Weapon_G18_C);*/
			EntityNameIDMap["Item_Weapon_G36C_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"G36C", &pItem_Weapon_G36C_C);
			EntityNameIDMap["Item_Weapon_Grenade_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"手榴弹", &pItem_Weapon_Grenade_C);
			EntityNameIDMap["Item_Weapon_Grenade_Warmode_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"手榴弹", &pItem_Weapon_Grenade_C);
			EntityNameIDMap["Item_Weapon_Groza_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Groza", &pItem_Weapon_Groza_C, true);
			EntityNameIDMap["Item_Weapon_HK416_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M416", &pItem_Weapon_HK416_C);
			EntityNameIDMap["Item_Weapon_Mk12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mk12", &pItem_Weapon_Mk12_C);
			EntityNameIDMap["Item_Weapon_K2_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"K2", &pItem_Weapon_K2_C);
			EntityNameIDMap["Item_Weapon_Kar98k_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Kar98k", &pItem_Weapon_Kar98k_C);
			EntityNameIDMap["Item_Weapon_L6_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AMR", &pItem_Weapon_L6_C);
			EntityNameIDMap["Item_Weapon_M16A4_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M16A4", &pItem_Weapon_M16A4_C);
			/*EntityNameIDMap["Item_Weapon_M1911_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P1911", &pItem_Weapon_M1911_C);*/
			EntityNameIDMap["Item_Weapon_M249_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M249", &pItem_Weapon_M249_C);
			EntityNameIDMap["Item_Weapon_M24_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M24", &pItem_Weapon_M24_C);
			EntityNameIDMap["Item_Weapon_M79_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M79", &pItem_Weapon_M79_C);
			/*EntityNameIDMap["Item_Weapon_M9_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P92", &pItem_Weapon_M9_C);*/
			/*EntityNameIDMap["Item_Weapon_Machete_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"砍刀", &pItem_Weapon_Machete_C);*/
			EntityNameIDMap["Item_Weapon_MG3_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"MG3", &pItem_Weapon_MG3_C);
			EntityNameIDMap["Item_Weapon_Mini14_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mini14", &pItem_Weapon_Mini14_C);
			EntityNameIDMap["Item_Weapon_Mk14_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mk14", &pItem_Weapon_Mk14_C);
			EntityNameIDMap["Item_Weapon_Mk47Mutant_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mk47Mutant", &pItem_Weapon_Mk47Mutant_C);
			EntityNameIDMap["Item_Weapon_Molotov_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"燃烧弹", &pItem_Weapon_Molotov_C);
			EntityNameIDMap["Item_Weapon_Mortar_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"迫击炮", &pItem_Weapon_Mortar_C);
			EntityNameIDMap["Item_Weapon_Mosin_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"莫辛纳甘", &pItem_Weapon_Mosin_C);
			EntityNameIDMap["Item_Weapon_MP5K_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"MP5K", &pItem_Weapon_MP5K_C);
			/*EntityNameIDMap["Item_Weapon_NagantM1895_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"R1895", &pItem_Weapon_NagantM1895_C);*/
			EntityNameIDMap["Item_Weapon_P90_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P90", &pItem_Weapon_P90_C);
			EntityNameIDMap["Item_Weapon_Pan_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"平底锅", &pItem_Weapon_Pan_C);
			EntityNameIDMap["Item_Weapon_PanzerFaust100M_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"火箭筒", &pItem_Weapon_PanzerFaust100M_C);
			EntityNameIDMap["Item_Weapon_QBU88_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"QBU", &pItem_Weapon_QBU88_C);
			EntityNameIDMap["Item_Weapon_QBZ95_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"QUZ", &pItem_Weapon_QBZ95_C);
			/*EntityNameIDMap["Item_Weapon_Rhino_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"R45", &pItem_Weapon_Rhino_C);*/
			EntityNameIDMap["Item_Weapon_Rock_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"雪球", &pItem_Weapon_Rock_C);
			/*EntityNameIDMap["Item_Weapon_Saiga12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S12K", &pItem_Weapon_Saiga12_C);*/
			/*EntityNameIDMap["Item_Weapon_Sawnoff_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"霰弹手喷", &pItem_Weapon_Sawnoff_C);*/
			EntityNameIDMap["Item_Weapon_SCAR-L_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SCAR-L", &pItem_Weapon_SCAR_L_C);
			/*EntityNameIDMap["Item_Weapon_Sickle_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"镰刀", &pItem_Weapon_Sickle_C);*/
			EntityNameIDMap["Item_Weapon_SKS_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SKS", &pItem_Weapon_SKS_C);
			EntityNameIDMap["Item_Weapon_SmokeBomb_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"烟雾弹", &pItem_Weapon_SmokeBomb_C);
			//EntityNameIDMap["Item_Weapon_Snowball_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"雪球");
			//EntityNameIDMap["Item_Weapon_SpikeTrap_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"地刺");
			EntityNameIDMap["Item_Weapon_StickyGrenade_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"黏土炸弹", &pItem_Weapon_StickyGrenade_C);
			EntityNameIDMap["Item_Weapon_Thompson_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"汤姆逊", &pItem_Weapon_Thompson_C);
			EntityNameIDMap["Item_Weapon_UMP_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"UMP9", &pItem_Weapon_UMP_C);
			EntityNameIDMap["Item_Weapon_UZI_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Micro Uzi", &pItem_Weapon_UZI_C);
			EntityNameIDMap["Item_Weapon_Vector_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Vector", &pItem_Weapon_Vector_C);
			EntityNameIDMap["Item_Weapon_VSS_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"VSS", &pItem_Weapon_VSS_C);
			/*EntityNameIDMap["Item_Weapon_vz61Skorpion_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"蝎式冲锋枪", &pItem_Weapon_vz61Skorpion_C);*/
			EntityNameIDMap["Item_Weapon_Win1894_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Win94", &pItem_Weapon_Win1894_C);
			/*EntityNameIDMap["Item_Weapon_Winchester_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S1897", &pItem_Weapon_Winchester_C);*/
			//EntityNameIDMap["WarModeStartParachutePack_C"] = EntityNameIDTypeMap(EntityType::Item, u8"跳伞背包");
			//EntityNameIDMap["SP6_EventItem_DVD_01_C"] = EntityNameIDTypeMap(EntityType::Item, u8"DVD");
			//EntityNameIDMap["SP6_EventItem_DVD_02_C"] = EntityNameIDTypeMap(EntityType::Item, u8"DVD");
			//EntityNameIDMap["SP6_EventItem_DVD_03_C"] = EntityNameIDTypeMap(EntityType::Item, u8"DVD");
		}
		/*投掷品*/
		{
		EntityNameIDMap["ProjGrenade_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心手雷");
		EntityNameIDMap["ProjC4_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心C4");
		EntityNameIDMap["ProjBluezoneGrenade_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心篮圈手雷");
		EntityNameIDMap["ProjStickyGrenade_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心C4");
		EntityNameIDMap["ProjFlashBang_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心闪光");
		EntityNameIDMap["ProjMolotov_C"] = EntityNameIDTypeMap(EntityType::toudan, u8"小心燃烧弹");
		
		}
		/*盒子*/
		{
			EntityNameIDMap["Carapackage_RedBox_C"] = EntityNameIDTypeMap(EntityType::AirPack, u8"空投箱", &pAirPack, true);
			EntityNameIDMap["Carapackage_FlareGun_C"] = EntityNameIDTypeMap(EntityType::AirPack, u8"超级空投", &pAirPack, true);
			EntityNameIDMap["DeathDropItemPackage_C"] = EntityNameIDTypeMap(EntityType::DeadBox, u8"玩家盒子", &pAirPack, true);
		}
		/*手持武器*/
		{
			EntityNameIDMap["WeapLunchmeatsAK47_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AKM", &pWeapon_AK47_C);
			EntityNameIDMap["WeapAK47_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AKM", &pWeapon_AK47_C);
			EntityNameIDMap["WeapAUG_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AUG", &pWeapon_AUG_C);
			EntityNameIDMap["WeapAWM_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AWM", &pWeapon_AWM_C);
			EntityNameIDMap["WeapBerreta686_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S686", &pWeapon_Berreta686_C);
			EntityNameIDMap["WeapBerylM762_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"BerylM762", &pWeapon_BerylM762_C);
			EntityNameIDMap["WeapBizonPP19_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"野牛冲锋枪", &pWeapon_BizonPP19_C);
			EntityNameIDMap["WeapCowbar_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"撬棍", &pWeapon_Cowbar_C);
			EntityNameIDMap["WeapCowbarProjectile_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"撬棍", &pWeapon_Cowbar_C);
			EntityNameIDMap["WeapCrossbow_1_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"十字弩", &pWeapon_Crossbow_C);
			EntityNameIDMap["WeapDesertEagle_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"沙漠之鹰", &pWeapon_DesertEagle_C);
			EntityNameIDMap["WeapDP12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"DBS", &pWeapon_DP12_C);
			EntityNameIDMap["WeapDP28_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"DP-28", &pWeapon_DP28_C);
			EntityNameIDMap["WeapDuncansHK416_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M416", &pWeapon_HK416_C);
			EntityNameIDMap["WeapHK416_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M416", &pWeapon_HK416_C);
			EntityNameIDMap["WeapFNFal_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SLR", &pWeapon_FNFal_C);
			EntityNameIDMap["WeapG18_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P18C", &pWeapon_G18_C);
			EntityNameIDMap["WeapG36C_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"G36C", &pWeapon_G36C_C);
			EntityNameIDMap["WeapGroza_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Groza", &pWeapon_Groza_C);
			EntityNameIDMap["WeapJuliesKar98k_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Kar98k", &pWeapon_Kar98k_C);
			EntityNameIDMap["WeapKar98k_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Kar98k", &pWeapon_Kar98k_C);
			EntityNameIDMap["WeapMk12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mk12", &pWeapon_Mk12_C);
			EntityNameIDMap["WeapK2_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"K2", &pWeapon_K2_C);
			EntityNameIDMap["WeapL6_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"AMR", &pWeapon_L6_C);
			EntityNameIDMap["WeapM16A4_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M16A4", &pWeapon_M16A4_C);
			EntityNameIDMap["WeapM1911_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P1911", &pWeapon_M1911_C);
			EntityNameIDMap["WeapM249_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M249", &pWeapon_M249_C);
			EntityNameIDMap["WeapM24_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"M24", &pWeapon_M24_C);
			EntityNameIDMap["WeapM9_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P92", &pWeapon_M9_C);
			EntityNameIDMap["WeapMachete_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"砍刀", &pWeapon_Machete_C);
			EntityNameIDMap["WeapMacheteProjectile_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"砍刀", &pWeapon_Machete_C);
			EntityNameIDMap["WeapMadsQBU88_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"QBU", &pWeapon_QBU88_C);
			EntityNameIDMap["WeapMG3_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"MG3", &pWeapon_MG3_C);
			EntityNameIDMap["WeapMini14_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mini14", &pWeapon_Mini14_C);
			EntityNameIDMap["WeapMk14_C"] = EntityNameIDTypeMap(EntityType::Armor, u8"Mk14", &pWeapon_Mk14_C);
			EntityNameIDMap["WeapMk47Mutant_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Mk47Mutant", &pWeapon_Mk47Mutant_C);
			EntityNameIDMap["WeapMP5K_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"MP5K", &pWeapon_MP5K_C);
			EntityNameIDMap["WeapNagantM1895_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"R1895");
			EntityNameIDMap["WeapMosinNagant_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"莫辛纳甘", &pWeapon_Mosin_C);
			EntityNameIDMap["WeapP90_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"P90", &pWeapon_P90_C);
			EntityNameIDMap["WeapPan_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"平底锅", &pWeapon_Pan_C);
			EntityNameIDMap["WeapPanProjectile_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"平底锅", &pWeapon_Pan_C);
			EntityNameIDMap["WeapPanzerFaust100M1_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"铁拳火箭筒", &pWeapon_PanzerFaust100M_C);
			EntityNameIDMap["WeapQBU88_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"QBU", &pWeapon_QBU88_C);
			EntityNameIDMap["WeapQBZ95_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"QBZ", &pWeapon_QBZ95_C);
			EntityNameIDMap["WeapRhino_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"R45", &pWeapon_Rhino_C);
			EntityNameIDMap["WeapSaiga12_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S12K", &pWeapon_Saiga12_C);
			EntityNameIDMap["WeapSawnoff_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"霰弹手喷", &pWeapon_Sawnoff_C);
			EntityNameIDMap["WeapSCAR-L_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SCAR-L", &pWeapon_SCAR_L_C);
			EntityNameIDMap["WeapSickle_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"镰刀", &pWeapon_Sickle_C);
			EntityNameIDMap["WeapSickleProjectile_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"镰刀", &pWeapon_Sickle_C);
			EntityNameIDMap["WeapSKS_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"SKS", &pWeapon_SKS_C);
			EntityNameIDMap["WeapThompson_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"汤姆逊", &pWeapon_Thompson_C);
			EntityNameIDMap["WeapUMP_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"UMP9", &pWeapon_UMP_C);
			EntityNameIDMap["WeapUZI_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Micro Uzi", &pWeapon_UZI_C);
			EntityNameIDMap["WeapVector_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Vector", &pWeapon_Vector_C);
			EntityNameIDMap["WeapVSS_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"VSS", &pWeapon_VSS_C);
			EntityNameIDMap["Weapvz61Skorpion_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"蝎式冲锋枪", &pWeapon_vz61Skorpion_C);
			EntityNameIDMap["WeapWin94_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"Win94", &pWeapon_Win1894_C);
			EntityNameIDMap["WeapWinchester_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"S1897", &pWeapon_Winchester_C);
			EntityNameIDMap["WeapFlareGun_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"信号枪", &pWeapon_FlareGun_C);
			EntityNameIDMap["WeapC4_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"C4", &pWeapon_C4_C);
			EntityNameIDMap["WeapMolotov_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"燃烧弹", &pWeapon_Molotov_C);
			EntityNameIDMap["WeapGrenade_C"] = EntityNameIDTypeMap(EntityType::Grenade, u8"手榴弹", &pWeapon_Grenade_C);
			
			//EntityNameIDMap["WeapJerryCan_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"燃料", &pWeapon_JerryCan_C);
			EntityNameIDMap["WeapApple_C"] = EntityNameIDTypeMap(EntityType::Weapon, u8"苹果", &pWeapon_Apple_C);
		}
	}
}

namespace GameData
{
	extern  LPCSTR 卡密;
	ULONG 大厅状态;
	ULONG_PTR 世界基址;
	ULONG_PTR 世界一级;
	ULONG_PTR 对象指针;
	ULONG_PTR 本人一级;
	ULONG_PTR 本人二级;
	ULONG_PTR 本人三级;
	ULONG_PTR 本人四级;
	ULONG_PTR 投影相机;
	ULONG_PTR 名字地址;
	ULONG_PTR 名字偏移;
	ULONG_PTR 初始指针;
	ULONG 对象数量;
	ULONG 背包状态;
	FLoaclPlayerData LoaclPlayerData;
	FLoaclWeaponData LoaclWeaponData;
	FCameraCacheData CameraCacheData;
	FCameraCacheData CameraCacheDataForAimbot;
	ULONG_PTR AimbotEntityPtr;
	ULONG NtReadVirtualMemoryIndex = 0, NtUserSendInputIndex = 0, NtUserCreateFile = 0, NtUserGetAsyncKeyStateIndex = 0, ZwQueryVirtualMemoryIndex = 0;
	
	DWORD pZwProtectVirtualMemory(HANDLE ProcessHandle, PVOID lpAddress, PSIZE_T dwSize, ULONG  flNewProtect, PULONG  lpflOldProtect);
	DWORD pZwQueryVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, ULONG MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationLength, PSIZE_T ReturnLength);
	DWORD NtUserSendInput(UINT cInputs, LPINPUT pInputs, int cbSize);
	SHORT NtUserGetAsyncKeyState(DWORD key);
	namespace DrawOverlay
	{
		vector<Vector3> ItemList;
		vector<ULONG_PTR> VehicleList;
		DWORD 盲区敌人数量;
		FLOAT 最近距离;
	}
	
}

namespace Aim
{
	vector<ULONG_PTR> AimEntityPtrList;
	vector<FLOAT> AimDistanceList;
	vector<Vector2> AimPositionList;
};

namespace Bone
{
	enum Bone : INT
	{
		//---------//
		头部 = 15,
		颈部 = 5,
		//---------//
		左肩 = 88,
		右肩 = 115,
		//---------//
		左肘 = 89,
		右肘 = 116,
		//---------//
		左手 = 90,
		右手 = 117,
		//---------//
		骨盆 = 1,
		//---------//
		左腿 = 168,
		右腿 = 174,
		//---------//
		左膝 = 169,
		右膝 = 175,
		//---------//
		左脚跟 = 170,
		左脚前 = 171,
		右脚跟 = 176,
		右脚前 = 177,
		//---------//
		脚底 = 193,
		身体 = 4,
	};

	list<INT> _上部 = { Bone::颈部, Bone::头部 };
	list<INT> _右臂 = { Bone::颈部, Bone::右肩, Bone::右肘, Bone::右手 };
	list<INT> _左臂 = { Bone::颈部, Bone::左肩, Bone::左肘, Bone::左手 };
	list<INT> _脊柱 = { Bone::颈部, 4, 3, 2, Bone::骨盆 };
	list<INT> _右腿 = { Bone::骨盆, Bone::右腿, Bone::右膝, Bone::右脚跟, Bone::右脚前 };
	list<INT> _左腿 = { Bone::骨盆, Bone::左腿, Bone::左膝, Bone::左脚跟, Bone::左脚前 };
	list<list<INT>> 拼接骨骼 = { _上部, _右臂, _左臂, _脊柱, _右腿, _左腿 };
}
Vector3 叠加物品(Vector3 ItemScreenLocation) {
	for (ULONG i = 0; i < GameData::DrawOverlay::ItemList.size(); i++)
	{
		if (ItemScreenLocation.x > GameData::DrawOverlay::ItemList[i].x - 80.f && ItemScreenLocation.x < GameData::DrawOverlay::ItemList[i].x + 80.f
			&& ItemScreenLocation.y > GameData::DrawOverlay::ItemList[i].y - 15.f && ItemScreenLocation.y < GameData::DrawOverlay::ItemList[i].y + 15.f)
		{
			ItemScreenLocation = GameData::DrawOverlay::ItemList[i];
			ItemScreenLocation.y = ItemScreenLocation.y - 18.f;
		}
	}
	return ItemScreenLocation;
}
double 弧度转角度(double 弧度)
{
	return 弧度 * double(57.29577951308);
}

Vector3 计算角度(Vector3 D, Vector3 W)
{
	float 坐标X差 = W.x - D.x;
	float 坐标Y差 = W.y - D.y;
	float 坐标Z差 = W.z - D.z;
	Vector3 角度 = Vector3(float(弧度转角度(atan2(坐标Y差, 坐标X差))), float(弧度转角度(atan2(坐标Z差, sqrt(坐标X差 * 坐标X差 + 坐标Y差 * 坐标Y差)))), 0.0f);
	return 角度;
}
Vector2 WorldToScreenForAimbot(Vector3 WorldLocation)
{
	Vector2 ScreenLocation = Vector2(0.0f, 0.0f);
	D3DMATRIX TempMatrix = GameData::CameraCacheDataForAimbot.POV.Rotation.Matrix();
	Vector3 vAxisX = Vector3(TempMatrix.m[0][0], TempMatrix.m[0][1], TempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(TempMatrix.m[1][0], TempMatrix.m[1][1], TempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(TempMatrix.m[2][0], TempMatrix.m[2][1], TempMatrix.m[2][2]);
	Vector3 vDelta = WorldLocation - GameData::CameraCacheDataForAimbot.POV.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
	if (vTransformed.z < 1.0F) vTransformed.z = 1.0F;
	FLOAT FovAngle = GameData::CameraCacheDataForAimbot.POV.FOV;
	ScreenLocation.x = g_d3dViewPort.TopLeftX + vTransformed.x * (g_d3dViewPort.TopLeftX / tanf(FovAngle * M_PI / 360.f)) / vTransformed.z;
	ScreenLocation.y = g_d3dViewPort.TopLeftY - vTransformed.y * (g_d3dViewPort.TopLeftX / tanf(FovAngle * M_PI / 360.f)) / vTransformed.z;
	return ScreenLocation;
}
Vector2 WorldToScreen(Vector3 WorldLocation)
{
	Vector2 ScreenLocation = Vector2(0.0f, 0.0f);
	D3DMATRIX TempMatrix = GameData::CameraCacheData.POV.Rotation.Matrix();
	Vector3 vAxisX = Vector3(TempMatrix.m[0][0], TempMatrix.m[0][1], TempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(TempMatrix.m[1][0], TempMatrix.m[1][1], TempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(TempMatrix.m[2][0], TempMatrix.m[2][1], TempMatrix.m[2][2]);
	Vector3 vDelta = WorldLocation - GameData::CameraCacheData.POV.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
	if (vTransformed.z < 1.0F) vTransformed.z = 1.0F;
	FLOAT FovAngle = GameData::CameraCacheData.POV.FOV;
	ScreenLocation.x = g_d3dViewPort.TopLeftX + vTransformed.x * (g_d3dViewPort.TopLeftX / tanf(FovAngle * M_PI / 360.f)) / vTransformed.z;
	ScreenLocation.y = g_d3dViewPort.TopLeftY - vTransformed.y * (g_d3dViewPort.TopLeftX / tanf(FovAngle * M_PI / 360.f)) / vTransformed.z;
	return ScreenLocation;
}

Vector3 GetBonePosition(ULONG_PTR Mesh, INT ID)
{
	ULONG_PTR BoneArry = Memory::Read<ULONG_PTR>(Mesh + _Bone);

	FTransform Bone = Memory::Read<FTransform>(BoneArry + (static_cast<unsigned long long>(ID) * 0x30));

	FTransform ComponentToWorld = Memory::Read<FTransform>(Mesh + _BoneArry);

	D3DMATRIX Matrix = MatrixMultiplication(Bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}
FLOAT GetAimDragForce(FLOAT Distance) {
	FLOAT Gravity = 1.33f;	PCSTR WeaponName = GameData::LoaclWeaponData.WeaponName;
	if (Distance <= 250)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 1.25; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 0.5f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 0.7f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 0.6f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 0.55f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 0.45f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 0.55f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 0.45f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 0.5f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 0.55f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.0f; }
		else { Gravity = 1.1f; }
	}
	else if (Distance <= 300)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 1.25f; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 0.5f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 0.8f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 0.9f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 0.45f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 0.6f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 0.75f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 0.9f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.0f; }
		else { Gravity = 1.1f; }
	}
	else if (Distance <= 350)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 1.3f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.3f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 0.9f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 1.1f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 0.95f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.2f; }
		else { Gravity = 1.2f; }
	}
	else if (Distance <= 400)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 1.82f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 1.65f; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 1.35f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 1.6f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 1.6f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.0f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 1.6f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.15f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 1.3f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.4f; }
		else { Gravity = 1.5f; }
	}
	else if (Distance <= 450)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 2.15f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 2.0f; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 1.4f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.3f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 1.45f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 1.9f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 1.85f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.75f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.2f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 1.45f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 2.1f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.35f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.35f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.61f; }
		else { Gravity = 1.7f; }
	}
	else if (Distance <= 500)
	{
		if (strcmp(WeaponName, u8"AKM") == 0) { Gravity = 2.45f; }
		else if (strcmp(WeaponName, u8"AUG") == 0) { Gravity = 2.1f; }
		else if (strcmp(WeaponName, u8"QBZ") == 0) { Gravity = 1.6f; }
		else if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.55f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 1.8f; }
		else if (strcmp(WeaponName, u8"SCAR-L") == 0) { Gravity = 2.15f; }
		else if (strcmp(WeaponName, u8"M416") == 0) { Gravity = 2.1f; }
		else if (strcmp(WeaponName, u8"M16A4") == 0) { Gravity = 1.9f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.3f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 2.0f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 1.9f; }
		else if (strcmp(WeaponName, u8"Groza") == 0) { Gravity = 2.3f; }
		else if (strcmp(WeaponName, u8"UMP9") == 0) { Gravity = 1.9f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"BerylM762") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { Gravity = 1.9f; }
		else if (strcmp(WeaponName, u8"G36C") == 0) { Gravity = 1.85f; }
		else { Gravity = 1.9f; }
	}
	else if (Distance <= 550)
	{
		if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.8f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.75f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 2.2f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.5f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 2.5f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 2.0f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.7f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.6f; }
		else { Gravity = 2.2f; }
	}
	else if (Distance <= 600)
	{
		if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 1.95f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.85f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 2.35f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.67f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 2.5f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 2.4f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 1.8f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.8f; }
		else { Gravity = 2.5f; }
	}
	else if (Distance <= 650)
	{
		if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 2.175f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 1.95f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 2.5f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.75f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 2.95f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 2.5f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 2.0f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 1.95f; }
		else { Gravity = 3.0f; }
	}
	else if (Distance <= 700)
	{
		if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 2.25f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 2.1f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 2.95f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 2.1f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 3.25f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 2.8f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 2.05f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 2.1f; }
		else { Gravity = 3.5f; }
	}
	else if (Distance <= 800)
	{
		if (strcmp(WeaponName, u8"Kar98k") == 0) { Gravity = 2.35f; }
		else if (strcmp(WeaponName, u8"M24") == 0) { Gravity = 2.3f; }
		else if (strcmp(WeaponName, u8"SKS") == 0) { Gravity = 3.4f; }
		else if (strcmp(WeaponName, u8"AWM") == 0) { Gravity = 1.95f; }
		else if (strcmp(WeaponName, u8"Mini14") == 0) { Gravity = 3.6f; }
		else if (strcmp(WeaponName, u8"QBU") == 0) { Gravity = 3.3f; }
		else if (strcmp(WeaponName, u8"Mk14") == 0) { Gravity = 2.25f; }
		else if (strcmp(WeaponName, u8"SLR") == 0) { Gravity = 2.4f; }
		else { Gravity = 4.0f; }
	}
	else { Gravity = 5.0f; }
	return Gravity;
}
FLOAT GetAimSpeed()
{
	FLOAT AimSpeed;	PCSTR WeaponName = GameData::LoaclWeaponData.WeaponName;
	if (GameData::LoaclWeaponData.TrajectoryConfig.InitialSpeed > 100.f) {
		AimSpeed = GameData::LoaclWeaponData.TrajectoryConfig.InitialSpeed;
	}
	else {
		if (strcmp(WeaponName, u8"AKM") == 0) { AimSpeed = 715.f; }
		if (strcmp(WeaponName, u8"M416") == 0) { AimSpeed = 880.f; }
		if (strcmp(WeaponName, u8"M16A4") == 0) { AimSpeed = 900.f; }
		if (strcmp(WeaponName, u8"QBZ") == 0) { AimSpeed = 870.f; }
		if (strcmp(WeaponName, u8"SCAR-L") == 0) { AimSpeed = 870.f; }
		if (strcmp(WeaponName, u8"Mini14") == 0) { AimSpeed = 990.f; }
		if (strcmp(WeaponName, u8"SKS") == 0) { AimSpeed = 800.f; }
		if (strcmp(WeaponName, u8"Kar98k") == 0) { AimSpeed = 760.f; }
		if (strcmp(WeaponName, u8"M24") == 0) { AimSpeed = 790.f; }
		if (strcmp(WeaponName, u8"AWM") == 0) { AimSpeed = 910.f; }
		if (strcmp(WeaponName, u8"SLR") == 0) { AimSpeed = 840.f; }
		if (strcmp(WeaponName, u8"QBU") == 0) { AimSpeed = 945.f; }
		if (strcmp(WeaponName, u8"Groza") == 0) { AimSpeed = 715.f; }
		if (strcmp(WeaponName, u8"Mk14") == 0) { AimSpeed = 853.f; }
		if (strcmp(WeaponName, u8"M249") == 0) { AimSpeed = 880.f; }
		if (strcmp(WeaponName, u8"VSS") == 0) { AimSpeed = 300.f; }
		if (strcmp(WeaponName, u8"DP-28") == 0) { AimSpeed = 450.f; }
		if (strcmp(WeaponName, u8"UMP9") == 0) { AimSpeed = 400.f; }
		if (strcmp(WeaponName, u8"AUG") == 0) { AimSpeed = 940.f; }
		if (strcmp(WeaponName, u8"Vector") == 0) { AimSpeed = 300.f; }
		if (strcmp(WeaponName, u8"十字弩") == 0) { AimSpeed = 160.f; }
		if (strcmp(WeaponName, u8"汤姆逊") == 0) { AimSpeed = 280.f; }
		if (strcmp(WeaponName, u8"Micro Uzi") == 0) { AimSpeed = 350.f; }
		if (strcmp(WeaponName, u8"S12K") == 0) { AimSpeed = 350.f; }
		if (strcmp(WeaponName, u8"S686") == 0) { AimSpeed = 370.f; }
		if (strcmp(WeaponName, u8"S1897") == 0) { AimSpeed = 360.f; }
		if (strcmp(WeaponName, u8"Mk47Mutant") == 0) { AimSpeed = 780.f; }
		if (strcmp(WeaponName, u8"BerylM762") == 0) { AimSpeed = 715.f; }
		if (strcmp(WeaponName, u8"Win94") == 0) { AimSpeed = 760.f; }
		else { AimSpeed = 880.f; }
	}
	return AimSpeed;
}
Vector3 PredictedPosition(Vector3 Velocity, Vector3 VelocityUp, FLOAT Distance)
{
	Vector3 Results = { 0.f, 0.f, 0.f };
	FLOAT 衰减 = GetAimDragForce(Distance);
	FLOAT Gravity = 9.72f;// 9.800000191f;
	FLOAT TimeToReach = Distance / GameData::LoaclWeaponData.WeaponInitialSpeed;
	FLOAT Drop = Distance <= 100 ? 0 : (0.5f * Gravity * TimeToReach * TimeToReach * 50.0f) * 衰减;
	Results.z += Drop;

	Results.x = VelocityUp.x / 2 * powf(TimeToReach, 2) + Results.x;
	Results.y = VelocityUp.y / 2 * powf(TimeToReach, 2) + Results.y;
	Results.z = VelocityUp.z / 2 * powf(TimeToReach, 2) + Results.z;

	Results.x = Velocity.x * TimeToReach * 1.33f + Results.x;
	Results.y = Velocity.y * TimeToReach * 1.33f + Results.y;
	Results.z = Velocity.z * TimeToReach * 1.33f + Results.z;
	return Results;
}
DWORD GetTeamColor(DWORD TeamNumber)
{
	DWORD teamNumber = TeamNumber % 51;
	if (teamNumber == 1) return      0xA01D3C82;
	else if (teamNumber == 2)return  0xA03C843F;
	else if (teamNumber == 3)return  0xA0C76622;
	else if (teamNumber == 4)return  0xA0277FCA;
	else if (teamNumber == 5)return  0xA04B227D;
	else if (teamNumber == 6)return  0xA08E3524;
	else if (teamNumber == 7)return  0xA0425B0E;
	else if (teamNumber == 8)return  0xA0B12E5C;
	else if (teamNumber == 9)return  0xA08D6430;
	else if (teamNumber == 10)return 0xA0720F43;
	else if (teamNumber == 11)return 0xA08EA22C;
	else if (teamNumber == 12)return 0xA056A6A3;
	else if (teamNumber == 13)return 0xA0687880;
	else if (teamNumber == 14)return 0xA0D68F1D;
	else if (teamNumber == 15)return 0xA03A464C;
	else if (teamNumber == 16)return 0xA0D17393;
	else if (teamNumber == 17)return 0xA00D6560;
	else if (teamNumber == 18)return 0xA07A4713;
	else if (teamNumber == 19)return 0xA06E9125;
	else if (teamNumber == 20)return 0xA0815597;
	else if (teamNumber == 21)return 0xA0489775;
	else if (teamNumber == 22)return 0xA07892B5;
	else if (teamNumber == 23)return 0xA0D59174;
	else if (teamNumber == 24)return 0xA0332F64;
	else if (teamNumber == 25)return 0xA0877F1A;
	else if (teamNumber == 26)return 0xA0EE55AA;
	else if (teamNumber == 27)return 0xA0B4D8FC;
	else if (teamNumber == 28)return 0xA0ABD3D0;
	else if (teamNumber == 29)return 0xA0FADE6D;
	else if (teamNumber == 30)return 0xA0C2F836;
	else if (teamNumber == 31)return 0xA0FADE6D;
	else if (teamNumber == 32)return 0xA0ABD3D0;
	else if (teamNumber == 33)return 0xA0D5705C;
	else if (teamNumber == 34)return 0xA0EA7652;
	else if (teamNumber == 35)return 0xA010AAD8;
	else if (teamNumber == 36)return 0xA035DCB4;
	else if (teamNumber == 37)return 0xA0C68B08;
	else if (teamNumber == 38)return 0xA083645A;
	else if (teamNumber == 39)return 0xA071DFE6;
	else if (teamNumber == 40)return 0xA04531F1;
	else if (teamNumber == 41)return 0xA0E7BBFE;
	else if (teamNumber == 42)return 0xA038FDD8;
	else if (teamNumber == 43)return 0xA0BCB7CB;
	else if (teamNumber == 44)return 0xA0CFDA07;
	else if (teamNumber == 45)return 0xA0FAE8CD;
	else if (teamNumber == 46)return 0xA00458B8;
	else if (teamNumber == 47)return 0xA0CEE296;
	else if (teamNumber == 48)return 0xA0478FAF;
	else if (teamNumber == 49)return 0xA0E94773;
	else if (teamNumber == 50)return 0xA0F72EF3;
	else return 0xA0F8A658;
}
