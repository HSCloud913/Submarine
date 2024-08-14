#include "Util.h"
#include "cEngine.h"



cEngine* g_pEngine = new cEngine;



LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	g_pEngine->MsgProc(hWnd, msg, wParam, lParam);

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	g_pEngine->Create(hInst, L"³ÊÀÇ È¥Á¾Àº", FALSE, 1920, 1080, WndProc);
	g_pEngine->MainLoop();

	SAFE_DELETE(g_pEngine);

	return 0;
}