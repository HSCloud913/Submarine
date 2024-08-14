#pragma once
#include "cAI.h"

class cTimer;

class cAI_Ray :public cAI
{
public:
	cAI_Ray(cUnit* pUnit);
	~cAI_Ray();

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