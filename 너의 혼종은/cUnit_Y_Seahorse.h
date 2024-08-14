#pragma once
#include "cUnit.h"

class cUnit_Y_Seahorse :public cUnit
{
public:
	cUnit_Y_Seahorse();
	~cUnit_Y_Seahorse();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};