#pragma once
#include "cAI.h"

class cTimer;

class cAI_Whale :public cAI
{
public:
	cAI_Whale(cUnit* pUnit);
	~cAI_Whale();

private:
	cTimer* m_pPattern1;
	cTimer* m_pPattern2;

private:
	BOOL m_Attack;

private:
	virtual INT OnUpdate(cData* pData) override;
};