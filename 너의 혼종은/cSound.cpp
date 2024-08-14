#include "Util.h"

#include "cSound.h"



cSound::cSound()
	: m_pDS(nullptr)
	, m_pDSBuffer(nullptr)
{
}

cSound::~cSound()
{
	CleanUp();
}



INT cSound::Create(LPWSTR fileName)
{
	if (FAILED(DirectSoundCreate(NULL, &m_pDS, NULL)))
	{
		return Util::ErrorMessage(L"DirectSoundCreate");
	}

	if (FAILED(m_pDS->SetCooperativeLevel(cSystem::hWnd, DSSCL_NORMAL)))
	{
		return Util::ErrorMessage(L"DirectSoundCreate");
	}

	HMMIO hmmio;
	MMCKINFO ckIn, ckInRIFF;
	WAVEFORMATEX WaveFmt;

	hmmio = mmioOpenW(fileName, nullptr, MMIO_READ | MMIO_ALLOCBUF);

	if (hmmio != nullptr)
	{
		memset(&ckIn, 0, sizeof(MMCKINFO));
		ckIn.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		if (mmioDescend(hmmio, &ckIn, nullptr, MMIO_FINDRIFF))
		{
			mmioClose(hmmio, 0);
			return Util::ErrorMessage(L"mmioDescend WAVE");
		}

		memset(&ckInRIFF, 0, sizeof(MMCKINFO));
		ckInRIFF.fccType = mmioFOURCC('f', 'm', 't', ' ');
		if (mmioDescend(hmmio, &ckInRIFF, &ckIn, 0))
		{
			mmioClose(hmmio, 0);
			return Util::ErrorMessage(L"mmioDescend WAVE");
		}

		mmioRead(hmmio, (char*)&WaveFmt, sizeof(WaveFmt));
		if (WaveFmt.wFormatTag != WAVE_FORMAT_PCM)
		{
			mmioClose(hmmio, 0);
			return Util::ErrorMessage(L"WaveFmt.wFormatTag");
		}

		mmioAscend(hmmio, &ckInRIFF, 0);
		ckInRIFF.ckid = mmioFOURCC('d', 'a', 't', 'a');
		if (mmioDescend(hmmio, &ckInRIFF, &ckIn, MMIO_FINDCHUNK))
		{
			mmioClose(hmmio, 0);
			return Util::ErrorMessage(L"mmioDescend data");
		}

		DSBUFFERDESC dsbd;
		ZeroMemory(&dsbd, sizeof(DSBUFFERDESC));

		dsbd.dwSize = sizeof(DSBUFFERDESC);
		dsbd.dwBufferBytes = ckInRIFF.cksize;
		dsbd.dwFlags = DSBCAPS_CTRLDEFAULT | DSBCAPS_LOCSOFTWARE | DSBCAPS_LOCSOFTWARE;
		dsbd.lpwfxFormat = &WaveFmt;

		if (FAILED(m_pDS->CreateSoundBuffer(&dsbd, &m_pDSBuffer, nullptr)))
		{
			return Util::ErrorMessage(L"CreateSoundBuffer");
		}

		void *Write1 = nullptr, *Write2 = nullptr;
		DWORD Length1, Length2;

		if (FAILED(m_pDSBuffer->Lock(0, ckInRIFF.cksize
			, &Write1, &Length1, &Write2, &Length2, 0)))
		{
			return Util::ErrorMessage(L"m_pDSBuffer->Lock");
		}

		if (Write1 > 0)
		{
			mmioRead(hmmio, (char*)Write1, Length1);
		}

		if (Write2 > 0)
		{
			mmioRead(hmmio, (char*)Write2, Length2);
		}

		m_pDSBuffer->Unlock(Write1, Length1, Write2, Length2);
	}

	return 0;
}

INT cSound::CleanUp()
{
	if (m_pDSBuffer != nullptr)
	{
		SAFE_RELEASE(m_pDSBuffer);
	}

	if (m_pDS != nullptr)
	{
		SAFE_RELEASE(m_pDS);
	}

	return 0;
}



INT cSound::SetVolume(INT vol)
{
	if (vol < 0)
	{
		vol = 0;
	}

	if (vol > 100)
	{
		vol = 100;
	}

	m_pDSBuffer->SetVolume(DSVOLUME_TO_DB(vol));

	return 0;
}

INT cSound::SetPan(INT pan)
{
	if (pan < -10000)
	{
		pan = -10000;
	}

	if (pan > 10000)
	{
		pan = 10000;
	}

	m_pDSBuffer->SetPan(pan);

	return 0;
}



INT cSound::Play(BOOL bLoop)
{
	m_pDSBuffer->Play(0, 0, (bLoop) ? DSBPLAY_LOOPING : 0);

	return 0;
}

INT cSound::Pause()
{
	m_pDSBuffer->Stop();

	return 0;
}

INT cSound::Stop()
{
	m_pDSBuffer->Stop();
	m_pDSBuffer->SetCurrentPosition(0);
	return 0;
}