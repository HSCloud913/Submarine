#pragma once
#include <Windows.h>
#include <vector>

class cMsg;

class cMsgMgr
{
public:
	cMsgMgr();
	~cMsgMgr();

private:
	std::vector<cMsg*> m_pMsgList;

public:
	INT PushMessage(LPCWSTR fontName, LPCWSTR msg, DWORD color);

public:
	INT Update();
	INT Render();
};