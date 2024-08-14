#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_R_Cme.h"



cWeapon_R_Cme::cWeapon_R_Cme()
	: cWeapon(100)
{
}

cWeapon_R_Cme::~cWeapon_R_Cme()
{
}



INT cWeapon_R_Cme::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 25.f;
	Pos.y += 30.f;

	pData->AddObject(BulletFactory::Create(Bullet::R_Cme, Pos, degree, upgrade));

	return 0;
}