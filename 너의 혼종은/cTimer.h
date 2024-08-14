#pragma once
#include <Windows.h>

class cTimer
{
public:
	cTimer(INT min = 0, INT sec = 0);
	~cTimer();

private:
	INT m_SaveTime;
	INT m_Time;

private:
	DWORD m_StartTime;
	DWORD m_PauseTime;
	DWORD m_LastPauseTime;

private:
	BOOL m_bPlay;
	BOOL m_bEnd;

public:
	INT Update();

public:
	INT Play();
	INT Pause();
	INT Reset();

public:
	INT GetTime() const;

public:
	BOOL IsPlay() const;
	BOOL IsEnd() const;
};