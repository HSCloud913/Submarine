#pragma once
#include "c2DCoord.h"

class cCamera :public c2DCoord
{
public:
	cCamera();
	~cCamera();

public:
	INT FrameMove();
	INT Control();
	INT Reset();

public:
	virtual const D3DXVECTOR2* Pos() const override;
	virtual D3DXMATRIX* Matrix() override;
};