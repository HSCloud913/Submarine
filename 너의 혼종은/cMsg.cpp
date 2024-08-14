#include "Util.h"

#include "c2DLine.h"
#include "cFont.h"

#include "cMsg.h"



cMsg::cMsg(LPCWSTR fontName, LPCWSTR msg, DWORD color)
	: m_pLine(new c2DLine)
	, m_pFont(new cFont)

	, m_Msg(msg)
	, m_Color(color)

	, m_ShowTime(500.f)
	, m_Speed(0.f)
{
	m_pLine->Create();
	m_pLine->SetWidth(4.5f);
	m_pFont->Create(fontName, 15, 30);

	m_Point.x = m_pFont->GetStrSize(m_Msg).cx * 2;
	m_Point.y = m_pFont->GetStrSize(m_Msg).cy;

	m_Pos.x = cSystem::fWinSize.x - m_Point.x - 30.f;
	m_Pos.y = cSystem::fWinSize.y * 0.65;
}

cMsg::~cMsg()
{
	if (m_pLine != nullptr)
	{
		SAFE_DELETE(m_pLine);
	}

	if (m_pFont != nullptr)
	{
		SAFE_DELETE(m_pFont);
	}
}



INT cMsg::Update()
{
	m_ShowTime -= VFR(5.f);

	if (m_ShowTime < 0.f)
	{
		m_ShowTime = 0.f;
	}

	if (m_ShowTime <= 255.f)
	{
		m_Speed += VFR(0.1f);
		m_Pos.y -= VFR(m_Speed);
	}

	return 0;
}

INT cMsg::Render()
{
	cD3DApp::Sprite.CameraOff();

	INT Alpha = static_cast<INT>(m_ShowTime);

	if (Alpha > 255)
	{
		Alpha = 255;
	}

	if (Alpha < 0)
	{
		Alpha = 0;
	}

	DWORD Color = m_Color & 0x00ffffff | (Alpha << 24) & 0xff000000;

	D3DXVECTOR2 VtxList[5] =
	{
		m_Pos + D3DXVECTOR2(-10.f, -10.f)
		, m_Pos + D3DXVECTOR2(m_Point.x, 0.f) + D3DXVECTOR2(10.f, -10.f)
		, m_Pos + m_Point + D3DXVECTOR2(10.f, 10.f)
		, m_Pos + D3DXVECTOR2(0.f, m_Point.y) + D3DXVECTOR2(-10.f, 10.f)
		, VtxList[0]
	};

	m_pLine->RenderLine(VtxList, 5, Color);
	m_pFont->ShowText(m_Msg, m_Pos.x, m_Pos.y, D3DCOLOR_ARGB(Alpha, 255, 255, 255));

	cD3DApp::Sprite.CameraOn();

	return 0;
}



void cMsg::AddYPos(FLOAT y)
{
	if (m_ShowTime > 255.f)
	{
		m_Pos.y -= y;
	}
}

FLOAT cMsg::GetShowTime() const
{
	return m_ShowTime;
}