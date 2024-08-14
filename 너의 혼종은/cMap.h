#pragma once
#include <Windows.h>
#include "cData.h"

class cTile;

class cMap
{
public:
	cMap(cData* pData, INT stageNum);
	virtual ~cMap();

protected:
	cTile* m_pTile;
	cData* m_pData;

public:
	INT Update();
	INT Render();

protected:
	virtual INT OnUpdate() = 0;
	virtual INT OnRenderGround() = 0;
	virtual INT OnRenderSky() = 0;

public:
	BOOL GameClear() const;
	BOOL GameFail() const;

	void SetGameState(GameState state);
};