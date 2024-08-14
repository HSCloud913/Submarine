#include "cUnit_Player.h"

#include "cItem.h"



cItem::cItem(Item::_Type itemType)
	: c2DObject(10.f)

	, m_ItemType(itemType)
{
	m_Scale = D3DXVECTOR2(0.5, 0.5f);

	m_CollRect = { 64 - 128, 64 - 128, 192 - 128, 192 - 128 };
}

cItem::~cItem()
{
}



INT cItem::OnUpdateObject(cData* pData)
{
	return OnUpdateItem(pData);
}

INT cItem::OnRenderObject()
{
	return OnRenderItem();
}



INT cItem::Use(cData* pData, cUnit_Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->AddScore(100);
	}

	return OnUse(pData, pPlayer);
}



Item::_Type cItem::GetItemType() const
{
	return m_ItemType;
}