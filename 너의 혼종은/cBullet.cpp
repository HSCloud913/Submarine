#include "cUnit.h"

#include "cBullet.h"



cBullet::cBullet(FLOAT moveSpeed)
	: c2DObject(moveSpeed)
{
}

cBullet::~cBullet()
{
}



INT cBullet::Init(Team::_Type teamType, Bullet::_Type bulletType, INT damage)
{
	m_TeamType = teamType;
	m_BulletType = bulletType;

	m_Damage = damage;

	return 0;
}



INT cBullet::OnUpdateObject(cData* pData)
{
	return OnUpdateBullet(pData);
}

INT cBullet::OnRenderObject()
{
	return OnRenderBullet();
}



INT cBullet::Hit(cUnit* pUnit)
{
	if (pUnit != nullptr)
	{
	/*	if (pUnit->GetUnitType() == Unit::Ray || pUnit->GetUnitType() == Unit::Shark ||
			pUnit->GetUnitType() == Unit::Whale || pUnit->GetUnitType() == Unit::Kraken)
		{
			pUnit->AddHp(-m_Damage + 1);
		}

		else*/
		{
			pUnit->AddHp(-m_Damage);
		}
	}

	return 0;
}



Team::_Type cBullet::GetTeamType() const
{
	return m_TeamType;
}

Bullet::_Type cBullet::GetBulletType() const
{
	return m_BulletType;
}