#include "Util.h"

#include "cUnit.h"

#include "cGameData.h"

#include "cTimer.h"

#include "cUnit_Player.h"

#include "c2DAniList.h"

#include "cAI_Whale.h"



cAI_Whale::cAI_Whale(cUnit* pUnit)
	: cAI(pUnit)

	, m_pPattern1(new cTimer(0, 3))
	, m_pPattern2(new cTimer(0, 10))

	, m_Attack(FALSE)
{
	m_pPattern1->Play();
	m_pPattern2->Play();
}

cAI_Whale::~cAI_Whale()
{
}



INT cAI_Whale::OnUpdate(cData* pData)
{
	if (m_pPattern1 != nullptr)
	{
		m_pPattern1->Update();
	}

	if (m_pPattern2 != nullptr)
	{
		m_pPattern2->Update();
	}

	if (m_pUnit->GetAniList()->IsLock())
	{
		if (m_pUnit->GetAniList()->GetCurrAniNum() == 1)
		{
			if (m_pUnit->GetAniList()->GetCurrFrame() == 19)
			{
				m_Attack = TRUE;
			}

			if (m_pUnit->GetAniList()->GetCurrFrame() == 33)
			{
				m_Attack = FALSE;
			}
		}

		if (m_pUnit->GetAniList()->GetCurrAniNum() == 2)
		{
			cGameData* pGameData = dynamic_cast<cGameData*>(pData);

			if (pGameData != nullptr)
			{
				if (pGameData->GetPlayer() != nullptr)
				{
					pGameData->GetPlayer()->SetChaos();
				}
			}
		}

		if (m_pUnit->GetAniList()->IsEnd())
		{
			m_pUnit->GetAniList()->UnLock();
		}
	}

	else
	{
		if (m_pPattern1->IsEnd())
		{
			m_pUnit->GetAniList()->SetCurrAniNum(1);
			m_pUnit->GetAniList()->Play();
			m_pUnit->GetAniList()->Lock();

			SAFE_DELETE(m_pPattern1);

			m_pPattern1 = new cTimer(0, 3);
			m_pPattern1->Play();
		}

		else if (m_pPattern2->IsEnd())
		{
			m_pUnit->GetAniList()->SetCurrAniNum(2);
			m_pUnit->GetAniList()->Play();
			m_pUnit->GetAniList()->Lock();

			SAFE_DELETE(m_pPattern2);

			m_pPattern2 = new cTimer(0, 10);
			m_pPattern2->Play();
		}

		else
		{
			m_pUnit->GetAniList()->SetCurrAniNum(0);
			m_pUnit->GetAniList()->Play();
		}
	}

	if (m_Attack)
	{
		if (m_pUnit->GetEnemyPos() != nullptr)
		{
			FLOAT fx, fy, fRadian;

			fx = m_pUnit->GetEnemyPos()->x - m_pUnit->Pos()->x;
			fy = m_pUnit->GetEnemyPos()->y - m_pUnit->Pos()->y;

			fRadian = atan2f(fy, fx);

			m_pUnit->UseWeapon(pData, D3DXToDegree(fRadian) + 90.f);
		}
	}

	return 0;
}