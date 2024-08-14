#include "Util.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cItem_TripleTorpedo.h"



cItem_TripleTorpedo::cItem_TripleTorpedo()
	: cItem(Item::TripleTorpedo)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_TripleTorpedo], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_TripleTorpedo::~cItem_TripleTorpedo()
{
}



INT cItem_TripleTorpedo::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_TripleTorpedo::OnRenderItem()
{
	return 0;
}



INT cItem_TripleTorpedo::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		if (pPlayer->GetCurrWeaponNum() < 2)
		{
			pPlayer->SetCurrWeaponNum(1);
		}
	}

	return 0;
}