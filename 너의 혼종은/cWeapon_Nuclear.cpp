#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Nuclear.h"



cWeapon_Nuclear::cWeapon_Nuclear()
	: cWeapon(5000)
{
}

cWeapon_Nuclear::~cWeapon_Nuclear()
{
}



INT cWeapon_Nuclear::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x += 70.f;
	Pos.y += 50.f;

	pData->AddObject(BulletFactory::Create(Bullet::Nuclear, Pos, degree, upgrade));

	return 0;
}