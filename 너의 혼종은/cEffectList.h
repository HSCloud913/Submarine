#pragma once
#include <vector>

class cEffect;

class cEffectList
{
public:
	cEffectList();
	~cEffectList();

private:
	std::vector<cEffect*> m_pEffect;

public:
	INT Update();
	INT Render();

public:
	INT AddEffect(cTexList* pTex, INT frameNum, DWORD delay, const D3DXVECTOR2& pos);
};