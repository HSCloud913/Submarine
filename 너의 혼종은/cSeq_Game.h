#pragma once
#include "cSequence.h"

class cFade;
class cTimer;

class c2DAni;

class cGameMap;

class cSeq_Game :public cSequence
{
public:
	cSeq_Game();
	~cSeq_Game();

private:
	cFade* m_pFade;
	cTimer* m_pTimer;
	
private:
	enum State
	{
		None
		, Clear
		, Fail
	};

	State m_State;

private:
	c2DAni* m_pAni;

private:
	cGameMap* m_pGameMap;
	INT m_StageNum;

private:
	cGameMap* m_pNextGameMap;

private:
	INT m_Score;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;

private:
	cGameMap* LoadMap();
};