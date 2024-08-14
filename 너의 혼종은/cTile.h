#pragma once
#include <d3dx9.h>

class cData;

class cGameObject;

class cTile
{
public:
	cTile(INT stageNum);                       
	~cTile();

private:
	std::vector<cGameObject*> m_pGameObjList;
	std::vector<D3DXVECTOR2> m_PosList;

private:
	INT m_StageNum;

public:
	INT Update(cData* pData);
	INT Render();

public:
	INT AddObject(cGameObject* pGameObj);
	INT DeleteObject(UINT Idx);
	INT DeleteAllObject();
};