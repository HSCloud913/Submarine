#include "cItem_OnceTorpedo.h"
#include "cItem_TripleTorpedo.h"
#include "cItem_GuidedTorpedo.h"
#include "cItem_Nuclear.h"
#include "cItem_Speed.h"
#include "cItem_Upgrade.h"

#include "ItemFactory.h"



ItemFactory::ItemFactory()
{
}

ItemFactory::~ItemFactory()
{
}



cItem* ItemFactory::Create(Item::_Type itemType, const D3DXVECTOR2& pos)
{
	cItem* pItem = nullptr;

	switch (itemType)
	{
	case Item::OnceTorpedo:
		pItem = new cItem_OnceTorpedo();
		break;

	case Item::TripleTorpedo:
		pItem = new cItem_TripleTorpedo();
		break;

	case Item::GuidedTorpedo:
		pItem = new cItem_GuidedTorpedo();
		break;

	case Item::Nuclear:
		pItem = new cItem_Nuclear();
		break;

	case Item::Speed:
		pItem = new cItem_Speed();
		break;

	case Item::Upgrade:
		pItem = new cItem_Upgrade();
		break;
	}

	if (pItem != nullptr)
	{
		pItem->SetPos(&pos);
		pItem->SetXSpeed(-pItem->GetMoveSpeed());
	}

	return pItem;
}