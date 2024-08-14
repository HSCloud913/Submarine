#pragma once
#include "cWeapon.h"

class cWeapon_R_Seahorse :public cWeapon
{
public:
	cWeapon_R_Seahorse();
	~cWeapon_R_Seahorse();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};