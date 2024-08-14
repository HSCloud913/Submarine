#include "Util.h"

#include "c2DAni.h"

#include "UnitFactory.h"
#include "cGameObject.h"
#include "cTopography.h"
#include "cMapObject.h"
#include "cMapObj_Stone.h"
#include "cMapObj_Seaweed.h"

#include "cTile.h"

#include "cTimer.h"

#include "cData.h"



cData::cData(INT stageNum)
	: m_StageNum(stageNum)
	, m_GameState(None)

	, m_pAni(nullptr)

	, m_pStageTimer(new cTimer(3, 0))
	, m_pTopographyTimer(new cTimer(0, 6 - m_StageNum))

	, m_pObjTimer(new cTimer(0, 4 - stageNum))

	, m_bMiddle(FALSE)
{
	srand((UINT)time(NULL));

	m_pStageTimer->Play();
	m_pTopographyTimer->Play();

	m_pObjTimer->Play();

	for (UINT i = 0; i < 4; i++)
	{
		m_pSpawn[i] = new cTimer(0, i + 3);
		m_pSpawn[i]->Play();
	}

	m_pGameObject.clear();
}

cData::~cData()
{
	if (m_pTile != nullptr)
	{
		SAFE_DELETE(m_pTile);
	}
}



INT cData::Update()
{
	Spawn();

	if (m_pAni != nullptr)
	{
		m_pAni->Update();

		if (m_pAni->IsEnd())
		{
			SAFE_DELETE(m_pAni);
		}
	}

	if (m_pStageTimer != nullptr)
	{
		m_pStageTimer->Update();

		if (m_pStageTimer->GetTime() == 94 || m_pStageTimer->GetTime() == 4)
		{
			if (m_pAni == nullptr)
			{
				m_pAni = new c2DAni(cSystem::Resource.m_pTexList[TexList_Message_Warning], 96, 36);
				m_pAni->SetScale(2.7f, 2.7f);
				m_pAni->SetPos(&cSystem::fCenterPos);
				m_pAni->Play();
			}
		}

		if (m_pStageTimer->GetTime() == 90)
		{
			if (!m_bMiddle)
			{
				m_pStageTimer->Pause();

				if (m_StageNum == 0)
				{
					AddObject(UnitFactory::Create(Unit::Ray
						, D3DXVECTOR2(1500.f, cSystem::fCenterPos.y)));
				}

				else if (m_StageNum == 1)
				{
					AddObject(UnitFactory::Create(Unit::Shark
						, D3DXVECTOR2(1500.f, cSystem::fCenterPos.y)));
				}

				m_bMiddle = TRUE;
			}
		}

		if (m_pStageTimer->IsEnd())
		{
			SAFE_DELETE(m_pStageTimer);

			if (m_StageNum == 0)
			{
				AddObject(UnitFactory::Create(Unit::Whale
					, D3DXVECTOR2(1500.f, cSystem::fCenterPos.y)));
			}

			else if (m_StageNum == 1)
			{
				AddObject(UnitFactory::Create(Unit::Kraken
					, D3DXVECTOR2(1350.f, cSystem::fCenterPos.y + 200.f)));
			}
		}
	}

	for (UINT i = 0; i < m_pGameObject.size(); i++)
	{
		m_pGameObject[i]->Update(this);
	}

	return OnUpdate();
}

INT cData::Render()
{
	OnRender();

	if (m_pAni != nullptr)
	{
		m_pAni->Render();
	}

	return 0;
}



INT cData::Spawn()
{
	if (MapScroll())
	{
		if (m_pTopographyTimer != nullptr)
		{
			m_pTopographyTimer->Update();

			if (m_pTopographyTimer->IsEnd())
			{
				SAFE_DELETE(m_pTopographyTimer);

				cTopography* pTopography = nullptr;

				if (m_StageNum == 0)
				{
					pTopography = new cTopography(rand() % 3);
					pTopography->SetPos(2500.f, 800.f);
				}

				else if (m_StageNum == 1)
				{
					INT Random = rand() % 3 + 3;

					pTopography = new cTopography(Random);

					if (Random == 5)
					{
						pTopography->SetPos(2500.f, 300.f);
					}

					else
					{
						pTopography->SetPos(2500.f, 800.f);
					}
				}

				AddObject(pTopography);

				m_pTopographyTimer = new cTimer(0, 6 - m_StageNum);
				m_pTopographyTimer->Play();
			}
		}

		if (m_pObjTimer != nullptr)
		{
			m_pObjTimer->Update();

			if (m_pObjTimer->IsEnd())
			{
				SAFE_DELETE(m_pObjTimer);

				cMapObject* pMapObj = nullptr;

				if (rand() % 2 == 0)
				{
					pMapObj = new cMapObj_Stone();
				}

				else
				{
					pMapObj = new cMapObj_Seaweed();
				}

				pMapObj->SetPos(2000.f, 100 + rand() % 1720);

				AddObject(pMapObj);

				m_pObjTimer = new cTimer(0, 4 - m_StageNum);
				m_pObjTimer->Play();
			}
		}
	}

	for (UINT i = 0; i < 4; i++)
	{
		if (m_pSpawn[i] != nullptr)
		{
			m_pSpawn[i]->Update();

			if (m_pSpawn[i]->GetTime() < 0)
			{
				SAFE_DELETE(m_pSpawn[i]);
				m_pSpawn[i] = new cTimer(0, i + 3);
				m_pSpawn[i]->Play();
			}
		}
	}

	if (MapScroll())
	{
		if (m_pSpawn[0]->IsEnd())
		{
			if (m_StageNum == 0)
			{
				AddObject(UnitFactory::Create(Unit::Y_Seahorse
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			else if (m_StageNum == 1)
			{
				AddObject(UnitFactory::Create(Unit::P_Cme
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			SAFE_DELETE(m_pSpawn[0]);
			m_pSpawn[0] = new cTimer(0, 3);
			m_pSpawn[0]->Play();
		}

		if (m_pSpawn[1]->IsEnd())
		{
			if (m_StageNum == 0)
			{
				AddObject(UnitFactory::Create(Unit::Y_Puffer
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			else if (m_StageNum == 1)
			{
				AddObject(UnitFactory::Create(Unit::Y_MonkFish
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			SAFE_DELETE(m_pSpawn[1]);
			m_pSpawn[1] = new cTimer(0, 4);
			m_pSpawn[1]->Play();
		}

		if (m_pSpawn[2]->IsEnd())
		{
			if (m_StageNum == 0)
			{
				AddObject(UnitFactory::Create(Unit::R_Seahorse
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			else if (m_StageNum == 1)
			{
				AddObject(UnitFactory::Create(Unit::R_Cme
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			SAFE_DELETE(m_pSpawn[2]);
			m_pSpawn[2] = new cTimer(0, 5);
			m_pSpawn[2]->Play();
		}

		if (m_pSpawn[3]->IsEnd())
		{
			if (m_StageNum == 0)
			{
				AddObject(UnitFactory::Create(Unit::R_Puffer
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			else if (m_StageNum == 1)
			{
				AddObject(UnitFactory::Create(Unit::R_MonkFish
					, D3DXVECTOR2(2100.f, 100 + rand() % 880)));
			}

			SAFE_DELETE(m_pSpawn[3]);
			m_pSpawn[3] = new cTimer(0, 6);
			m_pSpawn[3]->Play();
		}
	}

	return 0;
}



INT cData::AddObject(cGameObject* pGameObject)
{
	m_pGameObject.emplace_back(pGameObject);

	OnAddObject(pGameObject);

	if (m_pTile != nullptr)
	{
   		m_pTile->AddObject(pGameObject);
	}

	return 0;
}

INT cData::DeleteObject(cGameObject* pGameObject)
{
	for (UINT i = 0; i < m_pGameObject.size(); i++)
	{
		if (m_pGameObject[i] == pGameObject)
		{
			if (m_pTile != nullptr)
			{
				m_pTile->DeleteObject(i);
			}

			OnDeleteObject(i);
		
			m_pGameObject.erase(m_pGameObject.begin() + i);

			break;
		}
	}

	SAFE_DELETE(pGameObject);

	return 0;
}

INT cData::DeleteAllObject()
{
	if (m_pTile != nullptr)
	{
		m_pTile->DeleteAllObject();
	}

	OnDeleteAllObject();

	for (UINT i = 0; i < m_pGameObject.size(); i++)
	{
		SAFE_DELETE(m_pGameObject[i]);
	}

	m_pGameObject.clear();

	return 0;
}



INT cData::SetTile(cTile* pTile)
{
	m_pTile = pTile;

	return 0;
}



GameState cData::GetGameState() const
{
	return m_GameState;
}

void cData::SetGameState(GameState state)
{
	m_GameState = state;
}



BOOL cData::MapScroll() const
{
	if (m_pStageTimer != nullptr)
	{
		return m_pStageTimer->IsPlay();
	}

	return FALSE;
}



INT cData::GetTime() const
{
	if (m_pStageTimer != nullptr)
	{
		return m_pStageTimer->GetTime();
	}

	return -1;
}