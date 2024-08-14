#include "Util.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cItem_GuidedTorpedo.h"



cItem_GuidedTorpedo::cItem_GuidedTorpedo()
	: cItem(Item::GuidedTorpedo)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_GuidedTorpedo], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_GuidedTorpedo::~cItem_GuidedTorpedo()
{
}



INT cItem_GuidedTorpedo::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_GuidedTorpedo::OnRenderItem()
{
	return 0;
}



INT cItem_GuidedTorpedo::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->SetCurrWeaponNum(2);
	}

	return 0;
}