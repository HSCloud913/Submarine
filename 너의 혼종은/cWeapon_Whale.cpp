#include <stdlib.h>

#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Whale.h"



cWeapon_Whale::cWeapon_Whale()
	: cWeapon(30)
{
	srand((UINT)timeGetTime());
}

cWeapon_Whale::~cWeapon_Whale()
{
}



INT cWeapon_Whale::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;

	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree - 45.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree - 30.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree - 15.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree + 15.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree + 30.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Whale, Pos, degree + 45.f, upgrade));

	return 0;
}