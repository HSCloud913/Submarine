#pragma once
#include "cItem.h"

class cItem_Speed :public cItem
{
public:
	cItem_Speed();
	~cItem_Speed();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};