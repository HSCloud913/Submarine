#pragma once
#include "cSequence.h"

class cFade;

class cSeq_Ending :public cSequence
{
public:
	cSeq_Ending(BOOL bClear, INT score = 0);
	~cSeq_Ending();

private:
	cFade* m_pFade;

private:
	INT m_Score;
	BOOL m_bClear;
	BOOL m_bReturn;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};