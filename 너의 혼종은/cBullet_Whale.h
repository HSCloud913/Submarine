#pragma once
#include "cBullet.h"

class cBullet_Whale :public cBullet
{
public:
	cBullet_Whale();
	~cBullet_Whale();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};