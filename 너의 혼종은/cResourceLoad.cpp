#include "Util.h"

#include "cTimer.h"
#include "cFont.h"

#include "cResourceLoad.h"



cResourceLoad::cResourceLoad()
	: m_pTimer(nullptr)
	, m_pFont(new cFont)

	, m_LoadState(Img)

	, m_PathNum(-1)
	, m_LoadTime(0)

	, m_bEnd(FALSE)
{
	m_pFont->Create(L"휴먼편지체 보통", 10, 20);
}

cResourceLoad::~cResourceLoad()
{
	if (m_pTimer != nullptr)
	{
		SAFE_DELETE(m_pTimer);
	}

	if (m_pFont != nullptr)
	{
		SAFE_DELETE(m_pFont);
	}
}



INT cResourceLoad::Init()
{
	if (m_LoadState == Img)
	{
		m_File.open(L"Path/Img/1.txt");
	}

	else if (m_LoadState == Sound)
	{
		m_File.open(L"Path/Sound/1.txt");
	}

	else
	{
		lstrcpyW(m_Path, L"Please Wait");
		m_LoadTime = timeGetTime() + 2000;

		return 0;
	}

	if (m_File.is_open())
	{
		if (m_LoadState == Img)
		{
			lstrcpyW(m_Path, L"Prepare Img");
			cSystem::Resource.AddTexList();
		}

		else
		{ // Sound
			lstrcpyW(m_Path, L"Prepare Sound");
			cSystem::Resource.AddSoundList();
		}
		 
		m_PathNum = 0;

		m_LoadTime = timeGetTime() + 1000;
	}

	else
	{
		if (m_LoadState == Img)
		{
			m_LoadState = Sound;
		}

		else
		{ // Sound
			m_LoadState = End;
		}

		lstrcpyW(m_Path, L"Complete");
		Init();
	}

	return 0;
}


INT cResourceLoad::Loading()
{
	if (m_pTimer != nullptr)
	{
		m_pTimer->Update();

		if (m_pTimer->IsEnd())
		{
			m_bEnd = TRUE;

			SAFE_DELETE(m_pTimer);
		}
	}

	else
	{
		if (!m_bEnd)
		{
			if (timeGetTime() < m_LoadTime)
			{
				return 0;
			}

			else
			{
				if (m_LoadState == End)
				{
					m_pTimer = new cTimer(0, 4);
					m_pTimer->Play();
				}

				else
				{
					if (m_File.eof())
					{
						m_File.close();

						m_PathNum++;

						WCHAR Buffer[256];

						if (m_LoadState == Img)
						{
							swprintf_s(Buffer, 255, L"Path/Img/%d.txt", m_PathNum + 1);
						}

						else
						{ // Sound
							swprintf_s(Buffer, 255, L"Path/Sound/%d.txt", m_PathNum + 1);
						}

						m_File.open(Buffer);

						if (m_File.is_open())
						{
							if (m_LoadState == Img)
							{
								cSystem::Resource.AddTexList();
							}

							else
							{ // Sound
								cSystem::Resource.AddSoundList();
							}
						}

						else
						{
							if (m_LoadState == Img)
							{
								m_LoadState = Sound;
							}

							else
							{ // Sound
								m_LoadState = End;
							}

							return Init();
						}
					}

					else
					{
						wmemset(m_Path, L'\0', 255);

						CHAR Str[256];
						m_File.getline(Str, 255);

						INT Len = strlen(Str);
						INT wLen = MultiByteToWideChar(CP_ACP, 0, Str, Len, nullptr, 0);
						MultiByteToWideChar(CP_ACP, 0, Str, Len, m_Path, wLen);

						if (m_LoadState == Img)
						{
							cSystem::Resource.CreateTexture(
								cSystem::Resource.m_pTexList[m_PathNum], m_Path);
						}

						else
						{ // Sound
							cSystem::Resource.CreateSound(
								cSystem::Resource.m_pSoundList[m_PathNum], m_Path);
						}
					}

					m_LoadTime = timeGetTime() + 1;
				}
			}
		}
	}

	return 0;
}

INT cResourceLoad::Render()
{
	if (!m_bEnd)
	{
		m_pFont->ShowText(m_Path, cSystem::CenterPt.x, cSystem::CenterPt.y
			, D3DCOLOR_ARGB(255, 255, 255, 255), DT_CENTER);
	}

	return 0;
}



BOOL cResourceLoad::IsEnd() const
{
	return m_bEnd;
}