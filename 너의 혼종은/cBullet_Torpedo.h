#pragma once
#include "cBullet.h"

class cBullet_Torpedo :public cBullet
{
public:
	cBullet_Torpedo(INT upgrade);
	~cBullet_Torpedo();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};