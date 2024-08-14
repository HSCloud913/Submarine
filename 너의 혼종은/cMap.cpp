#include "Util.h"

#include "cData.h"
#include "cTile.h"

#include "cMap.h"



cMap::cMap(cData* pData, INT stageNum)
	: m_pTile(new cTile(stageNum))
	, m_pData(pData)
{
	m_pData->SetTile(m_pTile);
}

cMap::~cMap()
{
	if (m_pData != nullptr)
	{
		m_pData->DeleteAllObject();

		SAFE_DELETE(m_pData);
	}
}



INT cMap::Update()
{
	m_pTile->Update(m_pData);
	m_pData->Update();

	return OnUpdate();
}

INT cMap::Render()
{
	m_pTile->Render();

	OnRenderGround();

	m_pData->Render();

	OnRenderSky();

	return 0;
}



BOOL cMap::GameClear() const
{
	return (m_pData->GetGameState() == Clear);
}

BOOL cMap::GameFail() const
{
	return (m_pData->GetGameState() == Fail);
}



void cMap::SetGameState(GameState state)
{
	m_pData->SetGameState(state);
}