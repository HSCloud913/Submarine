#pragma once
#include "cAI.h"

class cAI_Player :public cAI
{
public:
	cAI_Player(cUnit* pUnit);
	~cAI_Player();

private:
	virtual INT OnUpdate(cData* pData) override;
};