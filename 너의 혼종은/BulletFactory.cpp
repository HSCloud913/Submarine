#include "Util.h"

#include "cBullet_Torpedo.h"
#include "cBullet_GuidedTorpedo.h"
#include "cBullet_Nuclear.h"
#include "cBullet_AddOn.h"

#include "cBullet_Y_Seahorse.h"
#include "cBullet_R_Seahorse.h"
#include "cBullet_Y_Puffer.h"
#include "cBullet_R_Puffer.h"
#include "cBullet_P_Cme.h"
#include "cBullet_R_Cme.h"
#include "cBullet_Y_MonkFish.h"
#include "cBullet_R_MonkFish.h"

#include "cBullet_Ray.h"
#include "cBullet_Whale.h"
#include "cBullet_Shark.h"
#include "cBullet_Kraken.h"

#include "BulletFactory.h"



BulletFactory::BulletFactory()
{
}

BulletFactory::~BulletFactory()
{
}



cBullet* BulletFactory::Create(Bullet::_Type bulletType, const D3DXVECTOR2& pos
	, FLOAT degree, INT upgrade)
{
	cBullet* pBullet = nullptr;

	switch (bulletType)
	{
	case Bullet::Torpedo:
		pBullet = new cBullet_Torpedo(upgrade);
		break;

	case Bullet::GuidedTorpedo:
		pBullet = new cBullet_GuidedTorpedo(upgrade);
		break;

	case Bullet::Nuclear:
		pBullet = new cBullet_Nuclear();
		break;

	case Bullet::AddOn:
		pBullet = new cBullet_AddOn();
		break;

	case Bullet::Y_Seahorse:
		pBullet = new cBullet_Y_Seahorse();
		break;

	case Bullet::R_Seahorse:
		pBullet = new cBullet_R_Seahorse();
		break;

	case Bullet::Y_Puffer:
		pBullet = new cBullet_Y_Puffer();
		break;

	case Bullet::R_Puffer:
		pBullet = new cBullet_R_Puffer();
		break;

	case Bullet::P_Cme:
		pBullet = new cBullet_P_Cme();
		break;

	case Bullet::R_Cme:
		pBullet = new cBullet_R_Cme();
		break;

	case Bullet::Y_MonkFish:
		pBullet = new cBullet_Y_MonkFish();
		break;

	case Bullet::R_MonkFish:
		pBullet = new cBullet_R_MonkFish();
		break;

	case Bullet::Ray:
		pBullet = new cBullet_Ray();
		break;

	case Bullet::Whale:
		pBullet = new cBullet_Whale();
		break;

	case Bullet::Shark:
		pBullet = new cBullet_Shark();
		break;

	case Bullet::Kraken:
		pBullet = new cBullet_Kraken();
		break;
	}

	if (pBullet != nullptr)
	{
		D3DXVECTOR2 Direction(0.f, 0.f);
		Util::GetPosition(&Direction, degree);
		Direction *= pBullet->GetMoveSpeed();

		pBullet->SetPos(&pos);
		pBullet->SetSpeed(&Direction);

		pBullet->SetAngle(degree);
	}

	return pBullet;
}