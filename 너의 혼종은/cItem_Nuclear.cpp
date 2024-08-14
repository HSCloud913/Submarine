#include "Util.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cItem_Nuclear.h"



cItem_Nuclear::cItem_Nuclear()
	: cItem(Item::Nuclear)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_Nuclear], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_Nuclear::~cItem_Nuclear()
{
}



INT cItem_Nuclear::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_Nuclear::OnRenderItem()
{
	return 0;
}



INT cItem_Nuclear::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->AddNuclear(1);
	}

	return 0;
}