#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Ray.h"



cBullet_Ray::cBullet_Ray()
	: cBullet(8.f)
{
	m_CollRect = { 48 - 64, 14 - 64, 86 - 64, 113 - 64 };

	this->Init(Team::Enemy, Bullet::Ray, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Ray], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Ray::~cBullet_Ray()
{
}



INT cBullet_Ray::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Ray::OnRenderBullet()
{
	return 0;
}