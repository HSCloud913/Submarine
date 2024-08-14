#pragma once
#include "cAI.h"

class cTimer;

class cAI_Y_MonkFish :public cAI
{
public:
	cAI_Y_MonkFish(cUnit* pUnit);
	~cAI_Y_MonkFish();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};