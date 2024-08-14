#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_AddOn.h"



cWeapon_AddOn::cWeapon_AddOn()
	: cWeapon(300)
{
}

cWeapon_AddOn::~cWeapon_AddOn()
{
}



INT cWeapon_AddOn::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;

	Pos.x += 20.f;
	Pos.y += 30.f;

	pData->AddObject(BulletFactory::Create(Bullet::AddOn, Pos, degree, upgrade));

	return 0;
}