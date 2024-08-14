#pragma once
#include "cBullet.h"

class cBullet_P_Cme :public cBullet
{
public:
	cBullet_P_Cme();
	~cBullet_P_Cme();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};