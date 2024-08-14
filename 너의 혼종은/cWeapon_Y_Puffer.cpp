#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Y_Puffer.h"



cWeapon_Y_Puffer::cWeapon_Y_Puffer()
	: cWeapon(100)
{
}

cWeapon_Y_Puffer::~cWeapon_Y_Puffer()
{
}



INT cWeapon_Y_Puffer::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x -= 80.f;

	pData->AddObject(BulletFactory::Create(Bullet::Y_Puffer, Pos, degree, upgrade));

	return 0;
}