#pragma once
#include <vector>

class cTexture;

class cTexList
{
public:
	cTexList();
	~cTexList();

private:
	std::vector<cTexture*> m_pTexList;

public:
	UINT GetSize() const;

public:
	INT AddTexture(LPCWSTR fileName);
	INT AddTexture(cTexture* pTex);

	INT DeleteTexture(UINT Idx);
	INT DeleteAllTeture();

public:
	cTexture* GetTexture(UINT Idx) const;
};