#include "Util.h"

#include "c2DAniList.h"

#include "cWeapon.h"
#include "cWeapon_AddOn.h"

#include "cUnit_AddOn.h"



cUnit_AddOn::cUnit_AddOn()
	: cUnit(0.f)
{
	m_Scale = D3DXVECTOR2(0.75f, 0.75f);

	m_CollRect = { 0, 0, 0, 0 };

	this->Init(AI::AddOn, Team::Assist, Unit::AddOn, 1, 0);

	/* AniList */
	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_AddOn_Move], 12, 60);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();

	/* WeaponList */
	m_pWeaponList.push_back(new cWeapon_AddOn);
	m_CurrWeaponNum = 0;
}

cUnit_AddOn::~cUnit_AddOn()
{
}



INT cUnit_AddOn::OnUpdateUnit(cData* pData)
{
	return 0;
}

INT cUnit_AddOn::OnRenderUnit()
{
	return 0;
}



INT cUnit_AddOn::OnItemDrop(cData* pData)
{
	return 0;
}