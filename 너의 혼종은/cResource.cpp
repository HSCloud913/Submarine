#include "Util.h"

#include "cResource.h"



cResource::cResource()
{
	m_pTexList.clear();
	m_pSoundList.clear();
}

cResource::~cResource()
{
	for (UINT i = 0; i < m_pTexList.size(); i++)
	{
		SAFE_DELETE(m_pTexList[i]);
	}

	for (UINT i = 0; i < m_pSoundList.size(); i++)
	{
		SAFE_DELETE(m_pSoundList[i]);
	}

	m_pTexList.clear();
	m_pSoundList.clear();
}



INT cResource::Init()
{
	m_Font.Create(L"µ¸¿ò", 10, 20);
	m_DebugFont.Create(L"µ¸¿ò", 8, 16);

	return 0;
}


INT cResource::AddTexList()
{
	m_pTexList.push_back(new cTexList);
	
	return 0;
}

INT cResource::AddSoundList()
{
	m_pSoundList.push_back(new cSoundList);

	return 0;
}


INT cResource::CreateTexture(cTexList* pTexList, LPCWSTR fileName)
{
	if (pTexList != nullptr)
	{
		pTexList->AddTexture(fileName);
	}

	return 0;
}

INT cResource::CreateSound(cSoundList* pSoundList, LPWSTR fileName)
{
	if (pSoundList != nullptr)
	{
		pSoundList->AddSound(fileName);
	}

	return 0;
}