#pragma once
#include "cWeapon.h"

class cWeapon_R_Cme :public cWeapon
{
public:
	cWeapon_R_Cme();
	~cWeapon_R_Cme();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};