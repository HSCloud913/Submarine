#pragma once
#include <Windows.h>
#include <vector>

enum GameState
{
	None
	, Clear
	, Fail
};

class c2DAni;

class cGameObject;

class cTile;

class cTimer;

class cData
{
public:
	cData(INT stageNum);
	virtual ~cData();

protected:
	c2DAni* m_pAni;

protected:
	cTile* m_pTile;

protected:
	cTimer* m_pStageTimer;
	cTimer* m_pTopographyTimer;
	cTimer* m_pSpawn[4];

	cTimer* m_pObjTimer;

protected:
	INT m_StageNum;
	GameState m_GameState;

protected:
	std::vector<cGameObject*> m_pGameObject;

protected:
	BOOL m_bMiddle;

public:
	INT Update();
	INT Render();

protected:
	virtual INT OnUpdate() = 0;
	virtual INT OnRender() = 0;

private:
	INT Spawn();

public:
	INT AddObject(cGameObject* pGameObject);
	INT DeleteObject(cGameObject* pGameObject);
	INT DeleteAllObject();

protected:
	virtual INT OnAddObject(cGameObject* pGameObject) = 0;
	virtual INT OnDeleteObject(UINT Idx) = 0;
	virtual INT OnDeleteAllObject() = 0;

public:
	INT SetTile(cTile* pTile);

public:
	GameState GetGameState() const;
	void SetGameState(GameState state);

public:
	BOOL MapScroll() const;

public:
	INT GetTime() const;
};