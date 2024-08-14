#pragma once
#include "cUnit.h"

class cTimer;

class cUnit_R_Puffer :public cUnit
{
public:
	cUnit_R_Puffer();
	~cUnit_R_Puffer();

private:
	cTimer* m_pUpTimer;
	cTimer* m_pDownTimer;

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};