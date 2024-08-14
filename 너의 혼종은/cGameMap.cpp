#include "Util.h"

#include "cUI.h"

#include "c2DAni.h"

#include "UnitFactory.h"
#include "cUnit_Player.h"

#include "cGameData.h"

#include "cGameMap.h"



cGameMap::cGameMap(INT stageNum)
	: cMap(new cGameData(stageNum), stageNum)
	
	, m_pUI(new cUI)
{
	if (stageNum == 0)
	{
		m_pStartMsg = new c2DAni(cSystem::Resource.m_pTexList[TexList_Message_Stage1], 72, 48);
	}

	else if (stageNum == 1)
	{
		m_pStartMsg = new c2DAni(cSystem::Resource.m_pTexList[TexList_Message_Stage2], 72, 48);
	}

	m_pStartMsg->SetPos(&cSystem::fCenterPos);
	m_pStartMsg->Play();

	m_pData->AddObject(UnitFactory::Create(Unit::Player
		, D3DXVECTOR2(256.f, cSystem::fCenterPos.y)));
}

cGameMap::~cGameMap()
{
	if (m_pUI != nullptr)
	{
		SAFE_DELETE(m_pUI);
	}
}



INT cGameMap::OnUpdate()
{
	m_pUI->Update(m_pData);

	if (m_pStartMsg != nullptr)
	{
		m_pStartMsg->Update();

		if (m_pStartMsg->GetCurrFrame() == 71)
		{
			SAFE_DELETE(m_pStartMsg);
		}
	}

	return 0;
}

INT cGameMap::OnRenderGround()
{
	return 0;
}

INT cGameMap::OnRenderSky()
{
	m_pUI->Render();

	if (m_pStartMsg != nullptr)
	{
		m_pStartMsg->Render();
	}

	return 0;
}



INT cGameMap::GetScore() const
{
	cGameData* pGameData = dynamic_cast<cGameData*>(m_pData);

	if (pGameData != nullptr)
	{
		return pGameData->GetPlayer()->GetScore();
	}

	return 0;
}