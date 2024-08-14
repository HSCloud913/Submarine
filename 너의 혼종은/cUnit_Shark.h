#pragma once
#include "cUnit.h"

class cUnit_Shark :public cUnit
{
public:
	cUnit_Shark();
	~cUnit_Shark();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};