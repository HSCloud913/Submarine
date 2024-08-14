#include "cData.h"

#include "BulletFactory.h"

#include "cWeapon_Kraken1.h"



cWeapon_Kraken1::cWeapon_Kraken1()
	: cWeapon(100)

	, m_Num(-1)
{
}

cWeapon_Kraken1::~cWeapon_Kraken1()
{
}



INT cWeapon_Kraken1::OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	if (m_Num == -1)
	{
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 0, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 20, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 40, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 60, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 80, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 100, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 120, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 140, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 160, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 180, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 200, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 220, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 240, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 260, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 280, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 300, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 320, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 340, upgrade));
	}

	else
	{
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 10, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 30, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 50, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 70, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 90, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 110, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 130, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 150, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 170, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 190, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 210, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 230, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 250, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 270, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 290, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 310, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 330, upgrade));
		pData->AddObject(BulletFactory::Create(Bullet::Kraken, pos, 350, upgrade));
	}

	m_Num *= -1;

	return 0;
}