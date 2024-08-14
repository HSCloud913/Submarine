#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Shark.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Shark.h"



cUnit_Shark::cUnit_Shark()
	: cUnit(0.f)
{
	m_Scale = D3DXVECTOR2(2.f, 2.f);

	m_CollRect = { -150 - 256, 150 - 256, 500 - 256, 400 - 256 };

	this->Init(AI::Shark, Team::Enemy, Unit::Shark, 150, 2500);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Shark_Move], 24, 36);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Shark_Pattern1], 48, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Shark_Pattern2], 48, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Shark);
	m_CurrWeaponNum = 0;
}

cUnit_Shark::~cUnit_Shark()
{
}



INT cUnit_Shark::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_Shark::OnRenderUnit()
{
	INT hp = (m_Hp / 150.f) * 1232;

	RECT Rect = { 0, 0, hp, 32 };

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(0)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(1)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f), D3DXVECTOR2(1.f, 1.f), 0.f, &Rect);

	return 0;
}



INT cUnit_Shark::OnItemDrop(cData* pData)
{
	pData->AddObject(ItemFactory::Create(Item::Upgrade, m_Pos + D3DXVECTOR2(200.f, -100.f)));
	pData->AddObject(ItemFactory::Create(Item::GuidedTorpedo, m_Pos + D3DXVECTOR2(200.f, 100.f)));

	return 0;
}