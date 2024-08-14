#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_R_Seahorse.h"



cWeapon_R_Seahorse::cWeapon_R_Seahorse()
	: cWeapon(100)
{
}

cWeapon_R_Seahorse::~cWeapon_R_Seahorse()
{
}



INT cWeapon_R_Seahorse::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;

	Pos.x -= 60.f;

	pData->AddObject(BulletFactory::Create(Bullet::R_Seahorse, Pos, degree - 2.5f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::R_Seahorse, Pos, degree + 2.5f, upgrade));

	return 0;
}