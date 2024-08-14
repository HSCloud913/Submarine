#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Whale.h"



cBullet_Whale::cBullet_Whale()
	: cBullet(20.f)
{
	m_CollRect = { 29 - 64, 29 - 64, 100 - 64, 98 - 64 };

	this->Init(Team::Enemy, Bullet::Whale, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Whale], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Whale::~cBullet_Whale()
{
}



INT cBullet_Whale::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Whale::OnRenderBullet()
{
	return 0;
}