#include "Util.h"

#include "cSequence.h"

#include "cSeq_Load.h"
#include "cSeqMgr.h"



cSeqMgr::cSeqMgr()
	: m_pCurrSeq(new cSeq_Load)
{
}

cSeqMgr::~cSeqMgr()
{
	if (m_pCurrSeq != nullptr)
	{
		SAFE_DELETE(m_pCurrSeq);
	}
}



INT cSeqMgr::Init()
{
	if (m_pCurrSeq != nullptr)
	{
		m_pCurrSeq->Init();
	}

	return 0;
}

INT cSeqMgr::CleanUp()
{
	if (m_pCurrSeq != nullptr)
	{
		m_pCurrSeq->CleanUp();
	}

	return 0;
}


INT cSeqMgr::Update()
{
	cSequence* pNextSeq = m_pCurrSeq->Update();

	if (pNextSeq == nullptr)
	{
		m_pCurrSeq->CleanUp();

		cSystem::ExitProgram();

		return 0;
	}

	else if (pNextSeq != m_pCurrSeq)
	{
		cSystem::Camera.Reset();

		m_pCurrSeq->CleanUp();

		m_pCurrSeq = pNextSeq;
		m_pCurrSeq->Init();

		return 0;
	}

	return 0;
}

INT cSeqMgr::Render()
{
	if (m_pCurrSeq != nullptr)
	{
		m_pCurrSeq->Render();
	}

	return 0;
}