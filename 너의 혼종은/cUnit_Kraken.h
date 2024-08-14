#pragma once
#include "cUnit.h"

class cUnit_Kraken :public cUnit
{
public:
	cUnit_Kraken();
	~cUnit_Kraken();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};