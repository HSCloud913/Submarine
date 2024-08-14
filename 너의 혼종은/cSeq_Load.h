#pragma once
#include "cSequence.h"

class cResourceLoad;

class cFade;

class cTexture;
class cTexList;
class c2DAni;

class cSeq_Load :public cSequence
{
public:
	cSeq_Load();
	~cSeq_Load();

private:
	cResourceLoad* m_pLoad;
	cFade* m_pFade;

private:
	cTexture* m_pBackGround;
	cTexList* m_pTexList;
	c2DAni* m_pAni;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};