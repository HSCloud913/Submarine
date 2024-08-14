#pragma once
#include "c2DObject.h"
#include "Type.h"

class cUnit;

class cBullet :public c2DObject
{
public:
	cBullet(FLOAT moveSpeed);
	virtual ~cBullet();

protected:
	Team::_Type m_TeamType;
	Bullet::_Type m_BulletType;

protected:
	INT m_Damage;

protected:
	INT Init(Team::_Type teamType, Bullet::_Type bulletType, INT damage);
		
private:
	virtual INT OnUpdateObject(cData* pData) override;
	virtual INT OnRenderObject() override;

protected:
	virtual INT OnUpdateBullet(cData* pData) = 0;
	virtual INT OnRenderBullet() = 0;

public:
	INT Hit(cUnit* pUnit);

public:
	Team::_Type GetTeamType() const;
	Bullet::_Type GetBulletType() const;
};