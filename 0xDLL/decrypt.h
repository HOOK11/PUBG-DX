#pragma once

ULONG _XOR_(ULONG _����1, ULONG _����2) {
	return _����1 ^ _����2;
}

ULONG _SHL_(ULONG _����1, ULONG _����2) {
	return _����1 << _����2;
}

ULONG _ROL_(ULONG _����1, ULONG _����2) {
	_����2 %= 32;
	return (_����1 << _����2) | (_����1 >> (32 - _����2));
}

ULONG _ROR_(ULONG _����1, ULONG _����2) {
	_����2 %= 32;
	return (_����1 << (32 - _����2)) | (_����1 >> _����2);
}
namespace Decrypt
{
	ULONG_PTR DecryptPtr(ULONG_PTR Encrypted)
	{
		return Encrypted != NULL ? ((ULONG_PTR(__fastcall*)(ULONG_PTR, ULONG_PTR))(*(ULONG_PTR*)(ȫ��::ģ���ַ + _Shieldָ��)))(0, Encrypted) : NULL;
	}

	ULONG DecryptObjectID(ULONG Encrypted)
	{
		// #define F_DEC_ID(id) (_ROR_(id ^ 0xBB3B168B, 8) ^ _ROR_(id ^ 0xBB3B168B, 8) << 0x10 ^ 0xB0AD4459)
		//return F_DEC_ID(Encrypted);
		if (_Pz == 3) return _XOR_(_XOR_(_SHL_(Encrypted, _TableTwo), _DecryptTwo), Encrypted);
		Encrypted = _Pz == 1 ? _ROR_(_XOR_(Encrypted, _DecryptOne), _TableOne) : _ROL_(_XOR_(Encrypted, _DecryptOne), _TableOne);
		return _XOR_(_XOR_(_SHL_(Encrypted, _TableTwo), _DecryptTwo), Encrypted);
	}
}
PCSTR CacheGNamesForID(ULONG ID)
{
	ULONG_PTR fNamePtr = Memory::Read<ULONG_PTR>(GameData::����ƫ�� + ((static_cast<unsigned long long>(ID / _IDD)) * 0x08));
	if (Memory::ValidPtr(fNamePtr, sizeof(ULONG_PTR))) return "";
	ULONG_PTR fName = Memory::Read<ULONG_PTR>(fNamePtr + ((static_cast<unsigned long long>(ID % _IDD)) * 0x08));
	if (Memory::ValidPtr(fName, sizeof(ULONG_PTR)))  return "";
	return(PCSTR)(fName + 0x10);
}
EntityNameIDTypeMap FindEntityObjName(ULONG EntityObjID, PCSTR EntityObjName) {
	std::unordered_map<std::string, EntityNameIDTypeMap>::iterator IDTypeMapIt = std::unordered_map<std::string, EntityNameIDTypeMap>::iterator();
	IDTypeMapIt = ȫ��::EntityNameIDMap.find(EntityObjName); if (IDTypeMapIt == ȫ��::EntityNameIDMap.end()) {
		/*DbgPrint("δ֪��Ʒ��%d\t%s", EntityObjID, EntityObjName);*/
		ȫ��::EntityNameIDMap[EntityObjName] = EntityNameIDTypeMap(EntityType::Unknowns, EntityObjName);
		return EntityNameIDTypeMap(EntityType::Unknowns, EntityObjName);
	}
	return IDTypeMapIt->second;
}
EntityNameIDTypeMap FindEntityObjName(ULONG EntityObjID) {
	PCSTR EntityObjName = CacheGNamesForID(EntityObjID); if (!EntityObjName) { return EntityNameIDTypeMap(); }
	return FindEntityObjName(EntityObjID, EntityObjName);
}

typedef struct StringA
{
	char buffer[64];
};

//std::string GetNames(DWORD ID)
//{
//	std::string emp = "duiaudsakjkow";
//	if (ID <= 0 || ID > 700000)
//		return emp;
//	char Name[64] = { 0 };
//	uint32_t IdDiv = ID / _IDD;
//	uint32_t Idtemp = ID % _IDD;
//	uint64_t Serial = Memory::Read<uint64_t>(GameData::����ƫ�� + IdDiv * 0x8);
//	if (!Serial || Serial < 0x10000)
//		return emp;
//	uint64_t pName = Memory::Read<uint64_t>(Serial + 0x8 * Idtemp);
//	if (!pName || pName < 0x10000)
//		return emp;
//	StringA names = Memory::Read<StringA>(pName + 0x10);
//	char te[64];
//	memset(&te, 0, 64);
//	if (memcmp(names.buffer, te, 64) == 0)
//		return emp;
//	std::string str(names.buffer);
//	return str;
//}