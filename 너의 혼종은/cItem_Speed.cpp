#include "Util.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cItem_Speed.h"



cItem_Speed::cItem_Speed()
	: cItem(Item::Speed)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_Speed], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_Speed::~cItem_Speed()
{
}



INT cItem_Speed::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_Speed::OnRenderItem()
{
	return 0;
}



INT cItem_Speed::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->AddMoveSpeed(0.5f);
	}

	return 0;
}