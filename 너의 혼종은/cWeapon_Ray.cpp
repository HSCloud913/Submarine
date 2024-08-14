#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Ray.h"



cWeapon_Ray::cWeapon_Ray()
	: cWeapon(100)

	, m_Pattern(-1)
{
}

cWeapon_Ray::~cWeapon_Ray()
{
}



INT cWeapon_Ray::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	if (m_Pattern == -1)
	{
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 60.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 45.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 30.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 15.f, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 15.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 30.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 45.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 60.f, upgrade));
	}

	else if (m_Pattern == 1)
	{
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 62.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 47.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 32.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 17.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree - 2.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 2.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 17.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 32.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 47.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Ray, pos, degree + 62.5f, upgrade));
	}

	m_Pattern *= -1;
	

	return 0;
}