#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Nuclear.h"



cBullet_Nuclear::cBullet_Nuclear()
	: cBullet(10.f)
{
	m_CollRect = { 44 - 128, 96 - 128, 235 - 128, 136 - 128 };

	this->Init(Team::Player, Bullet::Nuclear, 10);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Nuclear], 48, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Nuclear::~cBullet_Nuclear()
{
}



INT cBullet_Nuclear::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Nuclear::OnRenderBullet()
{
	return 0;
}