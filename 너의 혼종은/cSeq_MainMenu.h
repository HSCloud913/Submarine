#pragma once
#include <vector>
#include "c2DCoord.h"
#include "cSequence.h"

class cFade;

class cButton;

class cSeq_MainMenu :public cSequence
{
public:
	cSeq_MainMenu();
	~cSeq_MainMenu();

private:
	cFade* m_pFade;

private:
	class cWaterDrop :public c2DCoord
	{
	public:
		cWaterDrop(D3DXVECTOR2 pos, FLOAT moveSpeed)
			: m_MoveSpeed(moveSpeed)
		{
			m_Pos = pos;
		}
		~cWaterDrop() {}

	private:
		FLOAT m_MoveSpeed;

	public:
		INT Update()
		{
			m_Pos.y -= VFR(m_MoveSpeed);

			return 0;
		}

		INT Render()
		{
			cD3DApp::Sprite.SetColor(D3DCOLOR_ARGB(127, 255, 255, 255));
			cD3DApp::Sprite.RenderTextureCenter(
				cSystem::Resource.m_pTexList[TexList_MainMenu]->GetTexture(6)
				, m_Pos, m_Scale);

			return 0;
		}
	};

	std::vector<cWaterDrop> m_WaterDropList;

private:
	cButton* m_pIntroduce;
	cButton* m_pMethod;
	cButton* m_pStart;
	cButton* m_pExit;
	cButton* m_pRanking;

	FLOAT m_ButtonPos;

private:
	BOOL m_bClick;

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;

private:
	INT UpdateButton();
};