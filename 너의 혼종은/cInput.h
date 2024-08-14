#pragma once
#include <d3dx9.h>

class cInput
{
public:
	cInput();
	~cInput();

private:
	enum State
	{
		None
		, Up
		, Down
		, Press
	};

private:
	BYTE m_OldKey[256];
	BYTE m_CurrKey[256];
	BYTE m_KeyMap[256];

private:
	BYTE m_OldMouse[8];
	BYTE m_CurrMouse[8];
	BYTE m_MouseMap[8];

private:
	D3DXVECTOR3 m_vcOld;
	D3DXVECTOR3 m_vcCurr;
	D3DXVECTOR3 m_vcEps;

public:
	INT FrameMove();
	INT FrameMove_Limit();

public:
	BOOL KeyUp(INT VK);
	BOOL KeyDown(INT VK);
	BOOL KeyPress(INT VK);

	INT KeyState(INT VK);

public:
	BOOL MouseUp(INT VK);
	BOOL MouseDown(INT VK);
	BOOL MousePress(INT VK);

	INT MouseState(INT VK);

public:
	D3DXVECTOR3 GetMousePos();
	D3DXVECTOR3 GetMouseEps();

	POINT CursorPt();
	POINT RealCursorPt();

	D3DXVECTOR2 fCursorPos();
	
public:
	INT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};