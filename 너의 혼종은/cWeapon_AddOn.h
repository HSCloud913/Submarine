#pragma once
#include "cWeapon.h"

class cWeapon_AddOn :public cWeapon
{
public:
	cWeapon_AddOn();
	~cWeapon_AddOn();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};