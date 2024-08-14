#include "cSystem.h"



HWND cSystem::hWnd;
HINSTANCE cSystem::hInst;

POINT cSystem::WinSize;
D3DXVECTOR2 cSystem::fWinSize;

POINT cSystem::CenterPt;
D3DXVECTOR2 cSystem::fCenterPos;

std::chrono::duration<FLOAT> cSystem::ElapsedTime;
std::chrono::duration<FLOAT> cSystem::FrameRate;

BOOL cSystem::Exit = FALSE;

cInput cSystem::Input;
cCamera cSystem::Camera;

cMsgMgr cSystem::MsgMgr;

cResource cSystem::Resource;



cSystem::cSystem()
{
}

cSystem::~cSystem()
{
}



INT cSystem::Init(HWND hWnd, HINSTANCE hInst)
{
	this->hWnd = hWnd;
	this->hInst = hInst;

	WinSize.x = GetSystemMetrics(SM_CXSCREEN);
	WinSize.y = GetSystemMetrics(SM_CYSCREEN);
	fWinSize.x = static_cast<FLOAT>(GetSystemMetrics(SM_CXSCREEN));
	fWinSize.y = static_cast<FLOAT>(GetSystemMetrics(SM_CYSCREEN));

	CenterPt.x = WinSize.x / 2;
	CenterPt.y = WinSize.y / 2;
	fCenterPos.x = fWinSize.x / 2.f;
	fCenterPos.y = fWinSize.y / 2.f;

	return 0;
}


INT cSystem::FrameMove()
{
	Input.FrameMove();
	Camera.FrameMove();

	return 0;
}

INT cSystem::FrameMove_Limit()
{
	Input.FrameMove_Limit();

	return 0;
}



void cSystem::ExitProgram()
{
	Exit = TRUE;
}