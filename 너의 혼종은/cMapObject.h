#pragma once
#include "c2DObject.h"
#include "Type.h"

class cMapObject :public c2DObject
{
public:
	cMapObject(MapObject::_Type mapObjType, FLOAT moveSpeed);
	virtual ~cMapObject();

protected:
	MapObject::_Type m_MapObjType;

protected:
	INT m_Hp;

private:
	virtual INT OnUpdateObject(cData* pData) override;
	virtual INT OnRenderObject() override;

protected:
	virtual INT OnUpdateMapObject(cData* pData) = 0;
	virtual INT OnRenderMapObject() = 0;

public:
	MapObject::_Type GetMapObjType() const;

public:
	INT GetHp() const;
	void AddHp(INT hp);
};