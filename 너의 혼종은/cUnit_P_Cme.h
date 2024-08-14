#pragma once
#include "cUnit.h"

class cUnit_P_Cme :public cUnit
{
public:
	cUnit_P_Cme();
	~cUnit_P_Cme();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};