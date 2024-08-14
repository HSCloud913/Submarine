#pragma once
#include "cWeapon.h"

class cWeapon_R_MonkFish :public cWeapon
{
public:
	cWeapon_R_MonkFish();
	~cWeapon_R_MonkFish();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};