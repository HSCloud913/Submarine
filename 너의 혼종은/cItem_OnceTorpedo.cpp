#include "Util.h"

#include "c2DAniList.h"

#include "cData.h"

#include "cUnit_Player.h"

#include "BulletFactory.h"

#include "cItem_OnceTorpedo.h"



cItem_OnceTorpedo::cItem_OnceTorpedo()
	: cItem(Item::OnceTorpedo)
{
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Item_OnceTorpedo], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cItem_OnceTorpedo::~cItem_OnceTorpedo()
{
}



INT cItem_OnceTorpedo::OnUpdateItem(cData* pData)
{
	return 0;
}

INT cItem_OnceTorpedo::OnRenderItem()
{
	return 0;
}



INT cItem_OnceTorpedo::OnUse(cData* pData, cUnit_Player* pPlayer)
{
	if (pData != nullptr)
	{
		D3DXVECTOR2 Pos = *pPlayer->Pos();
		Pos.x += 75.f;
		Pos.y += 40.f;

		pData->AddObject(BulletFactory::Create(Bullet::Torpedo, Pos, 90.f, pPlayer->GetCurrUpgrade()));
	}

	return 0;
}