#pragma once
#include "cBullet.h"

class cBullet_GuidedTorpedo :public cBullet
{
public:
	cBullet_GuidedTorpedo(INT upgrade);
	~cBullet_GuidedTorpedo();

private:
	virtual INT OnUpdateBullet(cData* pData) override;
	virtual INT OnRenderBullet() override;
};