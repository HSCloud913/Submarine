#pragma once
#include "cUnit.h"

class cTimer;

class cUnit_Y_Puffer :public cUnit
{
public:
	cUnit_Y_Puffer();
	~cUnit_Y_Puffer();

private:
	cTimer* m_pUpTimer;
	cTimer* m_pDownTimer;

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;
};