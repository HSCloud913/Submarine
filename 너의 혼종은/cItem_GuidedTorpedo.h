#pragma once
#include "cItem.h"

class cItem_GuidedTorpedo :public cItem
{
public:
	cItem_GuidedTorpedo();
	~cItem_GuidedTorpedo();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};