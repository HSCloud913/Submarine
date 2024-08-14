#pragma once
#include <Windows.h>

class cFont;

class cData;

class cUI
{
public:
	cUI();
	~cUI();

private:
	cFont* m_pFont;

public:
	INT m_Gauge;
	INT m_Score;
	INT m_Nuclear;

public:
	INT Update(cData* pData);
	INT Render();
};