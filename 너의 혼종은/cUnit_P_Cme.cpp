#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_P_Cme.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_P_Cme.h"



cUnit_P_Cme::cUnit_P_Cme()
	: cUnit(8.f)
{
	m_CollRect = { 20 - 128, 113 - 128, 215 - 128, 160 - 128 };

	this->Init(AI::P_Cme, Team::Enemy, Unit::P_Cme, 8, 400);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_P_Cme_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_P_Cme_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_P_Cme);
	m_CurrWeaponNum = 0;
}

cUnit_P_Cme::~cUnit_P_Cme()
{
}



INT cUnit_P_Cme::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_P_Cme::OnRenderUnit()
{
	return 0;
}



INT cUnit_P_Cme::OnItemDrop(cData* pData)
{
	if (rand() % 3 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::TripleTorpedo, m_Pos));
	}

	return 0;
}