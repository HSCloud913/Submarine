#pragma once
#include "cAI.h"

class cTimer;

class cAI_Shark :public cAI
{
public:
	cAI_Shark(cUnit* pUnit);
	~cAI_Shark();

private:
	cTimer* m_pPattern1;
	cTimer* m_pPattern2;

	cTimer* m_pRush;

private:
	BOOL m_bMove;
	INT m_Num;

private:
	virtual INT OnUpdate(cData* pData) override;
};