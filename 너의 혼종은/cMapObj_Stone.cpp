#include "Util.h"

#include "c2DAniList.h"

#include "cMapObj_Stone.h"



cMapObj_Stone::cMapObj_Stone()
	:cMapObject(MapObject::Stone, 14.f)
{
	m_CollRect = { 10 - 64, 10 - 64, 118 - 64, 118 - 64 };

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_MapObj_Stone], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}


cMapObj_Stone::~cMapObj_Stone()
{
}



INT cMapObj_Stone::OnUpdateMapObject(cData* pData)
{
	m_AngleSpeed = 5.f;

	return 0;
}

INT cMapObj_Stone::OnRenderMapObject()
{
	return 0;
}