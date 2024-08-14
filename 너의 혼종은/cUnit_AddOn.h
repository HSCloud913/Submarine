#pragma once
#include "cUnit.h"

class cUnit_AddOn :public cUnit
{
public:
	cUnit_AddOn();
	~cUnit_AddOn();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};