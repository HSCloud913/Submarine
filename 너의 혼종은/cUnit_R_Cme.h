#pragma once
#include "cUnit.h"

class cUnit_R_Cme :public cUnit
{
public:
	cUnit_R_Cme();
	~cUnit_R_Cme();

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};