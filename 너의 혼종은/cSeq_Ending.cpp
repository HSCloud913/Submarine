#include "Util.h"

#include "cFade.h"

#include "cSeq_Initial.h"
#include "cSeq_MainMenu.h"
#include "cSeq_Ending.h"



cSeq_Ending::cSeq_Ending(BOOL bClear, INT score)
	: m_Score(score)
	, m_bClear(bClear)

	, m_pFade(new cFade(Fade::In, 3.f))
	, m_bReturn(FALSE)
{
}

cSeq_Ending::~cSeq_Ending()
{
}



INT cSeq_Ending::OnInit()
{
	return 0;
}

INT cSeq_Ending::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Ending::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (m_pFade != nullptr)
	{
		m_pFade->Update();

		if (m_pFade->IsEnd())
		{
			SAFE_DELETE(m_pFade);
		
			if (m_bReturn)
			{
				if (m_bClear)
				{
					return new cSeq_Initial(m_Score);
				}

				else
				{
					return new cSeq_MainMenu;
				}
			}
		}
	}

	else
	{
		if (cSystem::Input.KeyDown(VK_SPACE))
		{
			m_pFade = new cFade(Fade::Out, 3.f);
			m_bReturn = TRUE;
		}
	}

	return pNextSeq;
}

INT cSeq_Ending::OnRender()
{
	if (m_bClear)
	{
		cD3DApp::Sprite.RenderTextureCenter(
			cSystem::Resource.m_pTexList[TexList_Ending]->GetTexture(0), cSystem::fCenterPos);
	}

	else
	{
		cD3DApp::Sprite.RenderTextureCenter(
			cSystem::Resource.m_pTexList[TexList_Ending]->GetTexture(1), cSystem::fCenterPos);
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}