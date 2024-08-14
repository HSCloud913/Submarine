#pragma once
#include "cWeapon.h"

class cWeapon_GuidedTorpedo :public cWeapon
{
public:
	cWeapon_GuidedTorpedo();
	~cWeapon_GuidedTorpedo();

private:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) override;
};