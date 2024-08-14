#pragma once
#include "cAI.h"

class cTimer;

class cAI_R_Puffer :public cAI
{
public:
	cAI_R_Puffer(cUnit* pUnit);
	~cAI_R_Puffer();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};