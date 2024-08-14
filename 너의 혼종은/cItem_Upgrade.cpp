#include "Util.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cItem_Upgrade.h"



cItem_Upgrade::cItem_Upgrade()
	: cItem(Item::Upgrade)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_Upgrade], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_Upgrade::~cItem_Upgrade()
{
}



INT cItem_Upgrade::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_Upgrade::OnRenderItem()
{
	return 0;
}



INT cItem_Upgrade::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->AddCurrUpgrade(1);
	}

	return 0;
}