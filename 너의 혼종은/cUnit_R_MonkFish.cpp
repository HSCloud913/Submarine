#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_R_MonkFish.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_R_MonkFish.h"



cUnit_R_MonkFish::cUnit_R_MonkFish()
	: cUnit(6.f)
{
	m_CollRect = { 58 - 128, 95 - 128, 207 - 128, 196 - 128 };

	this->Init(AI::R_MonkFish, Team::Enemy, Unit::R_MonkFish, 10, 600);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_MonkFish_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_MonkFish_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_R_MonkFish);
	m_CurrWeaponNum = 0;
}

cUnit_R_MonkFish::~cUnit_R_MonkFish()
{
}



INT cUnit_R_MonkFish::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_R_MonkFish::OnRenderUnit()
{
	return 0;
}



INT cUnit_R_MonkFish::OnItemDrop(cData* pData)
{
	if (rand() % 3 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Upgrade, m_Pos));
	}

	if (rand() % 6 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Nuclear, m_Pos));
	}

	return 0;
}