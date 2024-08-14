#pragma once
#include "cMap.h"

class cUI;

class c2DAni;

class cGameMap :public cMap
{
public:
	cGameMap(INT stageNum);
	~cGameMap();

private:
	cUI* m_pUI;

private:
	c2DAni* m_pStartMsg;

private:
	virtual INT OnUpdate() override;
	virtual INT OnRenderGround() override;
	virtual INT OnRenderSky() override;

public:
	INT GetScore() const;
};