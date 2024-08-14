#pragma once
#include "cItem.h"

class cItem_OnceTorpedo :public cItem
{
public:
	cItem_OnceTorpedo();
	~cItem_OnceTorpedo();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};