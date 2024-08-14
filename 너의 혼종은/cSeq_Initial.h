#pragma once
#include <fstream>
#include <vector>
#include "cSequence.h"

class cFont;

class cFade;

class cSeq_Initial :public cSequence
{
public:
	cSeq_Initial(INT score);
	~cSeq_Initial();

private:
	cFont* m_pFont;
	cFont* m_pScoreFont;

private:
	cFade* m_pFade;

private:
	INT m_Score;

private:
	CHAR m_Word[3];
	INT m_Input;
	INT m_Count;

private:
	std::ifstream m_RFile;
	std::ofstream m_WFile;

private:
	typedef struct _Info
	{
		CHAR Initial[5];
		INT Score;
	}Info;

private:
	std::vector<Info> m_InfoList;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};