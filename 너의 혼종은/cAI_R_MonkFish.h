#pragma once
#include "cAI.h"

class cTimer;


class cAI_R_MonkFish :public cAI
{
public:
	cAI_R_MonkFish(cUnit* pUnit);
	~cAI_R_MonkFish();

private:
	cTimer* m_pTimer;

private:
	virtual INT OnUpdate(cData* pData) override;
};