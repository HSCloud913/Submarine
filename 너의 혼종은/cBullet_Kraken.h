#pragma once
#include "cBullet.h"

class cBullet_Kraken :public cBullet
{
public:
	cBullet_Kraken();
	~cBullet_Kraken();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};