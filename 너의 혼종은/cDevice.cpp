#include "Util.h"

#include "cDevice.h"



cDevice::cDevice()
	: m_pD3D(nullptr)
	, m_pd3dDevice(nullptr)
{
}

cDevice::~cDevice()
{
}



INT cDevice::Create(BOOL bWindowed)
{
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return Util::ErrorMessage(L"Direct3DCreate9");
	}

	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));

	m_d3dpp.Windowed = TRUE;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	m_d3dpp.BackBufferCount = 1;
	m_d3dpp.BackBufferWidth = cSystem::WinSize.x;
	m_d3dpp.BackBufferHeight = cSystem::WinSize.y;
	m_d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;

	m_d3dpp.EnableAutoDepthStencil = TRUE;
	m_d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//풀 신 안티 체크
	DWORD level;

	for (int i = D3DMULTISAMPLE_16_SAMPLES; i >= D3DMULTISAMPLE_2_SAMPLES; i--)
	{
		if (SUCCEEDED(m_pD3D->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL, D3DFMT_D24S8, FALSE, (D3DMULTISAMPLE_TYPE)i, &level)))
		{
			m_d3dpp.MultiSampleQuality = level - 1;
			m_d3dpp.MultiSampleType = (D3DMULTISAMPLE_TYPE)i;

			break;
		}
	}

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, cSystem::hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING, &m_d3dpp, &m_pd3dDevice)))
	{
		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, cSystem::hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_d3dpp, &m_pd3dDevice)))
		{
			return Util::ErrorMessage(L"CreateDevice");
		}
	}

	D3DCAPS9 d3dCaps;
	m_pd3dDevice->GetDeviceCaps(&d3dCaps);

	m_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC);
	m_pd3dDevice->SetSamplerState(0, D3DSAMP_MAXANISOTROPY, d3dCaps.MaxAnisotropy);

	m_pd3dDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_ALPHAREF, 0x00000088);
	m_pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	return 0;
}

INT cDevice::CleanUp()
{
	if (m_pd3dDevice != nullptr)
	{
		SAFE_RELEASE(m_pd3dDevice);
	}

	if (m_pD3D != nullptr)
	{
		SAFE_RELEASE(m_pD3D);
	}

	return 0;
}



LPDIRECT3DDEVICE9 cDevice::GetDevice() const
{
	return m_pd3dDevice;
}