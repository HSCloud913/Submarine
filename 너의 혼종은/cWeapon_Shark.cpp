#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Shark.h"



cWeapon_Shark::cWeapon_Shark()
	: cWeapon(100)

	, m_Pattern(-1)
{
}

cWeapon_Shark::~cWeapon_Shark()
{
}



INT cWeapon_Shark::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	if (m_Pattern == -1)
	{
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 60.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 45.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 30.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 15.f, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 15.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 30.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 45.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 60.f, upgrade));
	}

	else if (m_Pattern == 1)
	{
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 50.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 35.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 20.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 5.f, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree - 2.5f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 2.5f, upgrade));

		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 5.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 20.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 35.f, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Shark, pos, degree + 50.f, upgrade));
	}

	m_Pattern *= -1;

	return 0;
}