#pragma once
#include "cItem.h"

class cItem_Nuclear :public cItem
{
public:
	cItem_Nuclear();
	~cItem_Nuclear();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};