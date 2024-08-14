#include "Util.h"

#include "cFade.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Cinematic.h"



cSeq_Cinematic::cSeq_Cinematic()
	: m_pFade(new cFade(Fade::In, 5.f))
	, m_FilmPos(0.f, 0.f)
	, m_FilmTargetXPos(0.f)
	, m_FilmCount(1)

	, m_bExit(FALSE)
{
}

cSeq_Cinematic::~cSeq_Cinematic()
{
}



INT cSeq_Cinematic::OnInit()
{
	return 0;
}

INT cSeq_Cinematic::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Cinematic::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (m_pFade != nullptr)
	{	
		m_pFade->Update();

		if (m_pFade->IsEnd())
		{
			SAFE_DELETE(m_pFade);

			if (m_bExit)
			{
				return new cSeq_MainMenu;
			}
		}
	}

	else
	{
		if (cSystem::Input.KeyDown(VK_SPACE))
		{
			if (m_FilmCount < 5)
			{
				m_FilmTargetXPos -= 1920.f;
				m_FilmCount++;
			}
		}

		if (m_FilmCount == 5)
		{
			m_bExit = TRUE;
		}
	}

	m_FilmPos.x += VFR((m_FilmTargetXPos - m_FilmPos.x) / 15.f);

	if (m_bExit)
	{
		if (m_FilmTargetXPos - m_FilmPos.x >= -10.f)
		{
			if (m_pFade == nullptr)
			{
				m_pFade = new cFade(Fade::Out, 2.5f);
			} 
		}
	}

	return pNextSeq;
}

INT cSeq_Cinematic::OnRender()
{
	cD3DApp::Sprite.RenderTexture(
		cSystem::Resource.m_pTexList[TexList_Cinematic]->GetTexture(0), m_FilmPos);

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}