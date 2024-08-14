#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Kraken2.h"



cWeapon_Kraken2::cWeapon_Kraken2()
	: cWeapon(50)
{
}

cWeapon_Kraken2::~cWeapon_Kraken2()
{
}



INT cWeapon_Kraken2::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, -64.f)
		, degree - 25.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, 64.f)
		,degree - 25.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos
		, degree - 25.f, upgrade));

	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, -64.f), degree, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, 64.f), degree, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, degree, upgrade));

	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, -64.f)
		, degree + 25.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos + D3DXVECTOR2(32.f, 64.f)
		, degree + 25.f, upgrade));
	pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos
		, degree + 25.f, upgrade));

	return 0;
}