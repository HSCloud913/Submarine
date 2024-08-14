#pragma once
#include "cAI.h"

class cTimer;

class cAI_P_Cme :public cAI
{
public:
	cAI_P_Cme(cUnit* pUnit);
	~cAI_P_Cme();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};