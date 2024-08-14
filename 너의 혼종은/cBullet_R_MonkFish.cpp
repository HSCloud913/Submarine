#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_R_MonkFish.h"



cBullet_R_MonkFish::cBullet_R_MonkFish()
	: cBullet(11.f)
{
	m_CollRect = { 32 - 64, 26 - 64, 102 - 64, 100 - 64 };

	this->Init(Team::Enemy, Bullet::R_MonkFish, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_R_MonkFish], 12, 36);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_R_MonkFish::~cBullet_R_MonkFish()
{
}



INT cBullet_R_MonkFish::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_R_MonkFish::OnRenderBullet()
{
	return 0;
}