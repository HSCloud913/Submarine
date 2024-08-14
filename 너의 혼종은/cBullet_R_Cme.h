#pragma once
#include "cBullet.h"

class cBullet_R_Cme :public cBullet
{
public:
	cBullet_R_Cme();
	~cBullet_R_Cme();
	
private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};