#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_AddOn.h"



cBullet_AddOn::cBullet_AddOn()
	: cBullet(12.f)
{
	m_CollRect = { 16 - 32, 16 - 32, 48 - 32, 48 - 32};

	this->Init(Team::Player, Bullet::AddOn, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_AddOn], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_AddOn::~cBullet_AddOn()
{
}



INT cBullet_AddOn::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_AddOn::OnRenderBullet()
{
	return 0;
}