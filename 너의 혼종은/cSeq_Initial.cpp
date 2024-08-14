#include "Util.h"

#include "cFont.h"

#include "cFade.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Initial.h"



cSeq_Initial::cSeq_Initial(INT score)
	: m_Score(score)
	, m_Input(65)
	, m_Count(0)

	, m_pFont(new cFont)
	, m_pScoreFont(new cFont)

	, m_pFade(nullptr)
{
	m_pFont->Create(L"Calibri", 200, 400);
	m_pScoreFont->Create(L"Calibri", 50, 100);
		
	m_InfoList.clear();
}

cSeq_Initial::~cSeq_Initial()
{
	if (m_pScoreFont != nullptr)
	{
		SAFE_DELETE(m_pScoreFont);
	}

	if (m_pFont != nullptr)
	{
		SAFE_DELETE(m_pFont);
	}
}



INT cSeq_Initial::OnInit()
{
	m_RFile.open(L"Result/Result.txt");

	if (m_RFile.is_open())
	{
		while (!m_RFile.eof())
		{
			UINT Idx = m_InfoList.size();
			m_InfoList.emplace_back();

			m_RFile >> m_InfoList[Idx].Initial >> m_InfoList[Idx].Score;
		}
	}

	m_RFile.close();

	m_Word[0] = 'A';

	return 0;
}

INT cSeq_Initial::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Initial::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (cSystem::Input.KeyDown(VK_SPACE))
	{
		if (m_Count < 3)
		{
			m_Count++;
			m_Input = 65;
		}
	}

	if (cSystem::Input.KeyDown(VK_UP))
	{
		if (m_Input > 65)
		{
			m_Input--;
		}

		else
		{
			m_Input = 90;
		}
	}

	if (cSystem::Input.KeyDown(VK_DOWN))
	{
		if (m_Input < 90)
		{
			m_Input++;
		}

		else
		{
			m_Input = 65;
		}
	}

	if (m_Count < 3)
	{
		m_Word[m_Count] = m_Input;
	}

	if (m_Count == 3)
	{
		m_WFile.open(L"Result/Result.txt");

		if (m_WFile.is_open())
		{
			for (UINT i = 0; i < m_InfoList.size(); i++)
			{
				m_WFile << m_InfoList[i].Initial << ' ' << m_InfoList[i].Score << std::endl;
			}

			m_WFile << std::endl;
			m_WFile << m_Word << ' ' << m_Score;
		}

		m_WFile.close();
	
		if (m_pFade == nullptr)
		{
			m_pFade = new cFade(Fade::Out, 5.f);
		}
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Update();

		if (m_pFade->IsEnd())
		{
			SAFE_DELETE(m_pFade);

			return new cSeq_MainMenu;
		}
	}

	return pNextSeq;
}

INT cSeq_Initial::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Initial]->GetTexture(0), cSystem::fCenterPos);

	WCHAR Score[256];
	swprintf_s(Score, L"Score : %d", m_Score);
	m_pScoreFont->ShowText(Score, cSystem::CenterPt.x, cSystem::CenterPt.y - 250
		, D3DCOLOR_ARGB(255, 255, 255, 255), DT_CENTER);

	INT YPos = -350;

	for (UINT i = 0; i < m_Input + 1; i++)
	{
		if (i < 4)
		{
			WCHAR Buffer[256];
			swprintf_s(Buffer, L"%c", m_Word[i]);

			m_pFont->ShowText(Buffer, cSystem::CenterPt.x + YPos, cSystem::CenterPt.y - 200
				, D3DCOLOR_ARGB(255, 255, 255, 255), DT_CENTER);

			YPos += 350;
		}
	}

	if (m_Count < 3)
	{
		cD3DApp::Sprite.RenderTextureCenter(
			cSystem::Resource.m_pTexList[TexList_Initial]->GetTexture(1)
			, D3DXVECTOR2(605 + m_Count * 350, cSystem::fCenterPos.y + 15.f));
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}