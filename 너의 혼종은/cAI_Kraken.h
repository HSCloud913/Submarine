#pragma once
#include "cAI.h"

class cTimer;

class cAI_Kraken :public cAI
{
public:
	cAI_Kraken(cUnit* pUnit);
	~cAI_Kraken();

private:
	cTimer* m_pPattern1;
	cTimer* m_pPattern2;
	cTimer* m_pPattern3;

private:
	BOOL m_Attack;

private:
	virtual INT OnUpdate(cData* pData) override;
};