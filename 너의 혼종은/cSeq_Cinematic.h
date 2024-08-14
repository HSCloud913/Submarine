#pragma once
#include "cSequence.h"

class cFade;

class cSeq_Cinematic :public cSequence
{
public:
	cSeq_Cinematic();
	~cSeq_Cinematic();

private:
	cFade* m_pFade;

private:
	D3DXVECTOR2 m_FilmPos;
	FLOAT m_FilmTargetXPos;
	INT m_FilmCount;

	BOOL m_bExit;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};