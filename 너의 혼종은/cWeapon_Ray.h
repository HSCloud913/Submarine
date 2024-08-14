#pragma once
#include "cWeapon.h"

class cWeapon_Ray :public cWeapon
{
public:
	cWeapon_Ray();
	~cWeapon_Ray();

private:
	INT m_Pattern;

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};