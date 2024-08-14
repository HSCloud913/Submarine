#include "Util.h"

#include "cInput.h"



cInput::cInput()
{
	memset(m_OldKey, 0, sizeof(m_OldKey));
	memset(m_CurrKey, 0, sizeof(m_CurrKey));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	GetKeyboardState(m_CurrKey);

	memset(m_OldMouse, 0, sizeof(m_OldMouse));
	memset(m_CurrMouse, 0, sizeof(m_CurrMouse));
	memset(m_MouseMap, 0, sizeof(m_MouseMap));
}

cInput::~cInput()
{
}



INT cInput::FrameMove()
{
	memcpy(m_OldKey, m_CurrKey, sizeof(m_OldKey));
	memset(m_CurrKey, 0, sizeof(m_CurrKey));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	GetKeyboardState(m_CurrKey);

	for (UINT i = 0; i < 256; i++)
	{
		BYTE VK = m_CurrKey[i] & 0x80;
		m_CurrKey[i] = (VK) ? 1 : 0;

		if (m_OldKey[i] == 1 && m_CurrKey[i] == 0)
		{
			m_KeyMap[i] = Up;
		}

		else if (m_OldKey[i] == 0 && m_CurrKey[i] == 1)
		{
			m_KeyMap[i] = Down;
		}

		else if (m_OldKey[i] == 1 && m_CurrKey[i] == 1)
		{
			m_KeyMap[i] = Press;
		}

		else
		{
			m_KeyMap[i] = None;
		}
	}


	POINT Cursor;
	::GetCursorPos(&Cursor);

	RECT WinRect;
	::GetWindowRect(cSystem::hWnd, &WinRect);

	memcpy(m_OldMouse, m_CurrMouse, sizeof(m_OldMouse));
	memset(m_CurrMouse, 0, sizeof(m_CurrMouse));
	memset(m_MouseMap, 0, sizeof(m_MouseMap));

	if (Cursor.x >= WinRect.left && Cursor.x <= WinRect.right &&
		Cursor.y >= WinRect.top && Cursor.x <= WinRect.bottom)
	{
		m_CurrMouse[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) ? 1 : 0;
		m_CurrMouse[1] = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) ? 1 : 0;
		m_CurrMouse[2] = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) ? 1 : 0;
	}

	else
	{
		m_CurrMouse[0] = None;
		m_CurrMouse[1] = None;
		m_CurrMouse[2] = None;
	}

	for (UINT i = 0; i < 8; i++)
	{
		if (m_OldMouse[i] == 1 && m_CurrMouse[i] == 0)
		{
			m_MouseMap[i] = Up;
		}

		else if (m_OldMouse[i] == 0 && m_CurrMouse[i] == 1)
		{
			m_MouseMap[i] = Down;
		}

		else if (m_OldMouse[i] == 1 && m_CurrMouse[i] == 1)
		{
			m_MouseMap[i] = Press;
		}
	}

	::ScreenToClient(cSystem::hWnd, &Cursor);

	m_vcCurr.x = static_cast<FLOAT>(Cursor.x);
	m_vcCurr.y = static_cast<FLOAT>(Cursor.y);

	m_vcEps = m_vcCurr - m_vcOld;
	m_vcOld.z = m_vcCurr.z;

	return 0;
}

INT cInput::FrameMove_Limit()
{	
	m_vcOld = m_vcCurr;

	return 0;
}


BOOL cInput::KeyUp(INT VK)
{
	return (m_KeyMap[VK] == Up);
}

BOOL cInput::KeyDown(INT VK)
{
	return (m_KeyMap[VK] == Down);

}

BOOL cInput::KeyPress(INT VK)
{
	return (m_KeyMap[VK] == Press);
}


INT cInput::KeyState(INT VK)
{
	return m_KeyMap[VK];
}



BOOL cInput::MouseUp(INT VK)
{
	return (m_MouseMap[(VK == VK_MBUTTON) ? 2 : VK - 1] == Up);
}

BOOL cInput::MouseDown(INT VK)
{
	return (m_MouseMap[(VK == VK_MBUTTON) ? 2 : VK - 1] == Down);
}

BOOL cInput::MousePress(INT VK)
{
	return (m_MouseMap[(VK == VK_MBUTTON) ? 2 : VK - 1] == Press);
}


INT cInput::MouseState(INT VK)
{
	return (m_MouseMap[(VK == VK_MBUTTON) ? 2 : VK - 1]);
}



D3DXVECTOR3 cInput::GetMousePos()
{
	D3DXVECTOR2 CamPos(0.f, 0.f);

	if (cD3DApp::Sprite.CameraCheck())
	{
		CamPos = *cSystem::Camera.Pos();
	}

	return D3DXVECTOR3(m_vcCurr.x + CamPos.x, m_vcCurr.y + CamPos.y, m_vcCurr.z);
}

D3DXVECTOR3 cInput::GetMouseEps()
{
	return m_vcEps;
}


POINT cInput::CursorPt()
{
	POINT Cursor;
	::GetCursorPos(&Cursor);
	::ScreenToClient(cSystem::hWnd, &Cursor);

	if (cD3DApp::Sprite.CameraCheck())
	{
		D3DXVECTOR2 CamPos = *cSystem::Camera.Pos();

		Cursor.x += static_cast<FLOAT>(CamPos.x);
		Cursor.y += static_cast<FLOAT>(CamPos.y);
	}

	return Cursor;
}

POINT cInput::RealCursorPt()
{
	POINT Cursor;
	::GetCursorPos(&Cursor);
	::ScreenToClient(cSystem::hWnd, &Cursor);

	return Cursor;
}


D3DXVECTOR2 cInput::fCursorPos()
{
	if (cD3DApp::Sprite.CameraCheck())
	{
		D3DXVECTOR2 CamPos = *cSystem::Camera.Pos();

		D3DXVECTOR2(m_vcCurr.x + CamPos.x, m_vcCurr.y + CamPos.y);
	}

	return D3DXVECTOR2(m_vcCurr.x, m_vcCurr.y);
}



INT cInput::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_MOUSEWHEEL)
	{
		INT z = HIWORD(wParam);

		m_vcCurr.z += static_cast<FLOAT>(z);
	}

	return 0;
}