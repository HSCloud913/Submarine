#pragma once
#include "cWeapon.h"

class cWeapon_Shark :public cWeapon
{
public:
	cWeapon_Shark();
	~cWeapon_Shark();

private:
	INT m_Pattern;

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};