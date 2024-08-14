#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Y_MonkFish.h"



cWeapon_Y_MonkFish::cWeapon_Y_MonkFish()
	: cWeapon(100)
{
}

cWeapon_Y_MonkFish::~cWeapon_Y_MonkFish()
{
}



INT cWeapon_Y_MonkFish::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 20.f;

	pData->AddObject(BulletFactory::Create(Bullet::Y_MonkFish, Pos, degree, upgrade));

	return 0;
}