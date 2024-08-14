#pragma once
#include "c2DObject.h"
#include "Type.h"

class cUnit_Player;

class cItem :public c2DObject
{
public:
	cItem(Item::_Type itemType);
	virtual ~cItem();

private:
	Item::_Type m_ItemType;

private:
	virtual INT OnUpdateObject(cData* pData) override;
	virtual INT OnRenderObject() override;

protected:
	virtual INT OnUpdateItem(cData* pData) = 0;
	virtual INT OnRenderItem() = 0;

public:
	INT Use(cData* pData, cUnit_Player* pPlayer);

protected:
	virtual INT OnUse(cData* pData, cUnit_Player* pPlayer) = 0;

public:
	Item::_Type GetItemType() const;
};