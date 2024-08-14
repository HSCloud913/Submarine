#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_R_MonkFish.h"



cWeapon_R_MonkFish::cWeapon_R_MonkFish()
	: cWeapon(1000)
{
}

cWeapon_R_MonkFish::~cWeapon_R_MonkFish()
{
}



INT cWeapon_R_MonkFish::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 20.f;

	pData->AddObject(BulletFactory::Create(Bullet::R_MonkFish, Pos, degree - 5.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::R_MonkFish, Pos, degree, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::R_MonkFish, Pos, degree + 5.f, upgrade));

	return 0;
}