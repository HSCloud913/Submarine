#pragma once
#include "cBullet.h"

class cBullet_AddOn :public cBullet
{
public:
	cBullet_AddOn();
	~cBullet_AddOn();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};