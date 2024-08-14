#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Ray.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Ray.h"



cUnit_Ray::cUnit_Ray()
	: cUnit(0.f)
{
	m_Scale = D3DXVECTOR2(2.f, 2.f);

	m_CollRect = { -150 - 256, 200 - 256, 400 - 256, 350 - 256 };

	this->Init(AI::Ray, Team::Enemy, Unit::Ray, 100, 2000);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Ray_Move], 36, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Ray_Pattern1], 60, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Ray_Pattern2], 60, 24);
	m_pAniList->SetCurrAniNum(2);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Ray);
	m_CurrWeaponNum = 0;
}
cUnit_Ray::~cUnit_Ray()
{
}



INT cUnit_Ray::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_Ray::OnRenderUnit()
{
	INT hp = (m_Hp / 100.f) * 1232;

	RECT Rect = { 0, 0, hp, 32 };

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(0)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(1)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f), D3DXVECTOR2(1.f, 1.f), 0.f, &Rect);

	return 0;
}



INT cUnit_Ray::OnItemDrop(cData* pData)
{
	pData->AddObject(ItemFactory::Create(Item::TripleTorpedo, m_Pos + D3DXVECTOR2(200.f, -100.f)));
	pData->AddObject(ItemFactory::Create(Item::Nuclear, m_Pos + D3DXVECTOR2(200.f, 100.f)));

	return 0;
}