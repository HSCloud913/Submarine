#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_P_Cme.h"



cBullet_P_Cme::cBullet_P_Cme()
	: cBullet(12.f)
{
	m_CollRect = { 32 - 64, 32 - 64, 98 - 64, 98 - 64 };

	this->Init(Team::Enemy, Bullet::P_Cme, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_P_Cme], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_P_Cme::~cBullet_P_Cme()
{
}



INT cBullet_P_Cme::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_P_Cme::OnRenderBullet()
{
	return 0;
}