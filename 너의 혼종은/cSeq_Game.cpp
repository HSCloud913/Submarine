#include "Util.h"

#include "cFade.h"
#include "cTimer.h"

#include "c2DAni.h"

#include "cGameMap.h"

#include "UnitFactory.h"

#include "cSound.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Ending.h"
#include "cSeq_Game.h"



cSeq_Game::cSeq_Game()
	: m_pFade(new cFade(Fade::In, 2.5f))
	, m_pTimer(nullptr)
	, m_State(None)

	, m_pAni(nullptr)

	, m_StageNum(1)

	, m_pNextGameMap(nullptr)

	, m_Score(0)
{
}


cSeq_Game::~cSeq_Game()
{
	SAFE_DELETE(m_pGameMap);
}



INT cSeq_Game::OnInit()
{
	m_pGameMap = LoadMap();
	cSystem::Resource.m_pSoundList[0]->GetSound(0)->Play(TRUE);

	return 0;
}

INT cSeq_Game::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Game::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (m_pAni != nullptr)
	{
		m_pAni->Update();

		if (m_pAni->IsEnd())
		{
			SAFE_DELETE(m_pAni);
		}
	}

	if(m_pFade != nullptr)
	{
		m_pFade->Update();

		if (m_pFade->GetAlpha() >= 255.f)
		{
			if (m_StageNum == 2)
			{
				if (m_pNextGameMap != nullptr)
				{
					SAFE_DELETE(m_pGameMap);
					m_pGameMap = m_pNextGameMap;
					m_pNextGameMap = nullptr;

					cSystem::Resource.m_pSoundList[0]->GetSound(0)->Play(TRUE);

					m_State = None;
				}

				else
				{
					cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
					return new cSeq_Ending(FALSE);
				}
			}

			if (m_StageNum == 3)
			{
				cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
				return new cSeq_Ending(TRUE, m_Score);
			}
		}

		if (m_pFade->IsEnd())
		{
			SAFE_DELETE(m_pFade);

			if (m_StageNum == 1)
			{
				if (m_State == Fail)
				{
					cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
					return new cSeq_Ending(FALSE);
				}
			}
		}
	}

	if (m_pTimer != nullptr)
	{
		m_pTimer->Update();

		if (m_pTimer->IsEnd())
		{
			SAFE_DELETE(m_pTimer);
			
			cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();

			if (m_pNextGameMap == nullptr)
			{
				m_pFade = new cFade(Fade::Out, 2.5f);
			}

			else
			{
				m_pFade = new cFade(Fade::OutIn, 2.5f);
			}
		}
	}

	else if (m_pGameMap != nullptr)
	{
		if (m_pGameMap->GameClear())
		{
			m_Score += m_pGameMap->GetScore();

			m_pGameMap->SetGameState(GameState::None);
			m_pNextGameMap = nullptr;
			m_State = Clear;

			++m_StageNum;
			m_pNextGameMap = LoadMap();

			m_pTimer = new cTimer(0, 3);
			m_pTimer->Play();

			if (m_pAni == nullptr)
			{
				m_pAni = new c2DAni(cSystem::Resource.m_pTexList[TexList_Message_Clear], 48, 48);
				m_pAni->SetPos(&cSystem::fCenterPos);
				m_pAni->Play();
			}
		}

		if (m_pGameMap->GameFail())
		{
			m_pGameMap->SetGameState(GameState::None);
			m_pNextGameMap = nullptr;
			m_State = Fail;

			m_pTimer = new cTimer(0, 3);
			m_pTimer->Play();

			if (m_pAni == nullptr)
			{
				m_pAni = new c2DAni(cSystem::Resource.m_pTexList[TexList_Message_Fail], 48, 48);
				m_pAni->SetPos(&cSystem::fCenterPos);
				m_pAni->SetScale(3.f, 3.f);
				m_pAni->Play();
			}
		}
	}

	if (m_pGameMap != nullptr)
	{
		m_pGameMap->Update();
	}

	if (cSystem::Input.KeyDown(VK_F4))
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
		return new cSeq_MainMenu;
	}

	if (cSystem::Input.KeyDown(VK_F5))
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
		m_Score = 0;
		m_StageNum = 1;
		m_pNextGameMap = LoadMap();

		SAFE_DELETE(m_pGameMap);
		m_pGameMap = m_pNextGameMap;
		m_pNextGameMap = nullptr;
		cSystem::Resource.m_pSoundList[0]->GetSound(0)->Play(TRUE);
	}

	if (cSystem::Input.KeyDown(VK_F6))
	{
		cSystem::Resource.m_pSoundList[0]->GetSound(0)->Stop();
		m_Score = 0;
		m_StageNum = 2;
		m_pNextGameMap = LoadMap();

		SAFE_DELETE(m_pGameMap);
		m_pGameMap = m_pNextGameMap;
		m_pNextGameMap = nullptr;
		cSystem::Resource.m_pSoundList[0]->GetSound(0)->Play(TRUE);
	}

	return pNextSeq;
}

INT cSeq_Game::OnRender()
{
	if (m_pGameMap != nullptr)
	{
		m_pGameMap->Render();
	}

	if (m_pAni != nullptr)
	{			
		m_pAni->Render();
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}



cGameMap* cSeq_Game::LoadMap()
{
	cGameMap* pGameMap = nullptr;

	if (m_StageNum == 1 || m_StageNum == 2)
	{
		pGameMap = new cGameMap(m_StageNum - 1);
	}

	return pGameMap;
}