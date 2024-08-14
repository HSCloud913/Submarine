#include <cstdlib>
#include "Util.h"

#include "cUnit.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cAI_Ray.h"



cAI_Ray::cAI_Ray(cUnit* pUnit)
	: cAI(pUnit)

	, m_pPattern1(new cTimer(0, 3))
	, m_pPattern2(new cTimer(0, 8))

	, m_pRush(nullptr)

	, m_bMove(FALSE)
	, m_Num(-1)
{
	srand((UINT)timeGetTime());

	m_pPattern1->Play();
	m_pPattern2->Play();
}

cAI_Ray::~cAI_Ray()
{
}



INT cAI_Ray::OnUpdate(cData* pData)
{
	if (m_pPattern1 != nullptr)
	{
		m_pPattern1->Update();
	}

	if (m_pPattern2 != nullptr)
	{
		m_pPattern2->Update();
	}

	if (m_pRush != nullptr)
	{
		m_pRush->Update();
		
		if (m_pRush->IsEnd())
		{
			m_bMove = FALSE;

			SAFE_DELETE(m_pRush);
		}
	}

	if (m_pUnit->GetAniList()->IsLock())
	{
		if (m_pUnit->GetAniList()->GetCurrAniNum() == 1)
		{
			if (m_pUnit->GetAniList()->GetCurrFrame() == 23 ||
				m_pUnit->GetAniList()->GetCurrFrame() == 36)
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
		}

		if (m_pUnit->GetAniList()->GetCurrAniNum() == 2)
		{
			if (m_pUnit->GetAniList()->GetCurrFrame() == 30)
			{
				m_bMove = TRUE;
				m_Num = rand() % 3;

				m_pRush = new cTimer(0, 3);
				m_pRush->Play();
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

			m_pPattern2 = new cTimer(0, 8);
			m_pPattern2->Play();
		}

		else
		{
			m_pUnit->GetAniList()->SetCurrAniNum(0);
			m_pUnit->GetAniList()->Play();
		}
	}

	if (m_bMove)
	{
		if (m_pUnit->Pos()->x > 300.f)
		{
			m_pUnit->AddXPos(VFR(-20.f));
		}

		if (m_Num == 0)
		{
			if (m_pUnit->Pos()->y > 100.f)
			{
				m_pUnit->AddYPos(VFR(-10.f));
			}
		}

		else if (m_Num == 2)
		{
			if (m_pUnit->Pos()->y < 980.f)
			{
				m_pUnit->AddYPos(VFR(10.f));
			}
		}	
	}

	else
	{
		if (m_pUnit->Pos()->x < 1500.f)
		{
			m_pUnit->AddXPos(VFR(20.f));
		}

		if (m_Num == 0)
		{
			if (m_pUnit->Pos()->y < cSystem::fCenterPos.y)
			{
				m_pUnit->AddYPos(VFR(10.f));
			}
		}

		else if (m_Num == 2)
		{
			if (m_pUnit->Pos()->y > cSystem::fCenterPos.y)
			{
				m_pUnit->AddYPos(VFR(-10.f));
			}
		}
	}

	return 0;
}