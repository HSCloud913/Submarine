#pragma once
#include "cItem.h"

class cItem_Upgrade :public cItem
{
public:
	cItem_Upgrade();
	~cItem_Upgrade();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};