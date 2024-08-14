#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Y_Seahorse.h"



cWeapon_Y_Seahorse::cWeapon_Y_Seahorse()
	: cWeapon(100)
{
}

cWeapon_Y_Seahorse::~cWeapon_Y_Seahorse()
{
}



INT cWeapon_Y_Seahorse::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;

	Pos.x -= 60.f;

	pData->AddObject(BulletFactory::Create(Bullet::Y_Seahorse, Pos, degree, upgrade));

	return 0;
}