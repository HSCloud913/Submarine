#include "Util.h"

#include "cUnit.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cAI_P_Cme.h"



cAI_P_Cme::cAI_P_Cme(cUnit* pUnit)
	: cAI(pUnit)

	, m_pTimer(new cTimer(0, 3))
{
	m_pTimer->Play();
}

cAI_P_Cme::~cAI_P_Cme()
{
}



INT cAI_P_Cme::OnUpdate(cData* pData)
{
	if (m_pTimer != nullptr)
	{
		m_pTimer->Update();
	}

	if (m_pUnit->GetAniList()->IsLock())
	{
		if (m_pUnit->GetAniList()->GetCurrFrame() == 19)
		{
			if (m_pUnit->GetEnemyPos() != nullptr)
			{
				if (m_pUnit->Pos()->x > -50.f)
				{
					FLOAT fx, fy, fRadian;

					fx = m_pUnit->GetEnemyPos()->x - m_pUnit->Pos()->x;
					fy = m_pUnit->GetEnemyPos()->y - m_pUnit->Pos()->y;

					fRadian = atan2f(fy, fx);

					m_pUnit->UseWeapon(pData, D3DXToDegree(fRadian) + 90.f);
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
		if (m_pTimer->IsEnd())
		{
			m_pUnit->GetAniList()->SetCurrAniNum(1);
			m_pUnit->GetAniList()->Play();
			m_pUnit->GetAniList()->Lock();

			SAFE_DELETE(m_pTimer);

			m_pTimer = new cTimer(0, 3);
			m_pTimer->Play();
		}

		else
		{
			m_pUnit->GetAniList()->SetCurrAniNum(0);
			m_pUnit->GetAniList()->Play();
		}
	}

	return 0;
}