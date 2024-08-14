#pragma once
#include "cWeapon.h"

class cWeapon_OnceTorpedo :public cWeapon
{
public:
	cWeapon_OnceTorpedo();
	~cWeapon_OnceTorpedo();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};