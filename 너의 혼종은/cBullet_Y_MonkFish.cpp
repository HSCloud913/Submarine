#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Y_MonkFish.h"



cBullet_Y_MonkFish::cBullet_Y_MonkFish()
	: cBullet(9.f)
{
	m_CollRect = { 32 - 64, 26 - 64, 102 - 64, 100 - 64 };

	this->Init(Team::Enemy, Bullet::Y_MonkFish, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Y_MonkFish], 12, 36);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Y_MonkFish::~cBullet_Y_MonkFish()
{
}



INT cBullet_Y_MonkFish::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Y_MonkFish::OnRenderBullet()
{
	return 0;
}