#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_TripleTorpedo.h"



cWeapon_TripleTorpedo::cWeapon_TripleTorpedo()
	: cWeapon(100)
{
}

cWeapon_TripleTorpedo::~cWeapon_TripleTorpedo()
{
}



INT cWeapon_TripleTorpedo::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	D3DXVECTOR2 Pos = pos;
	Pos.x += 75.f;
	Pos.y += 40.f;

	pData->AddObject(BulletFactory::Create(Bullet::Torpedo, Pos + D3DXVECTOR2(0.f, -10.f)
		, degree - 5.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Torpedo, Pos, degree, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Torpedo, Pos + D3DXVECTOR2(0.f, 10.f)
		, degree + 5.f, upgrade));

	return 0;
}