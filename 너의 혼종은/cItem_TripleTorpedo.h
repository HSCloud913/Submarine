#pragma once
#include "cItem.h"

class cItem_TripleTorpedo :public cItem
{
public:
	cItem_TripleTorpedo();
	~cItem_TripleTorpedo();

private:
	virtual INT OnUpdateItem(cData* pData) override;
	virtual INT OnRenderItem() override;

private:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) override;
};