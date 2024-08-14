#include "cMapObject.h"



cMapObject::cMapObject(MapObject::_Type mapObjType, FLOAT moveSpeed)
	: c2DObject(moveSpeed)

	, m_MapObjType(mapObjType)
	, m_Hp(2)
{
}

cMapObject::~cMapObject()
{
}



INT cMapObject::OnUpdateObject(cData* pData)
{
	m_Speed.x = -m_MoveSpeed;

	return OnUpdateMapObject(pData);
}

INT cMapObject::OnRenderObject()
{
	return OnRenderMapObject();
}



MapObject::_Type cMapObject::GetMapObjType() const
{
	return m_MapObjType;
}



INT cMapObject::GetHp() const
{
	return m_Hp;
}

void cMapObject::AddHp(INT hp)
{
	m_Hp += hp;
}