#pragma once
#include "c2DCoord.h"

class cTexList;
class c2DAni;

class cEffect :public c2DCoord
{
public:
	cEffect(cTexList* pTexList, INT frameNum, INT delay);
	~cEffect();

private:
	c2DAni* m_pAni;

public:
	INT Update();
	INT Render();

public:
	BOOL IsEnd() const;
};