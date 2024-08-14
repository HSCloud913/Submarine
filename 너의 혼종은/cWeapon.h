#pragma once
#include <d3dx9.h>
#include "Type.h"

class cData;

class cWeapon
{
public:
	cWeapon(DWORD delay);
	virtual ~cWeapon();

protected:
	DWORD m_PrevTime;
	DWORD m_Delay;

public:
	INT UseWeapon(cData* pData, const D3DXVECTOR2& pos, FLOAT degree, INT upgrade);

protected:
	virtual INT OnUseWeapon(cData* pData, const D3DXVECTOR2& pos
		, FLOAT degree, INT upgrade) = 0;

public:
	BOOL IsReady() const;
};