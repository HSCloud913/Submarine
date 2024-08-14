#pragma once
#include <d3dx9.h>

class cDevice
{
public:
	cDevice();
	~cDevice();

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pd3dDevice;

	D3DPRESENT_PARAMETERS m_d3dpp;

public:
	INT Create(BOOL bWindowed);
	INT CleanUp();

public:
	LPDIRECT3DDEVICE9 GetDevice() const;
};