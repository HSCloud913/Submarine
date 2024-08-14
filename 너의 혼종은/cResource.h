#pragma once
#include <vector>
#include "cFont.h"
#include "cTexList.h"
#include "cSoundList.h"

#include "TexListName.h"
#include "SoundListName.h"

class cResource
{
public:
	cResource();
	~cResource();

public:
	cFont m_Font;
	cFont m_DebugFont;

public:
	std::vector<cTexList*> m_pTexList;
	std::vector<cSoundList*> m_pSoundList;

public:
	INT Init();

public:
	INT AddTexList();
	INT AddSoundList();

public:
	INT CreateTexture(cTexList* pTexList, LPCWSTR fileName);
	INT CreateSound(cSoundList* pSoundList, LPWSTR fileName);
};