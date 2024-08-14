#include "Util.h"

#include "c2DAniList.h"

#include "cMapObj_Seaweed.h"



cMapObj_Seaweed::cMapObj_Seaweed()
	:cMapObject(MapObject::Seaweed, 16.f)
{
	m_CollRect = { 10 - 64, 10 - 64, 118 - 64, 118 - 64 };

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_MapObj_Seaweed], 24, 36);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cMapObj_Seaweed::~cMapObj_Seaweed()
{
}



INT cMapObj_Seaweed::OnUpdateMapObject(cData* pData)
{
	return 0;
}

INT cMapObj_Seaweed::OnRenderMapObject()
{
	return 0;
}