#include "Util.h"

#include "cTexture.h"

#include "cButton.h"



cButton::cButton(cTexture* pTex, const D3DXVECTOR2& pos)
	: m_pTex(pTex)
	, m_State(None)
{
	m_Pos = pos;
}

cButton::~cButton()
{
}



INT cButton::Update()
{
	cD3DApp::Sprite.CameraOff();

	D3DXVECTOR2 Cursor = cSystem::Input.fCursorPos();
	
	if (Cursor.x >= m_Pos.x - m_pTex->Width() / 2 && Cursor.x <= m_Pos.x + m_pTex->Width() / 2 &&
		Cursor.y >= m_Pos.y - m_pTex->Height() / 2 && Cursor.y <= m_Pos.y + m_pTex->Height() / 2)
	{
		if (cSystem::Input.KeyDown(VK_LBUTTON))
		{
			m_State = Down;
		}

		else if (cSystem::Input.KeyUp(VK_LBUTTON))
		{
			m_State = Up;
		}

		else if (cSystem::Input.KeyPress(VK_LBUTTON))
		{
			m_Scale = D3DXVECTOR2(0.9f, 0.9f);
			m_State = Press;
		}
		
		else
		{
			m_Scale = D3DXVECTOR2(1.1f, 1.1f);
			m_State = Focus;
		}
	}

	else
	{
		m_Scale = D3DXVECTOR2(1.f, 1.f);
		m_State = None;
	}

	cD3DApp::Sprite.CameraOn();

	return 0;
}

INT cButton::Render()
{
	cD3DApp::Sprite.CameraOff();

	cD3DApp::Sprite.RenderTextureCenter(m_pTex, m_Pos, m_Scale);

	cD3DApp::Sprite.CameraOn();

	return 0;
}



BOOL cButton::IsFocus() const
{
	return (m_State == Focus);
}

BOOL cButton::IsUp() const
{
	return (m_State == Up);
}

BOOL cButton::IsDown() const
{
	return (m_State == Down);
}

BOOL cButton::IsPress() const
{
	return (m_State == Press);
}