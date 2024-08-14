#include "Util.h"

#include "cMsg.h"

#include "cMsgMgr.h"



cMsgMgr::cMsgMgr()
{
	m_pMsgList.clear();
}

cMsgMgr::~cMsgMgr()
{
	for (UINT i = 0; i < m_pMsgList.size(); i++)
	{
		SAFE_DELETE(m_pMsgList[i]);
	}

	m_pMsgList.clear();
}



INT cMsgMgr::PushMessage(LPCWSTR fontName, LPCWSTR msg, DWORD color)
{
	m_pMsgList.push_back(new cMsg(fontName, msg, color));

	for (UINT i = 0; i < m_pMsgList.size() - 1; i++)
	{
		m_pMsgList[i]->AddYPos(65);
	}

	return 0;
}



INT cMsgMgr::Update()
{
	for (UINT i = 0; i < m_pMsgList.size(); i++)
	{
		m_pMsgList[i]->Update();

		if (m_pMsgList[i]->GetShowTime() <= 1.f)
		{
			SAFE_DELETE(m_pMsgList[i]);
			m_pMsgList.erase(m_pMsgList.begin() + i);

			i--;
			continue;
		}
	}

	return 0;
}

INT cMsgMgr::Render()
{
	for (UINT i = 0; i < m_pMsgList.size(); i++)
	{
		m_pMsgList[i]->Render();
	}

	return 0;
}