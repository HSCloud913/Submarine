#include "Util.h"

#include "cTimer.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_Y_Puffer.h"

#include "cData.h"
#include "ItemFactory.h"

#include "cUnit_Y_Puffer.h"



cUnit_Y_Puffer::cUnit_Y_Puffer()
	: cUnit(3.f)

	, m_pUpTimer(new cTimer(0, 1))
	, m_pDownTimer(nullptr)
{
	m_pUpTimer->Play();

	m_CollRect = { 68 - 128, 78 - 128, 192 - 128, 200 - 128 };

	this->Init(AI::Y_Puffer, Team::Enemy, Unit::Y_Puffer, 1, 300);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_Puffer_Move], 24, 48);
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Y_Puffer_Attack], 36, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_Y_Puffer);
	m_CurrWeaponNum = 0;
}

cUnit_Y_Puffer::~cUnit_Y_Puffer()
{
}



INT cUnit_Y_Puffer::OnUpdateUnit(cData* pData)
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

		m_Pos.y -= VFR(3.f);
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

		m_Pos.y += VFR(3.f);
	}

	return 0;
}

INT cUnit_Y_Puffer::OnRenderUnit()
{
	return 0;
}



INT cUnit_Y_Puffer::OnItemDrop(cData* pData)
{
	if (rand() % 4 == 0)
	{
		pData->AddObject(ItemFactory::Create(Item::Speed, m_Pos));
	}

	return 0;
}