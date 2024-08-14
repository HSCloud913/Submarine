#pragma once
#include "cWeapon.h"

class cWeapon_R_Puffer :public cWeapon
{
public:
	cWeapon_R_Puffer();
	~cWeapon_R_Puffer();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};