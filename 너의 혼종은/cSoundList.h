#pragma once
#include <vector>

class cSound;

class cSoundList
{
public:
	cSoundList();
	~cSoundList();

private:
	std::vector<cSound*> m_pSoundList;

public:
	UINT GetSize() const;

public:
	INT AddSound(LPWSTR fileName);
	INT AddSound(cSound* pSound);

	INT DeleteSound(UINT Idx);
	INT DeleteAllTeture();

public:
	cSound* GetSound(UINT Idx) const;
};