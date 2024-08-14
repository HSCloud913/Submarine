#pragma once
#include "cBullet.h"

class cBullet_R_MonkFish :public cBullet
{
public:
	cBullet_R_MonkFish();
	~cBullet_R_MonkFish();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};