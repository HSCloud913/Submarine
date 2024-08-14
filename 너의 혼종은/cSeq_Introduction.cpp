#include "Util.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Introduction.h"



cSeq_Introduction::cSeq_Introduction()
{
}

cSeq_Introduction::~cSeq_Introduction()
{
}



INT cSeq_Introduction::OnInit()
{
	return 0;
}

INT cSeq_Introduction::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Introduction::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (cSystem::Input.KeyDown(VK_ESCAPE))
	{
		return new cSeq_MainMenu;
	}

	return pNextSeq;
}

INT cSeq_Introduction::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Introduction]->GetTexture(0), cSystem::fCenterPos);

	return 0;
}