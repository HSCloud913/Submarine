#include "cData.h"

#include "cWeapon.h"



cWeapon::cWeapon(DWORD delay)
	: m_PrevTime(timeGetTime())
	, m_Delay(delay)
{
}

cWeapon::~cWeapon()
{
}



INT cWeapon::UseWeapon(cData* pData, const D3DXVECTOR2& pos, FLOAT degree, INT upgrade)
{
	if (timeGetTime() - m_PrevTime >= m_Delay)
	{
		m_PrevTime = timeGetTime();

		return OnUseWeapon(pData, pos, degree, upgrade);
	}

	return -1;
}



BOOL cWeapon::IsReady() const
{
	if (timeGetTime() - m_PrevTime >= m_Delay)
	{
		return TRUE;
	}

	return FALSE;
}