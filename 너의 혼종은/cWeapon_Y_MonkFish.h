#pragma once
#include "cWeapon.h"

class cWeapon_Y_MonkFish :public cWeapon
{
public:
	cWeapon_Y_MonkFish();
	~cWeapon_Y_MonkFish();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};