#include "Util.h"

#include "cFade.h"

#include "cSeq_Cinematic.h"
#include "cSeq_Intro.h"



cSeq_Intro::cSeq_Intro()
{
}

cSeq_Intro::~cSeq_Intro()
{
}



INT cSeq_Intro::OnInit()
{
	m_pFade = new cFade(Fade::InOut, 1.5f);

	return 0;
}

INT cSeq_Intro::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Intro::OnUpdate()
{
	cSequence* pNextSeq = this;

	m_pFade->Update();

	if (m_pFade->IsEnd())
	{
		return new cSeq_Cinematic;
	}

	return pNextSeq;
}

INT cSeq_Intro::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Intro]->GetTexture(0), cSystem::fCenterPos);

	m_pFade->Render();

	return 0;
}