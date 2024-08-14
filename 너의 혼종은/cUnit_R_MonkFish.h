#pragma once
#include "cUnit.h"

class cUnit_R_MonkFish :public cUnit
{
public:
	cUnit_R_MonkFish();
	~cUnit_R_MonkFish();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};