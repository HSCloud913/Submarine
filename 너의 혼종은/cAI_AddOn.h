#pragma once
#include "cAI.h"

class cAI_AddOn :public cAI
{
public:
	cAI_AddOn(cUnit* pUnit);
	~cAI_AddOn();

private:
	static INT m_Count;

private:
	INT m_Num;

private:
	virtual INT OnUpdate(cData* pData) override;
};