#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_R_Seahorse.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_R_Seahorse.h"



cUnit_R_Seahorse::cUnit_R_Seahorse()
	: cUnit(9.f)
{
	m_CollRect = { 90 - 128, 65 - 128, 173 - 128, 220 - 128 };

	this->Init(AI::R_Seahorse, Team::Enemy, Unit::R_Seahorse, 6, 300);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Seahorse_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Seahorse_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_R_Seahorse);
	m_CurrWeaponNum = 0;
}

cUnit_R_Seahorse::~cUnit_R_Seahorse()
{
}



INT cUnit_R_Seahorse::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_R_Seahorse::OnRenderUnit()
{
	return 0;
}



INT cUnit_R_Seahorse::OnItemDrop(cData* pData)
{
	if (rand() % 8 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Upgrade, m_Pos));
	}

	else if (rand() % 12 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Nuclear, m_Pos));
	}

	return 0;
}