#include "Util.h"

#include "cResourceLoad.h"

#include "cFade.h"

#include "cTexture.h"
#include "cTexList.h"
#include "c2DAni.h"

#include "cSeq_Intro.h"
#include "cSeq_Load.h"



cSeq_Load::cSeq_Load()
	: m_pFade(nullptr)
{
}

cSeq_Load::~cSeq_Load()
{
	if (m_pAni != nullptr)
	{
		SAFE_DELETE(m_pAni);
	}

	if (m_pTexList != nullptr)
	{
		SAFE_DELETE(m_pTexList);
	}

	if (m_pBackGround != nullptr)
	{
		SAFE_DELETE(m_pBackGround);
	}
}



INT cSeq_Load::OnInit()
{
	m_pLoad = new cResourceLoad;
	m_pLoad->Init();

	m_pBackGround = new cTexture;
	m_pBackGround->Create(L"Resource/Img/Load/BackGround.png");

	m_pTexList = new cTexList();
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00001.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00002.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00003.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00004.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00005.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00006.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00007.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00008.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00009.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00010.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00011.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00012.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00013.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00014.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00015.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00016.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00017.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00018.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00019.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00020.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00021.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00022.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00023.png");
	m_pTexList->AddTexture(L"Resource/Img/Load/Frame/00024.png");
	
	m_pAni = new c2DAni(m_pTexList, 24, 48);
	m_pAni->SetPos(&cSystem::fCenterPos);
	m_pAni->Play();

	return 0;
}

INT cSeq_Load::OnCleanUp()
{
	return 0;
}


cSequence* cSeq_Load::OnUpdate()
{
	cSequence* pNextSeq = this;

	m_pAni->Update();

	if (m_pLoad != nullptr)
	{
		if (m_pLoad->IsEnd())
		{
			SAFE_DELETE(m_pLoad);

			m_pFade = new cFade(Fade::Out, 5.f);
		}

		else
		{
			m_pLoad->Loading();
		}
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Update();

		if (m_pFade->IsEnd())
		{
			SAFE_DELETE(m_pFade);

			return new cSeq_Intro;
		}
	}

	return pNextSeq;
}

INT cSeq_Load::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(m_pBackGround, cSystem::fCenterPos);
	m_pAni->Render();

	if (m_pLoad != nullptr)
	{
		m_pLoad->Render();
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Render();
	}

	return 0;
}