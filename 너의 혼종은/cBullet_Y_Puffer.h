#pragma once
#include "cBullet.h"

class cBullet_Y_Puffer :public cBullet
{
public:
	cBullet_Y_Puffer();
	~cBullet_Y_Puffer();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};