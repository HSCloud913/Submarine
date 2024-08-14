#pragma once
#include "cBullet.h"

class cBullet_Nuclear :public cBullet
{
public:
	cBullet_Nuclear();
	~cBullet_Nuclear();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};