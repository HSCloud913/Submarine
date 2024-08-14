#include "cTimer.h"



cTimer::cTimer(INT min, INT sec)
	: m_SaveTime(min * 60 + sec)
	, m_Time(m_SaveTime)
	
	, m_StartTime(0)
	, m_PauseTime(0)
	, m_LastPauseTime(0)

	, m_bPlay(FALSE)
	, m_bEnd(FALSE)
{
}

cTimer::~cTimer()
{
}



INT cTimer::Update()
{
	if (m_bPlay && !m_bEnd)
	{
		DWORD NowTime = timeGetTime() / 1000 - m_StartTime - m_PauseTime;

		m_Time = m_SaveTime - NowTime;

		if (m_Time == 0)
		{
			m_bPlay = FALSE;
			m_bEnd = TRUE;
		}
	}

	return 0;
}



INT cTimer::Play()
{
	if (m_LastPauseTime != 0)
	{
		m_PauseTime += timeGetTime() / 1000 - m_LastPauseTime;
		m_LastPauseTime = 0;
		m_bPlay = TRUE;
	}

	if (m_PauseTime == 0)
	{
		m_StartTime = timeGetTime() / 1000;
		m_bPlay = TRUE;
	}

	return 0;
}

INT cTimer::Pause()
{
	if (m_bPlay)
	{
		m_LastPauseTime = timeGetTime() / 1000;
		m_bPlay = FALSE;
	}

	return 0;
}

INT cTimer::Reset()
{
	m_Time = m_SaveTime;

	m_StartTime = 0;
	m_PauseTime = 0;
	m_LastPauseTime = 0;

	m_bPlay = FALSE;
	m_bEnd = FALSE;

	return 0;
}



INT cTimer::GetTime() const
{
	return m_Time;
}



BOOL cTimer::IsPlay() const
{
	return m_bPlay;
}

BOOL cTimer::IsEnd() const
{
	return m_bEnd;
}