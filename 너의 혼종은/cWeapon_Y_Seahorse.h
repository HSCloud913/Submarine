#pragma once
#include "cWeapon.h"

class cWeapon_Y_Seahorse :public cWeapon
{
public:
	cWeapon_Y_Seahorse();
	~cWeapon_Y_Seahorse();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};