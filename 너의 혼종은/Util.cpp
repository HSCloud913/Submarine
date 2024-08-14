#include "Util.h"



INT Util::PushMessage(LPCWSTR fontName, LPCWSTR msg, DWORD color)
{
	return cSystem::MsgMgr.PushMessage(fontName, msg, color);
}

INT Util::ErrorMessage(LPCWSTR msg)
{
	MessageBox(nullptr, msg, L"Error", MB_OK);
	cSystem::ExitProgram();

	return 0;
}


INT Util::ScreenShot()
{
	LPDIRECT3DSURFACE9 pBackBuffer;

	if (SUCCEEDED(cD3DApp::Device.GetDevice()->GetBackBuffer(
		0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer)))
	{
		SYSTEMTIME SysTime;
		GetSystemTime(&SysTime);

		WCHAR Path[256];
		swprintf_s(Path, 255, L"ScreenShot/ScreenShot_%d%d%d%d.png"
			, SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wSecond);

		D3DXSaveSurfaceToFileW(Path, D3DXIFF_PNG, pBackBuffer, nullptr, nullptr);

		SAFE_RELEASE(pBackBuffer);
	}

	return 0;
}


INT Util::GetPosition(D3DXVECTOR2* pOut, FLOAT degree)
{
	pOut->x = sinf(D3DXToRadian(degree));
	pOut->y = -cosf(D3DXToRadian(degree));

	return 0;
}