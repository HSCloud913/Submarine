#pragma once
#include "cAI.h"

class AIFactory
{
private:
	AIFactory();
	~AIFactory();

public:
	static cAI* Create(AI::_Type aiType, cUnit* pUnit);
};