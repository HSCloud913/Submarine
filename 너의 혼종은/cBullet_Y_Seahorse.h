#pragma once
#include "cBullet.h"

class cBullet_Y_Seahorse :public cBullet
{
public:
	cBullet_Y_Seahorse();
	~cBullet_Y_Seahorse();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};