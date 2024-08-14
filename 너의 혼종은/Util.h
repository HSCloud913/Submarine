#pragma once
#include "cSystem.h"
#include "cD3DApp.h"

#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }

#define VFR(x) ((x) * cSystem::FrameRate.count())
#define VFR2X(x) ((x) * cSystem::FrameRate.count() * 2.f)
#define VFR4X(x) ((x) * cSystem::FrameRate.count() * 4.f)

namespace Util
{
	INT PushMessage(LPCWSTR fontName, LPCWSTR msg, DWORD color);
	INT ErrorMessage(LPCWSTR msg);

	INT ScreenShot();

	INT GetPosition(D3DXVECTOR2* pOut, FLOAT degree);
}