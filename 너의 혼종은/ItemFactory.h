#pragma once
#include "cItem.h"

class ItemFactory
{
private:
	ItemFactory();
	~ItemFactory();

public:
	static cItem* Create(Item::_Type itemType, const D3DXVECTOR2& pos);
};