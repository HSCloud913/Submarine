#pragma once
#include "cUnit.h"

class UnitFactory
{
private:
	UnitFactory();
	~UnitFactory();

public:
	static cUnit* Create(Unit::_Type unitType, const D3DXVECTOR2& pos);
};