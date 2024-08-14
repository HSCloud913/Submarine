#include "Util.h"

#include "cTexture.h"

#include "cTexList.h"



cTexList::cTexList()
{
	m_pTexList.clear();
}

cTexList::~cTexList()
{
	DeleteAllTeture();
}



UINT cTexList::GetSize() const
{
	return m_pTexList.size();
}



INT cTexList::AddTexture(LPCWSTR fileName)
{
	UINT Idx = m_pTexList.size();
	m_pTexList.push_back(new cTexture);
	m_pTexList[Idx]->Create(fileName);

	return 0;
}

INT cTexList::AddTexture(cTexture* pTex)
{
	m_pTexList.emplace_back(pTex);

	return 0;
}


INT cTexList::DeleteTexture(UINT Idx)
{
	if (Idx < m_pTexList.size())
	{
		SAFE_DELETE(m_pTexList[Idx]);
		m_pTexList.erase(m_pTexList.begin() + Idx);
	}

	return 0;
}

INT cTexList::DeleteAllTeture()
{
	for (UINT i = 0; i < m_pTexList.size(); i++)
	{
		SAFE_DELETE(m_pTexList[i]);
	}

	m_pTexList.clear();

	return 0;
}



cTexture* cTexList::GetTexture(UINT Idx) const
{
	if (Idx < m_pTexList.size())
	{
		return m_pTexList[Idx];
	}

	return nullptr;
}