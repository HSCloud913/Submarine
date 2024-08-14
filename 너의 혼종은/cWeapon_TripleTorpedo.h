#pragma once
#include "cWeapon.h"

class cWeapon_TripleTorpedo :public cWeapon
{
public:
	cWeapon_TripleTorpedo();
	~cWeapon_TripleTorpedo();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};