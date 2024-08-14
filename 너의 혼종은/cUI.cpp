#include "Util.h"

#include "cFont.h"

#include "cGameData.h"
#include "cData.h"

#include "cUnit_Player.h"

#include "cUI.h"



cUI::cUI()
	: m_pFont(new cFont)
	, m_Score(0)
	, m_Nuclear(0)
{
	m_pFont->Create(L"휴먼편지체 보통", 20, 40);
}

cUI::~cUI()
{
}



INT cUI::Update(cData* pData)
{
	cGameData* pGameData = dynamic_cast<cGameData*>(pData);

	m_Gauge = 180 - pData->GetTime();

	if (pGameData->GetPlayer() != nullptr)
	{
		m_Score = pGameData->GetPlayer()->GetScore();
		m_Nuclear = pGameData->GetPlayer()->NuclearCnt();
	}

	return 0;
}

INT cUI::Render()
{
	FLOAT Gauge = (m_Gauge / 180.f) * 1280.f;

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(9)
		, cSystem::fCenterPos + D3DXVECTOR2(0.f, 450.f));

	cD3DApp::Sprite.SetColor(D3DCOLOR_ARGB(255, 0, 255, 0));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(10)
		, cSystem::fCenterPos + D3DXVECTOR2(0.f, 450.f));
	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(11)
		, D3DXVECTOR2(352 + (m_Gauge / 180.f) * 1200.f, cSystem::fCenterPos.y + 450.f));

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(8)
		, D3DXVECTOR2(120.f, 1025.f), D3DXVECTOR2(0.5f, 0.5f));


	WCHAR Buffer[256];
	swprintf_s(Buffer, 255, L"X %d", m_Nuclear);
	m_pFont->ShowText(Buffer, 160.f, 980.f, D3DCOLOR_ARGB(255, 255, 255, 255));

	cD3DApp::Sprite.RenderTextureCenter(cSystem::Resource.m_pTexList[TexList_UI]->GetTexture(12)
		, D3DXVECTOR2(1920 - 138, 42.f));

	for (UINT i = 0; i < 6; i++)
	{
		INT Score = (m_Score % INT(pow(10, 6 - i))) / INT(pow(10, 5 - i));
		cD3DApp::Sprite.RenderTextureCenter(
			cSystem::Resource.m_pTexList[TexList_UI_Num]->GetTexture(Score)
			, D3DXVECTOR2(1730.f + i * 30, 100.f), D3DXVECTOR2(0.15f, 0.15f));
	}

	return 0;
}