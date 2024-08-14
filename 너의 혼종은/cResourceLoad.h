#pragma once
#include <fstream>

class cTimer;
class cFont;

class cResourceLoad
{
public:
	cResourceLoad();
	~cResourceLoad();

private:
	cTimer* m_pTimer;
	cFont* m_pFont;

private:
	enum Load
	{
		Img
		, Sound
		, End
	};

	Load m_LoadState;

private:
	std::fstream m_File;
	DWORD m_LoadTime;
 
	WCHAR m_Path[256];
	INT m_PathNum;

private:
	BOOL m_bEnd;

public:
	INT Init();

	INT Loading();
	INT Render();

public:
	BOOL IsEnd() const;
};