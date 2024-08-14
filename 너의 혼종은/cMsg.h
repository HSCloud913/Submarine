#pragma once
#include <d3dx9.h>

class c2DLine;
class cFont;

class cMsg
{
public:
	cMsg(LPCWSTR fontName, LPCWSTR msg, DWORD color);
	~cMsg();

private:
	c2DLine* m_pLine;
	cFont* m_pFont;

private:
	LPCWSTR m_Msg;
	DWORD m_Color;

private:
	D3DXVECTOR2 m_Point;
	D3DXVECTOR2 m_Pos;

private:
	FLOAT m_ShowTime;
	FLOAT m_Speed;

public:
	INT Update();
	INT Render();

public:
	void AddYPos(FLOAT y);
	FLOAT GetShowTime() const;
};