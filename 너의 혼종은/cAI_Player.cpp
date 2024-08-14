#include "Util.h"

#include "cSound.h"

#include "cUnit.h"
#include "cUnit_Player.h"

#include "c2DAniList.h"

#include "cWeapon.h"

#include "cAI_Player.h"



cAI_Player::cAI_Player(cUnit* pUnit)
	: cAI(pUnit)
{
}

cAI_Player::~cAI_Player()
{
}



INT cAI_Player::OnUpdate(cData* pData)
{
	cUnit_Player* pPlayer = dynamic_cast<cUnit_Player*>(m_pUnit);
	
	D3DXVECTOR2 Control(0.f, 0.f);

	if (cSystem::Input.KeyDown(VK_F1))
	{
		m_pUnit->SetSystemImmortal();
	}

	if (cSystem::Input.KeyDown(VK_F2))
	{
		m_pUnit->SetCurrWeaponNum(1);
	}

	if (cSystem::Input.KeyDown(VK_F3))
	{
		m_pUnit->SetCurrWeaponNum(2);
	}

	if (cSystem::Input.KeyDown('B'))
	{
		if (pPlayer->NuclearCnt() > 0)
		{
			INT SaveWeapon = m_pUnit->GetCurrWeaponNum();

			m_pUnit->SetCurrWeaponNum(3);

			if (m_pUnit->UseWeapon(pData, 90.f) != -1)
			{
				cSystem::Resource.m_pSoundList[0]->GetSound(3)->Stop();
				pPlayer->AddNuclear(-1);
				cSystem::Resource.m_pSoundList[0]->GetSound(3)->Play(FALSE);
			}

			else
			{
				Util::PushMessage(L"µ¸¿ò", L"ÄðÅ¸ÀÓ ÀÔ´Ï´Ù", D3DCOLOR_ARGB(255, 255, 0, 0));
			}

			m_pUnit->SetCurrWeaponNum(SaveWeapon);
		}

		else
		{
			Util::PushMessage(L"µ¸¿ò", L"ÇÙ ¹Ì»çÀÏÀÌ ºÎÁ·ÇÕ´Ï´Ù", D3DCOLOR_ARGB(255, 255, 0, 0));
		}
	}

	if (m_pUnit->GetAniList()->IsLock())
	{
		if (m_pUnit->GetAniList()->GetCurrFrame() == 7)
		{
			if (m_pUnit->GetCurrWeaponNum() == 2)
			{
				m_pUnit->SetCurrWeaponNum(1);
				m_pUnit->UseWeapon(pData, 90.f);

				m_pUnit->SetCurrWeaponNum(2);
				m_pUnit->UseWeapon(pData, 90.f);
			}

			else
			{
				m_pUnit->UseWeapon(pData, 90.f);
			}
		}

		if (m_pUnit->GetAniList()->IsEnd())
		{
			m_pUnit->GetAniList()->UnLock();
		}
	}

	if (cSystem::Input.KeyPress(VK_LEFT))
	{
		if (pPlayer->IsChaos())
		{
			if (m_pUnit->Pos()->x <= 1915.f)
			{
				Control.x += 1.f;
			}
		}

		else
		{
			if (m_pUnit->Pos()->x >= 5.f)
			{
				Control.x += -1.f;
			}
		}
	}

	if (cSystem::Input.KeyPress(VK_RIGHT))
	{
		if (pPlayer->IsChaos())
		{
			if (m_pUnit->Pos()->x >= 5.f)
			{
				Control.x += -1.f;
			}
		}

		else
		{
			if (m_pUnit->Pos()->x <= 1915.f)
			{
				Control.x += 1.f;
			}
		}
	}

	if (cSystem::Input.KeyPress(VK_UP))
	{
		if (pPlayer->IsChaos())
		{
			if (m_pUnit->Pos()->y <= 1075.f)
			{
				Control.y += 1.f;
			}
		}

		else
		{
			if (m_pUnit->Pos()->y >= 5.f)
			{
				Control.y += -1.f;
			}
		}
	}

	if (cSystem::Input.KeyPress(VK_DOWN))
	{
		if (pPlayer->IsChaos())
		{
			if (m_pUnit->Pos()->y >= 5.f)
			{
				Control.y += -1.f;
			}
		}

		else
		{
			if (m_pUnit->Pos()->y <= 1075.f)
			{
				Control.y += 1.f;
			}
		}
	}

	if (Control.x != 0.f || Control.y != 0.f)
	{
		D3DXVec2Normalize(&Control, &Control);
		Control *= m_pUnit->GetMoveSpeed();
	}

	m_pUnit->SetSpeed(&Control);

	m_pUnit->GetAniList()->SetCurrAniNum(0);
	m_pUnit->GetAniList()->Play();

	if (cSystem::Input.KeyPress(VK_SPACE))
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(3)->Stop();

		m_pUnit->GetAniList()->SetCurrAniNum(1);
		m_pUnit->GetAniList()->Play();
		m_pUnit->GetAniList()->Lock();

		cSystem::Resource.m_pSoundList[0]->GetSound(3)->Play(FALSE);
	}

	return 0;
}