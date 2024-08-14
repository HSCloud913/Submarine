#pragma once
#include <d3dx9.h>
#include <chrono>

#include "cCamera.h"
#include "cInput.h"

#include "cMsgMgr.h"

#include "cResource.h"

class cSystem
{
public:
	cSystem();
	~cSystem();

public:
	static HWND hWnd;
	static HINSTANCE hInst;

public:
	static POINT WinSize;
	static D3DXVECTOR2 fWinSize;

	static POINT CenterPt;
	static D3DXVECTOR2 fCenterPos;

public:
	static std::chrono::duration<FLOAT> ElapsedTime;
	static std::chrono::duration<FLOAT> FrameRate;

public:
	static BOOL Exit;

public:
	static cInput Input;
	static cCamera Camera;

public:
	static cMsgMgr MsgMgr;

public:
	static cResource Resource;

public:
	INT Init(HWND hWnd, HINSTANCE hInst);

	INT FrameMove();
	INT FrameMove_Limit();

public:
	static void ExitProgram();
};