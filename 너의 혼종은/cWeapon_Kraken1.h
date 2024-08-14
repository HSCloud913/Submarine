#pragma once
#include "cWeapon.h"

class cWeapon_Kraken1 :public cWeapon
{
public:
	cWeapon_Kraken1();
	~cWeapon_Kraken1();

private:
	INT m_Num;

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};