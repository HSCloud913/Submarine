#pragma once
#include "c2DCoord.h"

class cData;

class cGameObject :public c2DCoord
{
public:
	cGameObject();
	virtual ~cGameObject();

public:
	INT Update(cData* pData);
	INT Render();

protected:
	virtual INT OnUpdate(cData* pData) = 0;
	virtual INT OnRender() = 0;
};