#include "Util.h"

#include "cData.h"

#include "cGameObject.h"

#include "cTile.h"



cTile::cTile(INT stageNum)
	: m_StageNum(stageNum)
{
	m_pGameObjList.clear();

	m_PosList.emplace_back(0, 0);
	m_PosList.emplace_back(7680, 0);
}

cTile::~cTile()
{
}



INT cTile::Update(cData* pData)
{
	if (pData->MapScroll())
	{
		for (UINT i = 0; i < m_PosList.size() - 1; i++)
		{
			m_PosList[i].x -= VFR(5.f);
			m_PosList[i + 1].x = m_PosList[i].x + 7680;
		}

		for (UINT i = 0; i < m_PosList.size(); i++)
		{
			if (m_PosList[i].x < -7680)
			{
				m_PosList.erase(m_PosList.begin() + i);
				m_PosList.emplace_back(7680, 0);

				i--;
			}
		}
	}

	for (UINT i = 0; i < m_pGameObjList.size(); i++)
	{
		if (m_pGameObjList[i]->Pos()->x < -600.f || m_pGameObjList[i]->Pos()->x > 2520.f ||
			m_pGameObjList[i]->Pos()->y < -100.f || m_pGameObjList[i]->Pos()->y > 1180.f)
		{
			pData->DeleteObject(m_pGameObjList[i]);
		}
	}

	return 0;
}

INT cTile::Render()
{
	for (UINT i = 0; i < m_PosList.size(); i++)
	{
		cD3DApp::Sprite.RenderTexture(
			cSystem::Resource.m_pTexList[TexList_Map]->GetTexture(m_StageNum), m_PosList[i]);
	}

	return 0;
}



INT cTile::AddObject(cGameObject* pGameObj)
{
	m_pGameObjList.emplace_back(pGameObj);

	return 0;
}

INT cTile::DeleteObject(UINT Idx)
{
	m_pGameObjList.erase(m_pGameObjList.begin() + Idx);

	return 0;
}

INT cTile::DeleteAllObject()
{
	m_pGameObjList.clear();

	return 0;
}