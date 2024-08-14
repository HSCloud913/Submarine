#include <cstdio>
#include "Util.h"

#include "cSeqMgr.h"

#include "cEngine.h"



cEngine::cEngine()
	: m_pSystem(new cSystem)
	, m_pD3DApp(new cD3DApp)

	, m_pSeqMgr(new cSeqMgr)
{
}

cEngine::~cEngine()
{
	CleanUp();
}



INT cEngine::Create(HINSTANCE hInst, LPCWSTR name, BOOL bWindowed
	, INT width, INT height, WNDPROC wndProc)
{
	m_Name = name;

	m_Wc =
	{
		sizeof(WNDCLASSEX)
		, CS_CLASSDC
		, wndProc
		, 0L
		, 0L
		, GetModuleHandle(NULL)
		, NULL
		, NULL
		, (HBRUSH)GetStockObject(BLACK_BRUSH)
		, name
		, name
		, NULL
	};
	RegisterClassEx(&m_Wc);

	m_hWnd = CreateWindow
	(
		name
		, name
		, WS_POPUP | WS_VISIBLE
		, 0
		, 0
		, width
		, height
		, NULL
		, NULL
		, m_Wc.hInstance
		, NULL
	);

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);

	m_pSystem->Init(m_hWnd, hInst);
	m_pD3DApp->Init(bWindowed);

	cSystem::Resource.Init();

	m_pSeqMgr->Init();

	return 0;
}

INT cEngine::CleanUp()
{
	if (m_pD3DApp != nullptr)
	{
		SAFE_DELETE(m_pD3DApp);
	}

	if (m_pSystem != nullptr)
	{
		SAFE_DELETE(m_pSystem);
	}

	UnregisterClass(m_Name, m_Wc.hInstance);

	return 0;
}



INT cEngine::MainLoop()
{
#define DELAY 0.0166666666666
	std::chrono::system_clock::time_point BeginTime = std::chrono::system_clock::now();
	FLOAT ElapsedTime = 0.f;

	PeekMessage(&m_Msg, NULL, 0U, 0U, PM_REMOVE);

	while (m_Msg.message != WM_QUIT)
	{
		if (PeekMessage(&m_Msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&m_Msg);
			DispatchMessage(&m_Msg);
		}

		else
		{
			cSystem::ElapsedTime = std::chrono::system_clock::now() - BeginTime;
			cSystem::FrameRate = cSystem::ElapsedTime * 60.f;
			BeginTime = std::chrono::system_clock::now();

			m_pSystem->FrameMove();
			cSystem::MsgMgr.Update();
			
			m_pSeqMgr->Update();

			if (cSystem::Exit)
			{
				break;
			}

			ElapsedTime += cSystem::ElapsedTime.count();

			if (ElapsedTime >= DELAY)
			{
				ElapsedTime -= DELAY;

				m_pSystem->FrameMove_Limit();
				RenderLoop();
			}
		}
	}

	return 0;
}

INT cEngine::RenderLoop()
{
	cD3DApp::Device.GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET
		, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(cD3DApp::Device.GetDevice()->BeginScene()))
	{
		m_pSeqMgr->Render();
		cSystem::MsgMgr.Render();

		cD3DApp::Device.GetDevice()->EndScene();
	}

	cD3DApp::Device.GetDevice()->Present(NULL, NULL, NULL, NULL);

	return 0;
}



INT cEngine::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	cSystem::Input.MsgProc(hWnd, msg, wParam, lParam);

	if (msg == WM_KEYUP)
	{
		if (wParam == VK_SNAPSHOT)
		{
			Util::ScreenShot();
		}
	}

	return 0;
}