#include "Util.h"

#include "cUnit.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cAI_Y_Puffer.h"



cAI_Y_Puffer::cAI_Y_Puffer(cUnit* pUnit)
	: cAI(pUnit)
	, m_pTimer(new cTimer(0, 5))
{
	m_pTimer->Play();
}

cAI_Y_Puffer::~cAI_Y_Puffer()
{
}



INT cAI_Y_Puffer::OnUpdate(cData* pData)
{
	if (m_pTimer != nullptr)
	{
		m_pTimer->Update();
	}

	if (m_pUnit->GetAniList()->IsLock())
	{
		if (m_pUnit->GetAniList()->GetCurrFrame() == 19)
		{
			m_pUnit->UseWeapon(pData, -90.f);
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

			m_pTimer = new cTimer(0, 5);
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