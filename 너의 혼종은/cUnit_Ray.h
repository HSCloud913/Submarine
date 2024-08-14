#pragma once
#include "cUnit.h"

class cUnit_Ray :public cUnit
{
public:
	cUnit_Ray();
	~cUnit_Ray();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};