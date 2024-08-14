#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Kraken.h"



cBullet_Kraken::cBullet_Kraken()
	: cBullet(12.f)
{
	m_CollRect = { 16 - 64, 16 - 64, 114 - 64, 114 - 64 };

	this->Init(Team::Enemy, Bullet::Kraken, 1);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Kraken], 1, 10000);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Kraken::~cBullet_Kraken()
{
}



INT cBullet_Kraken::OnUpdateBullet(cData* pData)
{
	return 0;
}

INT cBullet_Kraken::OnRenderBullet()
{
	return 0;
}