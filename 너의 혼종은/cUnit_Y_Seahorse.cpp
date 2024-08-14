#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Y_Seahorse.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Y_Seahorse.h"



cUnit_Y_Seahorse::cUnit_Y_Seahorse()
	: cUnit(6.f)
{
	m_CollRect = { 90 - 128, 65 - 128, 173 - 128, 220 - 128 };

	this->Init(AI::Y_Seahorse, Team::Enemy, Unit::Y_Seahorse, 4, 200);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_Seahorse_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_Seahorse_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Y_Seahorse);
	m_CurrWeaponNum = 0;
}

cUnit_Y_Seahorse::~cUnit_Y_Seahorse()
{
}



INT cUnit_Y_Seahorse::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_Y_Seahorse::OnRenderUnit()
{
	return 0;
}



INT cUnit_Y_Seahorse::OnItemDrop(cData* pData)
{
	if (rand() % 2 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::OnceTorpedo, m_Pos));
	}

	return 0;
}