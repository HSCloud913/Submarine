#include "Util.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_R_Puffer.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_R_Puffer.h"



cUnit_R_Puffer::cUnit_R_Puffer()
	: cUnit(4.f)

	, m_pUpTimer(new cTimer(0, 1))
	, m_pDownTimer(nullptr)
{
	m_pUpTimer->Play();

	m_CollRect = { 68 - 128, 78 - 128, 192 - 128, 200 - 128 };

	this->Init(AI::R_Puffer, Team::Enemy, Unit::R_Puffer, 5, 400);
	
	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Puffer_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_R_Puffer_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_R_Puffer);
	m_CurrWeaponNum = 0;
}

cUnit_R_Puffer::~cUnit_R_Puffer()
{
}



INT cUnit_R_Puffer::OnUpdateUnit(cData* pData)
{
	if (m_pUpTimer != nullptr)
	{
		m_pUpTimer->Update();

		if (m_pUpTimer->IsEnd())
		{
			SAFE_DELETE(m_pUpTimer);

			m_pDownTimer = new cTimer(0, 1);
			m_pDownTimer->Play();
		}

		m_Pos.y -= VFR(4.f);
	}

	if (m_pDownTimer != nullptr)
	{
		m_pDownTimer->Update();

		if (m_pDownTimer->IsEnd())
		{
			SAFE_DELETE(m_pDownTimer);

			m_pUpTimer = new cTimer(0, 1);
			m_pUpTimer->Play();
		}

		m_Pos.y += VFR(4.f);
	}

	return 0;
}

INT cUnit_R_Puffer::OnRenderUnit()
{
	return 0;
}



INT cUnit_R_Puffer::OnItemDrop(cData* pData)
{
	if (rand() % 6 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::TripleTorpedo, m_Pos));
	}

	else if (rand() % 10 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Upgrade, m_Pos));
	}

	return 0;
}