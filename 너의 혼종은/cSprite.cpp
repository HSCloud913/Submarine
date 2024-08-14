#include "Util.h"

#include "cTexture.h"

#include "cSprite.h"



cSprite::cSprite()
	: m_pSprite(nullptr)
	, m_Color(0xffffffff)

	, m_bCamera(FALSE)
{
}

cSprite::~cSprite()
{
}



INT cSprite::Create()
{
	if (FAILED(D3DXCreateSprite(cD3DApp::Device.GetDevice(), &m_pSprite)))
	{
		return Util::ErrorMessage(L"D3DXCreateSprite");
	}

	return 0;
}

INT cSprite::CleanUp()
{
	if (m_pSprite != nullptr)
	{
		SAFE_RELEASE(m_pSprite);
	}

	return 0;
}



INT cSprite::Begin()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	return 0;
}

INT cSprite::End()
{
	m_pSprite->End();

	return 0;
}



INT cSprite::SetColor(DWORD color)
{
	m_Color = color;

	return 0;
}



INT cSprite::Draw(cTexture* pTex, const D3DXVECTOR2* pPos, const D3DXVECTOR3* pCenter
	, const D3DXVECTOR2* pScale, FLOAT* pAngle, const RECT* pRect)
{
	D3DXMATRIX WorldMat;
	D3DXMATRIX Mat[3];

	D3DXMatrixScaling(&Mat[0], pScale->x, pScale->y, 1.f);
	D3DXMatrixRotationZ(&Mat[1], D3DXToRadian(*pAngle));
	D3DXMatrixTranslation(&Mat[2], pPos->x, pPos->y, 0.f);

	WorldMat = Mat[0] * Mat[1] * Mat[2];

	if (m_bCamera)
	{
		WorldMat._41 += cSystem::Camera.Matrix()->_41;
		WorldMat._42 += cSystem::Camera.Matrix()->_42;
		WorldMat._43 += cSystem::Camera.Matrix()->_43;
	}

	m_pSprite->SetTransform(&WorldMat);

	RECT Rect;

	if (pRect == nullptr)
	{
		SetRect(&Rect, 0, 0, pTex->Width(), pTex->Height());
	}

	else
	{
		Rect = *pRect;
	}
	
	m_pSprite->Draw(pTex->GetTexture(), &Rect, pCenter, &D3DXVECTOR3(0.f, 0.f, 0.f), m_Color);
	
	D3DXMatrixIdentity(&WorldMat);
	m_pSprite->SetTransform(&WorldMat);

	m_Color = 0xffffffff;

	return 0;
}



INT cSprite::DrawTexture(cTexture* pTex, const D3DXVECTOR2& pos
	, const D3DXVECTOR2& scale, FLOAT angle, const RECT* pRect)
{
	D3DXVECTOR3 Center(0.f, 0.f, 0.f);

	return Draw(pTex, &pos, &Center, &scale, &angle, pRect);
}

INT cSprite::DrawTextureCenter(cTexture* pTex, const D3DXVECTOR2& pos
	, const D3DXVECTOR2& scale, FLOAT angle, const RECT* pRect)
{
	D3DXVECTOR3 Center(pTex->Width() / 2.f, pTex->Height() / 2.f, 0.f);

	return Draw(pTex, &pos, &Center, &scale, &angle, pRect);
}



INT cSprite::RenderTexture(cTexture* pTex, const D3DXVECTOR2& pos
	, const D3DXVECTOR2& scale, FLOAT angle, const RECT* pRect)
{
	D3DXVECTOR3 Center(0.f, 0.f, 0.f);

	Begin();
	Draw(pTex, &pos, &Center, &scale, &angle, pRect);
	End();

	return 0;
}

INT cSprite::RenderTextureCenter(cTexture* pTex, const D3DXVECTOR2& pos
	, const D3DXVECTOR2& scale, FLOAT angle, const RECT* pRect)
{
	D3DXVECTOR3 Center(pTex->Width() / 2.f, pTex->Height() / 2.f, 0.f);

	Begin();
	Draw(pTex, &pos, &Center, &scale, &angle, pRect);
	End();

	return 0;
}



void cSprite::CameraOn()
{
	m_bCamera = TRUE;
}

void cSprite::CameraOff()
{
	m_bCamera = FALSE;
}

BOOL cSprite::CameraCheck()
{
	return m_bCamera;
}



LPD3DXSPRITE cSprite::GetSprite() const
{
	return m_pSprite;
}