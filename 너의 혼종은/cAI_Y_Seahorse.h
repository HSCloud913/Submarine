#pragma once
#include "cAI.h"

class cTimer;

class cAI_Y_Seahorse :public cAI
{
public:
	cAI_Y_Seahorse(cUnit* pUnit);
	~cAI_Y_Seahorse();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};