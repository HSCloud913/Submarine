#pragma once
#include "cUnit.h"

class cUnit_R_Seahorse :public cUnit
{
public:
	cUnit_R_Seahorse();
	~cUnit_R_Seahorse();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};