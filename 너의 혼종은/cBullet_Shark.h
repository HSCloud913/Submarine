#pragma once
#include "cBullet.h"

class cBullet_Shark :public cBullet
{
public:
	cBullet_Shark();
	~cBullet_Shark();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};