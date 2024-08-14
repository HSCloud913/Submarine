#pragma once
#include <d3dx9.h>

class cTexture;

class cSprite
{
public:
	cSprite();
	~cSprite();

private:
	LPD3DXSPRITE m_pSprite;
	DWORD m_Color;

private:
	BOOL m_bCamera;

public:
	INT Create();
	INT CleanUp();

public:
	INT Begin();
	INT End();

public:
	INT SetColor(DWORD color);

public:
	INT Draw(cTexture* pTex, const D3DXVECTOR2* pPos, const D3DXVECTOR3* pCenter
		, const D3DXVECTOR2* pScale, FLOAT* pAngle, const RECT* pRect = nullptr);

public:
	INT DrawTexture(cTexture* pTex, const D3DXVECTOR2& pos
		, const D3DXVECTOR2& scale = D3DXVECTOR2(1.f, 1.f)
		, FLOAT angle = 0.f, const RECT* pRect = nullptr);
	INT DrawTextureCenter(cTexture* pTex, const D3DXVECTOR2& pos
		, const D3DXVECTOR2& scale = D3DXVECTOR2(1.f, 1.f)
		, FLOAT angle = 0.f, const RECT* pRect = nullptr);

public:
	INT RenderTexture(cTexture* pTex, const D3DXVECTOR2& pos
		, const D3DXVECTOR2& scale = D3DXVECTOR2(1.f, 1.f)
		, FLOAT angle = 0.f, const RECT* pRect = nullptr);
	INT RenderTextureCenter(cTexture* pTex, const D3DXVECTOR2& pos
		, const D3DXVECTOR2& scale = D3DXVECTOR2(1.f, 1.f)
		, FLOAT angle = 0.f, const RECT* pRect = nullptr);

public:
	void CameraOn();
	void CameraOff();
	BOOL CameraCheck();

public:
	LPD3DXSPRITE GetSprite() const;
};