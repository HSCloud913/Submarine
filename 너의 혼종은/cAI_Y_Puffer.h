#pragma once
#include "cAI.h"

class cTimer;

class cAI_Y_Puffer :public cAI
{
public:
	cAI_Y_Puffer(cUnit* pUnit);
	~cAI_Y_Puffer();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};