#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Shark.h"



cBullet_Shark::cBullet_Shark()
	: cBullet(10.f)
{
	m_CollRect = { 26 - 64, 19 - 64, 122 - 64, 107 - 64 };

	this->Init(Team::Enemy, Bullet::Shark, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Shark], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Shark::~cBullet_Shark()
{
}



INT cBullet_Shark::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Shark::OnRenderBullet()
{
	return 0;
}