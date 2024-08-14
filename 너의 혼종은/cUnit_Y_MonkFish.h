#pragma once
#include "cUnit.h"

class cUnit_Y_MonkFish :public cUnit
{
public:
	cUnit_Y_MonkFish();
	~cUnit_Y_MonkFish();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};