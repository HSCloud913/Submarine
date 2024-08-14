#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Y_Seahorse.h"



cBullet_Y_Seahorse::cBullet_Y_Seahorse()
	: cBullet(12.f)
{
	m_CollRect = { 50 - 64, 25 - 64, 90 - 64, 102 - 64 };

	this->Init(Team::Enemy, Bullet::Y_Seahorse, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Y_Seahorse], 12, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Y_Seahorse::~cBullet_Y_Seahorse()
{
}



INT cBullet_Y_Seahorse::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Y_Seahorse::OnRenderBullet()
{
	return 0;
}