#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Y_Puffer.h"



cBullet_Y_Puffer::cBullet_Y_Puffer()
	: cBullet(12.f)
{
	m_CollRect = { 43 - 64, 43 - 64, 87 - 64, 87 - 64 };

	this->Init(Team::Enemy, Bullet::Y_Puffer, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Y_Puffer], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Y_Puffer::~cBullet_Y_Puffer()
{
}



INT cBullet_Y_Puffer::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Y_Puffer::OnRenderBullet()
{
	return 0;
}