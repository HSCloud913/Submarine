#include "Util.h"

#include "cGameData.h"

#include "c2DAniList.h"

#include "cUnit_Player.h"

#include "cBullet_GuidedTorpedo.h"



cBullet_GuidedTorpedo::cBullet_GuidedTorpedo(INT upgrade)
	: cBullet(12.f)
{
	m_CollRect = { 50 - 128, 113 - 128, 217 - 128, 143 - 128 };

	this->Init(Team::Player, Bullet::GuidedTorpedo, 5);

	m_pAniList->AddAni(cSystem::Resource.m_pTexList[TexList_Bullet_GuidedTorpedo], 24, 24);
	m_pAniList->SetCurrAniNum(0);
	m_pAniList->Play();
}

cBullet_GuidedTorpedo::~cBullet_GuidedTorpedo()
{
}



INT cBullet_GuidedTorpedo::OnUpdateBullet(cData* pData)
{
	cGameData* pGameData = dynamic_cast<cGameData*>(pData);

	if (pGameData != nullptr)
	{
		if (pGameData->GetPlayer() != nullptr)
		{
			if (pGameData->GetPlayer()->GetEnemyPos() != nullptr)
			{
				D3DXVECTOR2 Target = *pGameData->GetPlayer()->GetEnemyPos();
				D3DXVECTOR2 Point;

				Point.x = Target.x - m_Pos.x;
				Point.y = Target.y - m_Pos.y;

				m_Angle = D3DXToDegree(atan2f(Point.y, Point.x)) + 90.f;

				D3DXVECTOR2 vcSpeed;
				FLOAT d = sqrt(pow(Point.x, 2) + pow(Point.y, 2));

				vcSpeed.x = Point.x / d * m_MoveSpeed;
				vcSpeed.y = Point.y / d * m_MoveSpeed;

				m_Speed = vcSpeed;
			}
		}
	}

	return 0;
}

INT cBullet_GuidedTorpedo::OnRenderBullet()
{
	return 0;
}