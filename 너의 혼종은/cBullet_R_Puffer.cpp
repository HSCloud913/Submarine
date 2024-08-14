#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_R_Puffer.h"



cBullet_R_Puffer::cBullet_R_Puffer()
	: cBullet(12.f)
{
	m_CollRect = { 43 - 64, 43 - 64, 87 - 64, 87 - 64 };

	this->Init(Team::Enemy, Bullet::R_Puffer, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_R_Puffer], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_R_Puffer::~cBullet_R_Puffer()
{
}



INT cBullet_R_Puffer::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_R_Puffer::OnRenderBullet()
{
	return 0;
}