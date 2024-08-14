#include "Util.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_OnceTorpedo.h"
#include "cWeapon_TripleTorpedo.h"
#include "cWeapon_GuidedTorpedo.h"
#include "cWeapon_Nuclear.h"

#include "cUnit_Player.h"



cUnit_Player::cUnit_Player()
	: cUnit(10.f)

	, m_pTimer(nullptr)

	, m_pChaos(nullptr)
	, m_pInk(nullptr)

	, m_Nuclear(1)
	, m_AddOn(0)

	, m_bChaos(FALSE)
	, m_bInk(FALSE)
{
	m_Scale = D3DXVECTOR2(0.85f, 0.85f);

	m_CollRect = { 105 - 128, 100 - 128, 170 - 128, 160 - 128 };

	this->Init(AI::Player, Team::Player, Unit::Player, 5, 0);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Player_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Player_Attack], 12, 36);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_OnceTorpedo);
	m_pWeaponList.push_back(new cWeapon_TripleTorpedo);
	m_pWeaponList.push_back(new cWeapon_GuidedTorpedo);
	m_pWeaponList.push_back(new cWeapon_Nuclear);
	m_CurrWeaponNum = 0;
}

cUnit_Player::~cUnit_Player()
{
	if (m_pTimer != nullptr)
	{
		SAFE_DELETE(m_pTimer);
	}
}



INT cUnit_Player::OnUpdateUnit(cData* pData)
{
	if (m_bSystemImmortal)
	{
		m_Color = D3DCOLOR_ARGB(100, 255, 255, 255);
	}

	else
	{
		if (m_pTimer == nullptr)
		{
			if (m_bImmortal)
			{
				m_pTimer = new cTimer(0, 3);
				m_pTimer->Play();
			}
		}

		else
		{
			m_pTimer->Update();

			if (m_pTimer->IsEnd())
			{
				m_bImmortal = FALSE;

				SAFE_DELETE(m_pTimer);
			}
		}

		if (m_bImmortal)
		{
			m_Color = D3DCOLOR_ARGB(255, 255, 0, 0);
		}

		else
		{
			m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);
		}
	}

	if (m_pChaos != nullptr)
	{
		m_pChaos->Update();

		if (m_pChaos->IsEnd())
		{
			m_bChaos = FALSE;
			SAFE_DELETE(m_pChaos);
		}
	}

	else
	{
		if (m_bChaos)
		{
			m_pChaos = new cTimer(0, 3);
			m_pChaos->Play();
		}
	}

	if (m_pInk != nullptr)
	{
		m_pInk->Update();

		if (m_pInk->IsEnd())
		{
			m_bInk = FALSE;
			SAFE_DELETE(m_pInk);
		}
	}

	else
	{
		if (m_bInk)
		{
			m_pInk = new cTimer(0, 3);
			m_pInk->Play();
		}
	}

	if (m_bChaos)
	{
		m_Color = D3DCOLOR_ARGB(255, 0, 0, 255);
	}

	return 0;
}

INT cUnit_Player::OnRenderUnit()
{
	INT hp = (m_Hp / 5.f) * 226;

	RECT Rect = {0, 0, hp, 32};

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(2)
		, m_Pos + D3DXVECTOR2(0, -100.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(3)
		, m_Pos + D3DXVECTOR2(0, -100.f), D3DXVECTOR2(1.f, 1.f), 0.f, &Rect);

	if (m_bInk)
	{
		cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_Ink]->GetTexture(0)
			, m_Pos);
	}

	return 0;
}



INT cUnit_Player::OnItemDrop(cData* pData)
{
	return 0;
}



INT cUnit_Player::NuclearCnt() const
{
	return m_Nuclear;
}


INT cUnit_Player::AddOnCnt() const
{
	return m_AddOn;
}



void cUnit_Player::AddNuclear(INT num)
{
	m_Nuclear += num;

	if (m_Nuclear > 5)
	{
		m_Nuclear = 5;
	}
}


BOOL cUnit_Player::AddOn(int num)
{
	m_AddOn += num;

	if (m_AddOn < 3)
	{
		return TRUE;
	}

	else
	{
		return FALSE;
	}
}



BOOL cUnit_Player::IsChaos() const
{
	return m_bChaos;
}

BOOL cUnit_Player::IsInk() const
{
	return m_bInk;
}



void cUnit_Player::SetChaos(BOOL bChaos)
{
	m_bChaos = bChaos;
}

void cUnit_Player::SetInk(BOOL bInk)
{
	m_bInk = bInk;
}