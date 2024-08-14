#pragma once
#include "cBullet.h"

class cBullet_R_Puffer :public cBullet
{
public:
	cBullet_R_Puffer();
	~cBullet_R_Puffer();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};