#include "Util.h"

#include "cFade.h"

#include "cButton.h"

#include "cSound.h"

#include "cSeq_Introduction.h"
#include "cSeq_Method.h"
#include "cSeq_Ranking.h"
#include "cSeq_Game.h"
#include "cSeq_MainMenu.h"



cSeq_MainMenu::cSeq_MainMenu()
	: m_pFade(new cFade(Fade::In, 2.5f))

	, m_pIntroduce(new cButton(cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(1)
		, D3DXVECTOR2(0.f, 0.f)))
	, m_pMethod(new cButton(cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(2)
		, D3DXVECTOR2(0.f, 0.f)))
	, m_pStart(new cButton(cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(3)
		, D3DXVECTOR2(0.f, 0.f)))
	, m_pExit(new cButton(cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(4)
		, D3DXVECTOR2(0.f, 0.f)))
	, m_pRanking(new cButton(cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(5)
		, D3DXVECTOR2(1770.f, 100.f)))

	, m_ButtonPos(1200.f)

	, m_bClick(FALSE)
{
}


cSeq_MainMenu::~cSeq_MainMenu()
{
	m_WaterDropList.clear();
}



INT cSeq_MainMenu::OnInit()
{
	for (UINT i = 0; i < 64; i++)
	{
		UINT Idx = m_WaterDropList.size();
		m_WaterDropList.emplace_back(D3DXVECTOR2(rand() % 1920, 1112 + rand() % 112)
			, 4 + rand() % 10);

		FLOAT Scale = 0.5f + static_cast<FLOAT>(rand()) / RAND_MAX * 0.8f;
		m_WaterDropList[Idx].SetScale(Scale, Scale);
	}

	return 0;
}

INT cSeq_MainMenu::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_MainMenu::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (m_pIntroduce->IsUp())
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(1)->Play(FALSE);

		return new cSeq_Introduction;
	}

	if (m_pMethod->IsUp())
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(1)->Play(FALSE);

		return new cSeq_Method;
	}

	if (m_pStart->IsUp())
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(1)->Play(FALSE);

		m_pFade = new cFade(Fade::Out, 2.5f);
		m_bClick = TRUE;
	}

	if (m_pExit->IsUp())
	{
		cSystem::ExitProgram();
	}

	if (m_pRanking->IsUp())
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(1)->Play(FALSE);

		return new cSeq_Ranking;
	}

	if (m_bClick)
	{
		if (m_ButtonPos < 1080.f)
		{
			m_ButtonPos += VFR(m_ButtonPos / 12.f);

			if (m_ButtonPos > 1080.001f)
			{
				m_ButtonPos = 1080.f;
			}
		}

		if (m_pFade != nullptr)
		{
			m_pFade->Update();

			if (m_pFade->IsEnd())
			{
				SAFE_DELETE(m_pFade);

				return new cSeq_Game;
			}
		}
	}

	else
	{
		if (m_ButtonPos > 0.f)
		{
			m_ButtonPos -= VFR(m_ButtonPos / 16.f);

			if (m_ButtonPos < 0.001f)
			{
				m_ButtonPos = 0.f;
			}
		}

		if (m_pFade != nullptr)
		{
			m_pFade->Update();

			if (m_pFade->IsEnd())
			{
				SAFE_DELETE(m_pFade);
			}
		}
	}

	for (UINT i = 0; i < m_WaterDropList.size(); i++)
	{
		m_WaterDropList[i].Update();

		if (m_WaterDropList[i].Pos()->y < -32)
		{
			m_WaterDropList[i].SetXPos(rand() % 1920);
			m_WaterDropList[i].SetYPos(1112 + rand() % 112);
		}
	}
	
	m_pIntroduce->Update();
	m_pMethod->Update();
	m_pStart->Update();
	m_pExit->Update();
	m_pRanking->Update();

	UpdateButton();

	return pNextSeq;
}

INT cSeq_MainMenu::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(0), cSystem::fCenterPos);

	m_pIntroduce->Render();
	m_pMethod->Render();
	m_pStart->Render();
	m_pExit->Render();
	m_pRanking->Render();

	for (UINT i = 0; i < m_WaterDropList.size(); i++)
	{
		m_WaterDropList[i].Render();
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}



INT cSeq_MainMenu::UpdateButton()
{
	m_pIntroduce->SetPos(1650.f, 500.f + m_ButtonPos);
	m_pMethod->SetPos(1650.f, 650.f + m_ButtonPos * 2.f);
	m_pStart->SetPos(1650.f, 800.f + m_ButtonPos * 4.f);
	m_pExit->SetPos(1650.f, 950.f + m_ButtonPos * 8.f);

	return 0;
}