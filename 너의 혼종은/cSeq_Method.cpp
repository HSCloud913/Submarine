#include "Util.h"

#include "cSeq_MainMenu.h"
#include "cSeq_Method.h"



cSeq_Method::cSeq_Method()
{
}

cSeq_Method::~cSeq_Method()
{
}



INT cSeq_Method::OnInit()
{
	return 0;
}

INT cSeq_Method::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Method::OnUpdate()
{
	cSequence* pNextSeq = this;

	if (cSystem::Input.KeyDown(VK_ESCAPE))
	{
		return new cSeq_MainMenu;
	}

	return pNextSeq;
}

INT cSeq_Method::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Method]->GetTexture(0), cSystem::fCenterPos);

	return 0;
}