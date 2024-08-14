#pragma once
#include "cWeapon.h"

class cWeapon_Kraken2 :public cWeapon
{
public:
	cWeapon_Kraken2();
	~cWeapon_Kraken2();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};