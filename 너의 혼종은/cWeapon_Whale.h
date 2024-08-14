#pragma once
#include "cWeapon.h"

class cWeapon_Whale :public cWeapon
{
public:
	cWeapon_Whale();
	~cWeapon_Whale();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};