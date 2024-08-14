#include "Util.h"

#include "cSound.h"

#include "cEffectList.h"

#include "cUnit_Player.h"
#include "cUnit.h"
#include "cBullet.h"
#include "cItem.h"
#include "cMapObject.h"
#include "cTopography.h"

#include "cTimer.h"

#include "UnitFactory.h"

#include "cGameData.h"



cGameData::cGameData(INT stageNum)
	: cData(stageNum)

	, m_pEffectList(new cEffectList)

	, m_pPlayer(nullptr)

	, m_bAddOn1(FALSE)
	, m_bAddOn2(FALSE)
{
	m_pUnitList.clear();
	m_pBulletList.clear();
	m_pItemList.clear();
	m_pMapObjList.clear();
	m_pTopographyList.clear();
}

cGameData::~cGameData()
{
}



INT cGameData::OnUpdate()
{
	D3DXVECTOR2 EnemyPos(3000.f, cSystem::fCenterPos.y);

	if (m_pPlayer != nullptr)
	{
		if (!m_bAddOn1)
		{
			if (m_pPlayer->GetScore() / 15000 >= 1)
			{
				if (m_pPlayer->AddOn(1))
				{
					AddObject(UnitFactory::Create(Unit::AddOn, *m_pPlayer->Pos()));
					m_bAddOn1 = TRUE;
				}
			}
		}

		if (!m_bAddOn2)
		{
			if (m_pPlayer->GetScore() / 30000 >= 1)
			{
				if (m_pPlayer->AddOn(1))
				{
					AddObject(UnitFactory::Create(Unit::AddOn, *m_pPlayer->Pos()));
					m_bAddOn2 = TRUE;
				}
			}
		}

		for (UINT m = 0; m < m_pMapObjList.size(); m++)
		{
			cMapObject* const pMapObj = m_pMapObjList[m];

			if (pMapObj == nullptr)
			{
				continue;
			}

			if (!m_pPlayer->IsImmortal() || !m_pPlayer->IsSystemImmortal())
			{
				if (IntersectRect(&RECT(), &m_pPlayer->GetCollRect(), &pMapObj->GetCollRect()))
				{ // �浹 �˻�
					if (pMapObj->GetMapObjType() == MapObject::Seaweed)
					{
						m_pPlayer->AddMoveSpeed(-1.f);
					}

					else
					{
						m_pPlayer->SetImmortal();
						m_pPlayer->AddHp(-1);
					}

					m_pEffectList->AddEffect(cSystem::Resource.m_pTexList[TexList_Effect_Bubble]
						, 24, 36, *pMapObj->Pos());

					DeleteObject(pMapObj);
					m--;
					continue;
				}
			}
			
			for (UINT b = 0; b < m_pBulletList.size(); b++)
			{
				cBullet* const pBullet = m_pBulletList[b];

				if (pBullet == nullptr)
				{
					continue;
				}

				if (pBullet->GetTeamType() == Team::Player)
				{
					if (IntersectRect(&RECT(), &pMapObj->GetCollRect(), &pBullet->GetCollRect()))
					{ // �浹 �˻�
						pMapObj->AddHp(-1);

						m_pEffectList->AddEffect(cSystem::Resource.m_pTexList[TexList_Effect_Boom]
							, 12, 36, *pBullet->Pos());

						DeleteObject(pBullet);
						b--;
						continue;
					}
				}
			}

			if (pMapObj->GetHp() <= 0)
			{
				m_pPlayer->AddScore(300);

				DeleteObject(pMapObj);
				m--;
				continue;
			}
		}

		/* ������ ȹ�� */
		for (UINT i = 0; i < m_pItemList.size(); i++)
		{
			cItem* const pItem = m_pItemList[i];

			if (pItem == nullptr)
			{
				continue;
			}

			if (IntersectRect(&RECT(), &m_pPlayer->GetCollRect(), &pItem->GetCollRect()))
			{ // �浹 �˻�
				pItem->Use(this, m_pPlayer); // ������ ���� ���ÿ� ���ο��� ������ �ö�

				m_pEffectList->AddEffect(cSystem::Resource.m_pTexList[TexList_Effect_Item]
					, 12, 36, *m_pPlayer->Pos());

				DeleteObject(pItem);
				i--;
				continue;
			}
		}

		for (UINT t = 0; t < m_pTopographyList.size(); t++)
		{
			cTopography* const pTopography = m_pTopographyList[t];

			if (pTopography == nullptr)
			{
				continue;
			}

			for (UINT i = 0; i < pTopography->GetSize(); i++)
			{
				RECT Rect;

				if (IntersectRect(&Rect, &m_pPlayer->GetCollRect(), &pTopography->GetCollRect(i)))
				{ // �浹 �˻�
					if (!m_pPlayer->IsImmortal() && !m_pPlayer->IsSystemImmortal())
					{
						m_pPlayer->SetImmortal(); // �÷��̾� �Ͻù���
						m_pPlayer->SetCurrWeaponNum(m_pPlayer->GetCurrWeaponNum() - 1);
						m_pPlayer->AddHp(-1);
					}

					INT Width = Rect.right - Rect.left;
					INT Height = Rect.bottom - Rect.top;

					m_pPlayer->AddXPos(-Width);
					m_pPlayer->AddYPos(-Height);
				}
			}
		}

		for (UINT u = 0; u < m_pUnitList.size(); u++)
		{
			cUnit* const pUnit = m_pUnitList[u];

			if (pUnit == nullptr)
			{
				continue;
			}

			/* �÷��̾�� ���� �浹 */
			if (m_pPlayer != nullptr)
			{
				if (m_pPlayer->GetTeamType() != pUnit->GetTeamType() &&
					pUnit->GetTeamType() != Team::Assist)
				{ // �� �˻�
					if (IntersectRect(&RECT(), &m_pPlayer->GetCollRect(), &pUnit->GetCollRect()))
					{ // �浹 �˻�
						if (!m_pPlayer->IsImmortal() && !m_pPlayer->IsSystemImmortal())
						{ // �÷��̾� ���� �˻�

							m_pPlayer->SetImmortal(); // �÷��̾� �Ͻù���
							m_pPlayer->SetCurrWeaponNum(m_pPlayer->GetCurrWeaponNum() - 1);
							// �÷��̾�� �� ��� 1�� ���� ����
							m_pPlayer->AddHp(-1);
							pUnit->AddHp(-1);
						}

						m_pPlayer->AddXPos(-m_pPlayer->Speed()->x);
						pUnit->AddXPos(-pUnit->Speed()->x);
					}
				}
			}

			for (UINT b = 0; b < m_pBulletList.size(); b++)
			{
				cBullet* const pBullet = m_pBulletList[b];

				if (pBullet == nullptr)
				{
					continue;
				}

				if (pBullet->GetBulletType() == Bullet::GuidedTorpedo)
				{
					for (UINT b2 = 0; b2 < m_pBulletList.size(); b2++)
					{
						cBullet* const pBullet2 = m_pBulletList[b2];

						if (pBullet2 == nullptr)
						{
							continue;
						}

						if (pBullet2->GetTeamType() == Team::Enemy)
						{
							if (IntersectRect(&RECT(), &pBullet->GetCollRect()
								, &pBullet2->GetCollRect()))
							{ // �浹 �˻�
								m_pEffectList->AddEffect(
									cSystem::Resource.m_pTexList[TexList_Effect_Bubble]
									, 24, 36, *pBullet->Pos());

								DeleteObject(pBullet2); // ź����
								b2--;
								b--;
								continue;
							}
						}
					}
				}

				/* ���ְ� �Ѿ� �浹 */
				if (!pUnit->IsImmortal() && !pUnit->IsSystemImmortal())
				{ // ������ �ƴҶ�
					if (pUnit->GetTeamType() != pBullet->GetTeamType())
					{ // �� �˻�
						if (IntersectRect(&RECT(), &pUnit->GetCollRect()
							, &pBullet->GetCollRect()))
						{ // �浹 �˻�
							if (pUnit->GetTeamType() == Team::Player)
							{ // �÷��̾��
								pUnit->SetImmortal(); // �÷��̾� �Ͻù���
								m_pPlayer->SetCurrWeaponNum(m_pPlayer->GetCurrWeaponNum() - 1);
							}

							if (pBullet->GetBulletType() == Bullet::Nuclear)
							{
								for (UINT u2 = 0; u2 < m_pUnitList.size(); u2++)
								{
									cUnit* const pUnit2 = m_pUnitList[u2];

									if (pUnit2 == nullptr)
									{
										continue;
									}

									if (pUnit2->GetTeamType() == Team::Enemy)
									{
										if (pUnit2->Pos()->x >= pBullet->Pos()->x - 500 &&
											pUnit2->Pos()->x <= pBullet->Pos()->x + 500 &&
											pUnit2->Pos()->y >= pBullet->Pos()->y - 500 &&
											pUnit2->Pos()->y <= pBullet->Pos()->y + 500)
										{
											pBullet->Hit(pUnit2); // �ǰ�
										}
									}
								}

								m_pEffectList->AddEffect(
									cSystem::Resource.m_pTexList[TexList_Effect_Nuclear] // ������
									, 24, 36, *pBullet->Pos());
							}

							else
							{
								pBullet->Hit(pUnit); // �ǰ�
							}

							if (pBullet->GetBulletType() == Bullet::Torpedo ||
								pBullet->GetBulletType() == Bullet::GuidedTorpedo)
							{
								m_pEffectList->AddEffect(
									cSystem::Resource.m_pTexList[TexList_Effect_Boom]
									, 12, 36, *pBullet->Pos());
							}

							else
							{
								m_pEffectList->AddEffect(
									cSystem::Resource.m_pTexList[TexList_Effect_Bubble]
									, 24, 36, *pBullet->Pos());
							}

							DeleteObject(pBullet); // ź����
							b--;
							continue;
						}
					}
				}
			}

			// �� ��ġ ����

			if (pUnit->GetTeamType() == Team::Enemy)
			{
				if (m_pPlayer != nullptr)
				{
					pUnit->SetEnemyPos(*m_pPlayer->Pos());
				}

				if (EnemyPos.x > pUnit->Pos()->x && pUnit->Pos()->x > 0.f)
				{
					EnemyPos = *pUnit->Pos();
				}
			}

			/* ���� ���� */
			if (pUnit->GetHp() <= 0)
			{
				pUnit->ItemDrop(this);

				if (pUnit->GetTeamType() == Team::Player)
				{
					SAFE_DELETE(m_pStageTimer);

					m_pEffectList->AddEffect(
						cSystem::Resource.m_pTexList[TexList_Effect_Death]
						, 24, 36, *m_pPlayer->Pos());

					m_GameState = Fail;
				}

				else
				{
					m_pPlayer->AddScore(pUnit->GetScore()); // ���ھ� �߰�

					if (pUnit->GetUnitType() == Unit::Ray ||
						pUnit->GetUnitType() == Unit::Shark ||
						pUnit->GetUnitType() == Unit::Whale ||
						pUnit->GetUnitType() == Unit::Kraken)
					{
						m_pPlayer->AddHp(2);

						if (m_pStageTimer != nullptr)
						{
							m_pStageTimer->Play();
						}

						SAFE_DELETE(m_pTopographyTimer);
						m_pTopographyTimer = new cTimer(0, 6 - m_StageNum);
						m_pTopographyTimer->Play();

						SAFE_DELETE(m_pObjTimer);
						m_pObjTimer = new cTimer(0, 4 - m_StageNum);
						m_pObjTimer->Play();

						for (UINT i = 0; i < 4; i++)
						{
							SAFE_DELETE(m_pSpawn[i]);
							m_pSpawn[i] = new cTimer(0, i + 3);
							m_pSpawn[i]->Play();
						}

						// Death Effect (Ư��)
					}

					else
					{
						m_pEffectList->AddEffect(
							cSystem::Resource.m_pTexList[TexList_Effect_Death]
							, 24, 36, *pUnit->Pos() + D3DXVECTOR2(0.f, -50.f));
					}

					if (pUnit->GetUnitType() == Unit::Kraken ||
						pUnit->GetUnitType() == Unit::Whale)
					{
						m_GameState = Clear;
					}
				}

				cSystem::Resource.m_pSoundList[0]->GetSound(2)->Play(FALSE);

				DeleteObject(pUnit);
				u--;
				continue;
			}
		}

		if (m_pPlayer != nullptr)
		{
			m_pPlayer->SetEnemyPos(EnemyPos);
		}
	}

	m_pEffectList->Update();

	return 0;
}

INT cGameData::OnRender()
{
	for (UINT i = 0; i < m_pTopographyList.size(); i++)
	{
		if (m_pTopographyList[i] == nullptr)
		{
			continue;
		}

		m_pTopographyList[i]->Render();
	}

	for (UINT i = 0; i < m_pItemList.size(); i++)
	{
		if (m_pItemList[i] == nullptr)
		{
			continue;
		}

		m_pItemList[i]->Render();
	}

	for (UINT i = 0; i < m_pMapObjList.size(); i++)
	{
		if (m_pMapObjList[i] == nullptr)
		{
			continue;
		}

		m_pMapObjList[i]->Render();
	}

	for (UINT i = 0; i < m_pUnitList.size(); i++)
	{
		if (m_pUnitList[i] == nullptr)
		{
			continue;
		}

		if (m_pUnitList[i] != m_pPlayer)
		{
			m_pUnitList[i]->Render();
		}
	}

	for (UINT i = 0; i < m_pBulletList.size(); i++)
	{
		if (m_pBulletList[i] == nullptr)
		{
			continue;
		}

		m_pBulletList[i]->Render();
	}

	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Render();
	}

	m_pEffectList->Render();

	return 0;
}



INT cGameData::OnAddObject(cGameObject* pGameObject)
{
	m_pUnitList.emplace_back(dynamic_cast<cUnit*>(pGameObject));
	m_pBulletList.emplace_back(dynamic_cast<cBullet*>(pGameObject));
	m_pItemList.emplace_back(dynamic_cast<cItem*>(pGameObject));
	m_pMapObjList.emplace_back(dynamic_cast<cMapObject*>(pGameObject));
	m_pTopographyList.emplace_back(dynamic_cast<cTopography*>(pGameObject));

	cUnit_Player* pPlayer = dynamic_cast<cUnit_Player*>(pGameObject);

	if (pPlayer != nullptr)
	{
		m_pPlayer = pPlayer;
	}

	return 0;
}

INT cGameData::OnDeleteObject(UINT Idx)
{
	m_pUnitList.erase(m_pUnitList.begin() + Idx);
	m_pBulletList.erase(m_pBulletList.begin() + Idx);
	m_pItemList.erase(m_pItemList.begin() + Idx);
	m_pMapObjList.erase(m_pMapObjList.begin() + Idx);
	m_pTopographyList.erase(m_pTopographyList.begin() + Idx);

	if (m_pGameObject[Idx] == m_pPlayer)
	{
		m_pPlayer = nullptr;
	}

	return 0;
}

INT cGameData::OnDeleteAllObject()
{
	m_pUnitList.clear();
	m_pBulletList.clear();
	m_pItemList.clear();
	m_pMapObjList.clear();
	m_pTopographyList.clear();

	m_pPlayer = nullptr;

	return 0;
}



cUnit_Player* cGameData::GetPlayer() const
{
	return m_pPlayer;
}