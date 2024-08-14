#pragma once
#include <Windows.h>

class cSystem;
class cD3DApp;

class cSeqMgr;

class cEngine
{
public:
	cEngine();
	~cEngine();

private:
	cSystem* m_pSystem;
	cD3DApp* m_pD3DApp;

private:
	cSeqMgr* m_pSeqMgr;

private:
	LPCWSTR m_Name;
	HWND m_hWnd;

private:
	WNDCLASSEX m_Wc;
	MSG m_Msg;

public:
	INT Create(HINSTANCE hInst, LPCWSTR name, BOOL bWindowed
		, INT width, INT height, WNDPROC wndProc);
	INT CleanUp();

	INT MainLoop();
	INT RenderLoop();

public:
	INT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};