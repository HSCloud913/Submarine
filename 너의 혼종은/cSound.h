#pragma once
#include <dsound.h>

#define DSBCAPS_CTRLDEFAULT (DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN)
#define DSVOLUME_TO_DB(vol) ((DWORD) -30 * (100 - vol))

class cSound
{
public:
	cSound();
	~cSound();

private:
	LPDIRECTSOUND m_pDS;
	LPDIRECTSOUNDBUFFER m_pDSBuffer;

public:
	INT Create(LPWSTR fileName);
	INT CleanUp();

public:
	INT SetVolume(INT vol);
	INT SetPan(INT pan);

public:
	INT Play(BOOL bLoop);
	INT Pause();
	INT Stop();
};