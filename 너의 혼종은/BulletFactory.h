#pragma once
#include "cBullet.h"

class BulletFactory
{
private:
	BulletFactory();
	~BulletFactory();

public:
	static cBullet* Create(Bullet::_Type bulletType, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade);
};