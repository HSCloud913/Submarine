#pragma once
#include "cWeapon.h"

class cWeapon_P_Cme :public cWeapon
{
public:
	cWeapon_P_Cme();
	~cWeapon_P_Cme();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};