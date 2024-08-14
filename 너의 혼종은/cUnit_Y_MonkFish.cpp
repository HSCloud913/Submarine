#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Y_MonkFish.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Y_MonkFish.h"



cUnit_Y_MonkFish::cUnit_Y_MonkFish()
	: cUnit(5.f)
{
	m_CollRect = { 58 - 128, 95 - 128, 207 - 128, 196 - 128 };

	this->Init(AI::Y_MonkFish, Team::Enemy, Unit::Y_MonkFish, 9, 500);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_MonkFish_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_MonkFish_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Y_MonkFish);
	m_CurrWeaponNum = 0;
}

cUnit_Y_MonkFish::~cUnit_Y_MonkFish()
{
}



INT cUnit_Y_MonkFish::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_Y_MonkFish::OnRenderUnit()
{
	return 0;
}



INT cUnit_Y_MonkFish::OnItemDrop(cData* pData)
{
	if (rand() % 3 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::TripleTorpedo, m_Pos));
	}

	return 0;
}