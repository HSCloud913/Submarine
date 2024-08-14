#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_R_Cme.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_R_Cme.h"



cUnit_R_Cme::cUnit_R_Cme()
	: cUnit(12.f)
{
	m_CollRect = { 20 - 128, 113 - 128, 215 - 128, 160 - 128 };

	this->Init(AI::R_Cme, Team::Enemy, Unit::R_Cme, 10, 500);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Cme_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Cme_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_R_Cme);
	m_CurrWeaponNum = 0;
}

cUnit_R_Cme::~cUnit_R_Cme()
{
}



INT cUnit_R_Cme::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_R_Cme::OnRenderUnit()
{
	return 0;
}



INT cUnit_R_Cme::OnItemDrop(cData* pData)
{
	if (rand() % 4 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::GuidedTorpedo, m_Pos));
	}

	else if (rand() % 7 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Nuclear, m_Pos));
	}

	return 0;
}