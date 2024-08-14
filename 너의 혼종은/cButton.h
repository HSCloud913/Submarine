#pragma once
#include "c2DCoord.h"

class cTexture;

class cButton :public c2DCoord
{
public:
	cButton(cTexture* pTex, const D3DXVECTOR2& pos);
	~cButton();

private:
	enum State
	{
		None
		, Focus
		, Up
		, Down
		, Press
	};

	State m_State;

private:
	cTexture* m_pTex;

public:
	INT Update();
	INT Render();

public:
	BOOL IsFocus() const;
	BOOL IsUp() const;
	BOOL IsDown() const;
	BOOL IsPress() const;
};