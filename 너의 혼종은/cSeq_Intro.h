#pragma once
#include "cSequence.h"

class cFade;

class cSeq_Intro :public cSequence
{
public:
	cSeq_Intro();
	~cSeq_Intro();

private:
	cFade* m_pFade;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};