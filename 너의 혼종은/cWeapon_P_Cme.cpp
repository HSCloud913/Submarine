#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_P_Cme.h"



cWeapon_P_Cme::cWeapon_P_Cme()
	: cWeapon(100)
{
}

cWeapon_P_Cme::~cWeapon_P_Cme()
{
}



INT cWeapon_P_Cme::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 25.f;
	Pos.y += 30.f;

	pData->AddObject(BulletFactory::Create(Bullet::P_Cme, Pos, degree - 7.5f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::P_Cme, Pos, degree - 2.5f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::P_Cme, Pos, degree + 2.5f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::P_Cme, Pos, degree - 7.5f, upgrade));

	return 0;
}