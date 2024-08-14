#include "Util.h"

#include "cFont.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Ranking.h"



cSeq_Ranking::cSeq_Ranking()
	: m_pFont(new cFont)
{
	m_pFont->Create(L"Calibri", 100, 200);
}

cSeq_Ranking::~cSeq_Ranking()
{
}



INT cSeq_Ranking::OnInit()
{
	m_RFile.open(L"Result/Result.txt");

	if (m_RFile.is_open())
	{
		while (!m_RFile.eof())
		{
			UINT Idx = m_InfoList.size();
			m_InfoList.emplace_back();

			m_RFile >> m_InfoList[Idx].Initial >> m_InfoList[Idx].Score;
		}
	}

	for (UINT i = 0; i < m_InfoList.size(); i++)
	{
		for (UINT j = i + 1; j < m_InfoList.size(); j++)
		{
			if (m_InfoList[i].Score > m_InfoList[j].Score)
			{
				Info Temp;
				lstrcpyA(Temp.Initial, m_InfoList[i].Initial);
				Temp.Score = m_InfoList[i].Score;

				lstrcpyA(m_InfoList[i].Initial, m_InfoList[j].Initial);
				m_InfoList[i].Score = m_InfoList[j].Score;

				lstrcpyA(m_InfoList[j].Initial, Temp.Initial);
				m_InfoList[j].Score = Temp.Score;
			}
		}
	}

	return 0;
}

INT cSeq_Ranking::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Ranking::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (cSystem::Input.KeyDown(VK_ESCAPE))
	{
		return new cSeq_MainMenu;
	}

	return pNextSeq;
}

INT cSeq_Ranking::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Ranking]->GetTexture(0), cSystem::fCenterPos);

	for (UINT i = m_InfoList.size() - 1; i > 0; i--)
	{
		if (i > m_InfoList.size() - 4)
		{
			CHAR Initial[256];
			WCHAR wInitial[256];

			memset(Initial, '\0', 255);
			wmemset(wInitial, L'\0', 255);

			lstrcpyA(Initial, m_InfoList[i].Initial);

			INT InitialLen = strlen(Initial);
			INT wInitialLen = MultiByteToWideChar(CP_ACP, 0, Initial, InitialLen, nullptr, 0);
			MultiByteToWideChar(CP_ACP, 0, Initial, InitialLen, wInitial, wInitialLen);

			m_pFont->ShowText(wInitial, 550, 300 + (m_InfoList.size() - i - 1) * 260
				, D3DCOLOR_ARGB(255, 0, 0, 0));


			CHAR Score[256];
			WCHAR wScore[256];

			memset(Score, '\0', 255);
			wmemset(wScore, L'\0', 255);

			sprintf_s(Score, 255, "%d", m_InfoList[i].Score);

			INT ScoreLen = strlen(Score);
			INT wScoreLen = MultiByteToWideChar(CP_ACP, 0, Score, ScoreLen, nullptr, 0);
			MultiByteToWideChar(CP_ACP, 0, Score, ScoreLen, wScore, wScoreLen);

			m_pFont->ShowText(wScore, 1050, 300 + (m_InfoList.size() - i - 1) * 260
				, D3DCOLOR_ARGB(255, 0, 0, 0));
		}
	}

	return 0;
}