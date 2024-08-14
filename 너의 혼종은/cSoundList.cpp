#include "Util.h"

#include "cSound.h"

#include "cSoundList.h"



cSoundList::cSoundList()
{
	m_pSoundList.clear();
}

cSoundList::~cSoundList()
{
	DeleteAllTeture();
}



UINT cSoundList::GetSize() const
{
	return m_pSoundList.size();
}



INT cSoundList::AddSound(LPWSTR fileName)
{
	UINT Idx = m_pSoundList.size();
	m_pSoundList.push_back(new cSound);
	m_pSoundList[Idx]->Create(fileName);

	return 0;
}

INT cSoundList::AddSound(cSound* pSound)
{
	m_pSoundList.emplace_back(pSound);

	return 0;
}


INT cSoundList::DeleteSound(UINT Idx)
{
	if (Idx < m_pSoundList.size())
	{
		SAFE_DELETE(m_pSoundList[Idx]);
		m_pSoundList.erase(m_pSoundList.begin() + Idx);
	}

	return 0;
}

INT cSoundList::DeleteAllTeture()
{
	for (UINT i = 0; i < m_pSoundList.size(); i++)
	{
		SAFE_DELETE(m_pSoundList[i]);
	}

	m_pSoundList.clear();

	return 0;
}



cSound* cSoundList::GetSound(UINT Idx) const
{
	if (Idx < m_pSoundList.size())
	{
		return m_pSoundList[Idx];
	}

	return nullptr;
}