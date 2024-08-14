#include "Util.h"

#include "cFont.h"



cFont::cFont()
	: m_pFont(nullptr)
{
}

cFont::~cFont()
{
	CleanUp();
}



INT cFont::Create(LPCWSTR fontName, INT width, INT height)
{
	if (FAILED(D3DXCreateFontW(
		cD3DApp::Device.GetDevice()
		, height
		, width
		, FW_BOLD
		, 1
		, FALSE
		, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS
		, DEFAULT_QUALITY
		, DEFAULT_PITCH | FF_DONTCARE
		, fontName
		, &m_pFont)))
	{
		return Util::ErrorMessage(fontName);
	}

	m_Size.cx = width;
	m_Size.cy = height;

	return 0;
}

INT cFont::CleanUp()
{
	if (m_pFont != nullptr)
	{
		SAFE_RELEASE(m_pFont);
	}

	return 0;
}



INT cFont::ShowText(LPCWSTR str, INT x, INT y, DWORD color, DWORD dt)
{
	RECT Rect = { ((dt == DT_CENTER) ? x << 1 : x), y, -1, -1 };
	m_pFont->DrawTextW(nullptr, str, -1, &Rect, dt | DT_NOCLIP, color);

	return 0;
}

INT cFont::ShowText(LPCWSTR str, FLOAT fx, FLOAT fy, DWORD color, DWORD dt)
{
	INT x = static_cast<FLOAT>(fx);
	INT y = static_cast<FLOAT>(fy);

	RECT Rect = { ((dt == DT_CENTER) ? x << 1 : x), y, -1, -1 };
	m_pFont->DrawTextW(nullptr, str, -1, &Rect, dt | DT_NOCLIP, color);

	return 0;
}



SIZE cFont::GetStrSize(LPCWSTR str)
{
	SIZE Size;

	Size.cx = lstrlenW(str) * m_Size.cx;
	Size.cy = m_Size.cy;

	return Size;
}