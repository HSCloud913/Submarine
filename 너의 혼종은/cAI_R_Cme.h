#pragma once
#include "cAI.h"

class cTimer;

class cAI_R_Cme :public cAI
{
public:
	cAI_R_Cme(cUnit* pUnit);
	~cAI_R_Cme();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};