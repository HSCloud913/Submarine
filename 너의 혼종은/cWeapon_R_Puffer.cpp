#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_R_Puffer.h"



cWeapon_R_Puffer::cWeapon_R_Puffer()
	: cWeapon(100)
{
}

cWeapon_R_Puffer::~cWeapon_R_Puffer()
{
}



INT cWeapon_R_Puffer::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 80.f;

	pData->AddObject(BulletFactory::Create(Bullet::R_Puffer, Pos, degree, upgrade));

	pData->AddObject(BulletFactory::Create(Bullet::R_Puffer, Pos + D3DXVECTOR2(15.f, 0.f), degree - 2.5f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::R_Puffer, Pos + D3DXVECTOR2(15.f, 0.f), degree + 2.5f, upgrade));

	return 0;
}