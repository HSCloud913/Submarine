#include "Util.h"

#include "cTexture.h"

#include "cFade.h"



cFade::cFade(Fade::_Type fadeType, FLOAT speed)
	: m_FadeType(fadeType)
	, m_Speed(speed)

	, m_bEnd(FALSE)
{
	Init();
}

cFade::~cFade()
{
}



INT cFade::Init()
{
	if (m_FadeType == Fade::In || m_FadeType == Fade::InOut)
	{
		if (m_Speed > 0.f)
		{
			m_Speed *= -1.f;
		}

		m_Alpha = 255;
	}

	else
	{
		if (m_Speed < 0.f)
		{
			m_Speed *= -1.f;
		}

		m_Alpha = 0;
	}

	return 0;
}


INT cFade::Update()
{
	m_Alpha += VFR(m_Speed);

	if (m_Alpha > 255.f)
	{
		m_Alpha = 255.f;

		if (m_FadeType == Fade::OutIn)
		{
			m_Speed *= -1;
		}

		else
		{
			m_bEnd = TRUE;
		}
	}

	else if (m_Alpha < 0.f)
	{
		m_Alpha = 0.f;

		if (m_FadeType == Fade::InOut)
		{
			m_Speed *= -1;
		}

		else
		{
			m_bEnd = TRUE;
		}
	}

	return 0;
}

INT cFade::Render()
{
	cD3DApp::Sprite.CameraOff();

	cD3DApp::Sprite.SetColor(D3DCOLOR_ARGB(static_cast<INT>(m_Alpha), 255, 255, 255));
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Fade]->GetTexture(0), cSystem::fCenterPos);
	
	cD3DApp::Sprite.CameraOn();

	return 0;
}



BOOL cFade::GetAlpha() const
{
	return m_Alpha;
}



BOOL cFade::IsEnd() const
{
	return m_bEnd;
}