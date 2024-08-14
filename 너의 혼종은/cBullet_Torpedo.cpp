#include "Util.h"

#include "c2DAniList.h"

#include "cBullet_Torpedo.h"



cBullet_Torpedo::cBullet_Torpedo(INT upgrade)
	: cBullet(1.f)
{
	m_CollRect = { 25 - 128, 119 - 128, 250 - 128, 138 - 128 };

	this->Init(Team::Player, Bullet::Torpedo, 2 + upgrade);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_Torpedo], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_Torpedo::~cBullet_Torpedo()
{
}



INT cBullet_Torpedo::OnUpdateBullet(cData* pData)
{ // °¡¼Óµµ
	D3DXVECTOR2 Direction(0.f, 0.f);
	Util::GetPosition(&Direction, m_Angle);
	Direction *= 1.2f;

	m_Speed += VFR(Direction);

	return 0;
}

INT cBullet_Torpedo::OnRenderBullet()
{
	return 0;
}