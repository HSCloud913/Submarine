#pragma once
#include "cBullet.h"

class cBullet_R_Seahorse :public cBullet
{
public:
	cBullet_R_Seahorse();
	~cBullet_R_Seahorse();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};