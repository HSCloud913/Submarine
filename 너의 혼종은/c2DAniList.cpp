#include "Util.h"

#include "cTexList.h"
#include "c2DAni.h"

#include "c2DAniList.h"



c2DAniList::c2DAniList()
	: m_CurrAniNum(-1)
	, m_bLock(FALSE)
{
	m_pAniList.clear();
}

c2DAniList::~c2DAniList()
{
	for (UINT i = 0; i < m_pAniList.size(); i++)
	{
		SAFE_DELETE(m_pAniList[i]);
	}

	m_pAniList.clear();
}



INT c2DAniList::Update()
{
	for (UINT i = 0; i < m_pAniList.size(); i++)
	{
		m_pAniList[i]->SetPos(&m_Pos);
		m_pAniList[i]->SetScale(&m_Scale);
		m_pAniList[i]->SetAngle(m_Angle);
	}

	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->Update();

		if (m_bLock && m_pAniList[m_CurrAniNum]->IsEnd())
		{
			m_bLock = FALSE;
		}
	}

	return 0;
}

INT c2DAniList::Render()
{
	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->Render();
	}

	return 0;
}



INT c2DAniList::AddAni(cTexList* pTexList, INT frameNum, DWORD delay)
{
	m_pAniList.push_back(new c2DAni(pTexList, frameNum, delay));

	return 0;
}



INT c2DAniList::Play()
{
	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->Play();
	}

	return 0;
}

INT c2DAniList::Pause()
{
	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->Pause();
	}

	return 0;
}

INT c2DAniList::Stop()
{
	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->Stop();
	}

	return 0;
}



INT c2DAniList::GetCurrFrame() const
{
	if (m_CurrAniNum > -1)
	{
		return m_pAniList[m_CurrAniNum]->GetCurrFrame();
	}

	return -1;
}

void c2DAniList::SetCurrFrame(INT frame)
{
	if (m_CurrAniNum > -1)
	{
		m_pAniList[m_CurrAniNum]->SetCurrFrame(frame);
	}
}



INT c2DAniList::GetCurrAniNum() const
{
	return m_CurrAniNum;
}

void c2DAniList::SetCurrAniNum(INT aniNum)
{
	if (!m_bLock && m_CurrAniNum != aniNum)
	{
		if (m_CurrAniNum > -1)
		{
			m_pAniList[m_CurrAniNum]->Stop();
		}

		m_CurrAniNum = aniNum;
	}
}



void c2DAniList::Lock()
{
	m_bLock = TRUE;
}

void c2DAniList::UnLock()
{
	m_bLock = FALSE;
}

BOOL c2DAniList::IsLock() const
{
	return m_bLock;
}



BOOL c2DAniList::IsEnd() const
{
	if (m_CurrAniNum > -1)
	{
		return m_pAniList[m_CurrAniNum]->IsEnd();
	}

	return TRUE;
}