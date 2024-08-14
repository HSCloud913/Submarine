#pragma once

class cSequence;

class cSeqMgr
{
public:
	cSeqMgr();
	~cSeqMgr();

private:
	cSequence* m_pCurrSeq;

public:
	INT Init();
	INT CleanUp();

	INT Update();
	INT Render();
};