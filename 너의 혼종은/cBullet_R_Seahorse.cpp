#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_R_Seahorse.h"



cBullet_R_Seahorse::cBullet_R_Seahorse()
	: cBullet(12.f)
{
	m_CollRect = { 50 - 64, 25 - 64, 90 - 64, 102 - 64 };

	this->Init(Team::Enemy, Bullet::R_Puffer, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_R_Seahorse], 12, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_R_Seahorse::~cBullet_R_Seahorse()
{
}



INT cBullet_R_Seahorse::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_R_Seahorse::OnRenderBullet()
{
	return 0;
}