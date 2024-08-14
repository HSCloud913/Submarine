#include "Util.h"

#include "c2DAni.h"
#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Whale.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Whale.h"



cUnit_Whale::cUnit_Whale()
	: cUnit(0.f)

	, m_pAni(nullptr)

	, m_Count(0.f)
{
	m_Scale = D3DXVECTOR2(4.f, 4.f);

	m_CollRect = { -600 - 256, 150 - 256, 800 - 256, 550 - 256 };

	this->Init(AI::Whale, Team::Enemy, Unit::Whale, 200, 4000);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Whale_Move], 48, 24);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Whale_Pattern1], 48, 36);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Whale_Pattern2], 48, 36);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Whale);
	m_CurrWeaponNum = 0;
}

cUnit_Whale::~cUnit_Whale()
{
}



INT cUnit_Whale::OnUpdateUnit(cData* pData)
{
	if (m_pAniList->GetCurrAniNum() == 2)
	{
		if (m_pAniList->GetCurrFrame() == 14)
		{
			m_pAni = new c2DAni(cSystem::Resource.m_pTexList[TexList_Effect_SonicWave], 24, 36);
			m_pAni->SetPos(m_Pos.x - 300.f, m_Pos.y);
			m_pAni->SetScale(5.f, 5.f);
			m_pAni->Play();
		}
	}

	if (m_pAni != nullptr)
	{
		m_pAni->AddXPos(-VFR(10.f));

		m_pAni->Update();

		if (m_pAni->IsEnd())
		{
			m_Count += VFR(1.f);

			if (m_Count >= 5.f)
			{
				m_Count = 0.f;

				SAFE_DELETE(m_pAni);
			}
		}
	}

	return 0;
}

INT cUnit_Whale::OnRenderUnit()
{
	if (m_pAni != nullptr)
	{
		m_pAni->Render();
	}

	INT hp = (m_Hp / 200.f) * 1232;

	RECT Rect = { 0, 0, hp, 32 };

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(0)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(1)
		, D3DXVECTOR2(cSystem::fCenterPos.x, 24.f), D3DXVECTOR2(1.f, 1.f), 0.f, &Rect);

	return 0;
}



INT cUnit_Whale::OnItemDrop(cData* pData)
{
	return 0;
}