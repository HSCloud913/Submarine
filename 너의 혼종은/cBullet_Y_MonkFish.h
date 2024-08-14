#pragma once
#include "cBullet.h"

class cBullet_Y_MonkFish :public cBullet
{
public:
	cBullet_Y_MonkFish();
	~cBullet_Y_MonkFish();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};