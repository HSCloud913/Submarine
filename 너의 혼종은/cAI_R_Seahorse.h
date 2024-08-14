#pragma once
#include "cAI.h"

class cTimer;

class cAI_R_Seahorse :public cAI
{
public:
	cAI_R_Seahorse(cUnit* pUnit);
	~cAI_R_Seahorse();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};