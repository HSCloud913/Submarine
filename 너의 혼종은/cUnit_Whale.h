#pragma once
#include "cUnit.h"

class c2DAni;

class cUnit_Whale :public cUnit
{
public:
	cUnit_Whale();
	~cUnit_Whale();

private:
	c2DAni* m_pAni;

private:
	FLOAT m_Count;

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};