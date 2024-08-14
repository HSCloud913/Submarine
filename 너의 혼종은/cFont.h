#pragma once
#include <d3dx9.h>

class cFont
{
public:
	cFont();
	~cFont();

private:
	LPD3DXFONT m_pFont;
	SIZE m_Size;

public:
	INT Create(LPCWSTR fontName, INT width, INT height);
	INT CleanUp();

public:
	INT ShowText(LPCWSTR str, INT x, INT y, DWORD color, DWORD dt = 0x00000000);
	INT ShowText(LPCWSTR str, FLOAT fx, FLOAT fy, DWORD color, DWORD dt = 0x00000000);

public:
	SIZE GetStrSize(LPCWSTR str);
};