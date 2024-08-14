#pragma once
#include "cBullet.h"

class cBullet_Ray :public cBullet
{
public:
	cBullet_Ray();
	~cBullet_Ray();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};