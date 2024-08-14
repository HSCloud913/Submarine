#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Kraken1.h"
#include "cWeapon_Kraken2.h"

#include "cUnit_Kraken.h"



cUnit_Kraken::cUnit_Kraken()
	: cUnit(0.f)
{
	m_Scale = D3DXVECTOR2(4.f, 4.f);

	m_CollRect = { 200 - 256, -350 - 256, 700 - 256, 337 - 256 };

	this->Init(AI::Kraken, Team::Enemy, Unit::Kraken, 300, 5000);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Kraken_Move], 48, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Kraken_Pattern1], 48, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Kraken_Move], 48, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Kraken_Pattern1], 48, 48);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Kraken1);
	m_pWeaponList.push_back(new cWeapon_Kraken2);
	m_CurrWeaponNum = 0;
}

cUnit_Kraken::~cUnit_Kraken()
{
}



INT cUnit_Kraken::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_Kraken::OnRenderUnit()
{
	INT hp = (m_Hp / 300.f) * 1232;

	RECT Rect = { 0, 0, hp, 32 };

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(0)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(1)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f), D3DXVECTOR2(1.f, 1.f), 0.f, &Rect);

	return 0;
}



INT cUnit_Kraken::OnItemDrop(cData* pData)
{
	return 0;
}