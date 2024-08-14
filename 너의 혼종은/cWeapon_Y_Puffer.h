#pragma once
#include "cWeapon.h"

class cWeapon_Y_Puffer :public cWeapon
{
public:
	cWeapon_Y_Puffer();
	~cWeapon_Y_Puffer();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};