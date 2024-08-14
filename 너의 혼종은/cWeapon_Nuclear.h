#pragma once
#include "cWeapon.h"

class cWeapon_Nuclear :public cWeapon
{
public:
	cWeapon_Nuclear();
	~cWeapon_Nuclear();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};