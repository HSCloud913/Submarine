#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_OnceTorpedo.h"



cWeapon_OnceTorpedo::cWeapon_OnceTorpedo()
	: cWeapon(100)
{
}

cWeapon_OnceTorpedo::~cWeapon_OnceTorpedo()
{
}



INT cWeapon_OnceTorpedo::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x += 75.f;
	Pos.y += 40.f;

	pData->AddObject(BulletFactory::Create(Bullet::Torpedo, Pos, degree, upgrade));

	return 0;
}