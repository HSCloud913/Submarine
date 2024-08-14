#include "Util.h"

#include "cTexList.h"

#include "c2DAni.h"



c2DAni::c2DAni(cTexList* pTexList, INT frameNum, DWORD delay)
	: m_pTexList(pTexList)
	, m_FrameNum(frameNum)
	, m_Delay(delay)

	, m_PrevTime(timeGetTime())
	, m_CurrFrame(0)

	, m_bPlay(FALSE)
	, m_bEnd(FALSE)
{
}

c2DAni::~c2DAni()
{
}



INT c2DAni::Update()
{
	if (m_bPlay)
	{
		if (timeGetTime() - m_PrevTime >= m_Delay)
		{
			if (m_bEnd)
			{
				m_bEnd = FALSE;
			}

			m_CurrFrame++;

			if (m_CurrFrame >= m_FrameNum)
			{
				m_CurrFrame = 0;
				m_bEnd = TRUE;
			}

			m_PrevTime = timeGetTime();
		}
	}

	return 0;
}

INT c2DAni::Render()
{
	cD3DApp::Sprite.RenderTextureCenter(m_pTexList->GetTexture(m_CurrFrame)
		, m_Pos, m_Scale, m_Angle);

	return 0;
}



INT c2DAni::Play()
{
	m_bPlay = TRUE;

	return 0;
}

INT c2DAni::Pause()
{
	m_bPlay = FALSE;

	return 0;
}

INT c2DAni::Stop()
{
	m_CurrFrame = 0;
	m_bPlay = FALSE;

	return 0;
}


INT c2DAni::GetCurrFrame() const
{
	return m_CurrFrame;
}

void c2DAni::SetCurrFrame(INT frame)
{
	m_CurrFrame = frame;
}



BOOL c2DAni::IsEnd() const
{
	return m_bEnd;
}