#pragma once
#include <Windows.h>
#include "Type.h"

class cData;

class cUnit;

class cAI
{
public:
	cAI(cUnit* pUnit);
	virtual ~cAI();

protected:
	cUnit* m_pUnit;

public:
	INT Update(cData* pData);

protected:
	virtual INT OnUpdate(cData* pData) = 0;
};