#pragma once
#include <fstream>
#include "cSequence.h"

class cFont;

class cSeq_Ranking :public cSequence
{
public:
	cSeq_Ranking();
	~cSeq_Ranking();

private:
	cFont* m_pFont;

private:
	std::ifstream m_RFile;

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