#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_GuidedTorpedo.h"



cWeapon_GuidedTorpedo::cWeapon_GuidedTorpedo()
	: cWeapon(2000)
{
}

cWeapon_GuidedTorpedo::~cWeapon_GuidedTorpedo()
{
}



INT cWeapon_GuidedTorpedo::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x += 75.f;
	Pos.y += 40.f;

	pData->AddObject(BulletFactory::Create(Bullet::GuidedTorpedo, Pos + D3DXVECTOR2(-5.f, 10.f)
		, degree, upgrade));

	return 0;
}