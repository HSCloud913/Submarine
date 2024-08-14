#include "Util.h"

#include "cAI.h"
#include "AIFactory.h"

#include "cWeapon.h"

#include "cUnit.h"



cUnit::cUnit(FLOAT moveSpeed)
	: c2DObject(moveSpeed)

	, m_pEnemyPos(nullptr)

	, m_CurrWeaponNum(-1)

	, m_CurrUpgrade(0)

	, m_bImmortal(FALSE)
	, m_bSystemImmortal(FALSE)
{
	m_pWeaponList.clear();
}

cUnit::~cUnit()
{
	for (UINT i = 0; i < m_pWeaponList.size(); i++)
	{
		SAFE_DELETE(m_pWeaponList[i]);
	}

	m_pWeaponList.clear();

	if (m_pAI != nullptr)
	{
		SAFE_DELETE(m_pAI);
	}
}



INT cUnit::Init(AI::_Type aiType, Team::_Type teamType, Unit::_Type unitType
	, INT hp, INT score)
{
	m_pAI = AIFactory::Create(aiType, this);
	
	m_TeamType = teamType;
	m_UnitType = unitType;
	
	m_MaxHp = hp;
	m_Hp = hp;

	m_Score = score;

	return 0;
}

INT cUnit::OnUpdateObject(cData* pData)
{
	if (m_pAI != nullptr)
	{
		m_pAI->Update(pData);
	}

	return OnUpdateUnit(pData);
}

INT cUnit::OnRenderObject()
{
	return OnRenderUnit();
}



INT cUnit::ItemDrop(cData* pData)
{
	return OnItemDrop(pData);
}



cWeapon* cUnit::GetWeapon() const
{
	if (m_CurrWeaponNum > -1)
	{
		return m_pWeaponList[m_CurrWeaponNum];
	}

	return nullptr;
}

INT cUnit::UseWeapon(cData* pData, FLOAT degree)
{
	if (m_CurrWeaponNum > -1)
	{
		return m_pWeaponList[m_CurrWeaponNum]->UseWeapon(pData, m_Pos, degree, m_CurrUpgrade);
	}

	return -1;
}


INT cUnit::GetCurrWeaponNum() const
{
	return m_CurrWeaponNum;
}

void cUnit::SetCurrWeaponNum(INT weaponNum)
{
	if (weaponNum > -1)
	{
		m_CurrWeaponNum = weaponNum;
	}
}



Team::_Type cUnit::GetTeamType() const
{
	return m_TeamType;
}

Unit::_Type cUnit::GetUnitType() const
{
	return m_UnitType;
}



D3DXVECTOR2* cUnit::GetEnemyPos() const
{
	return m_pEnemyPos;
}

void cUnit::SetEnemyPos(const D3DXVECTOR2& pos)
{
	if (m_pEnemyPos != nullptr)
	{
		*m_pEnemyPos = pos;
	}

	else
	{
		m_pEnemyPos = new D3DXVECTOR2(pos);
	}
}



INT cUnit::GetCurrUpgrade() const
{
	return m_CurrUpgrade;
}

void cUnit::AddCurrUpgrade(INT upgrade)
{
	m_CurrUpgrade += upgrade;

	if (m_CurrUpgrade > 2)
	{
		m_CurrUpgrade = 2;
	}

	if (m_CurrUpgrade < 0)
	{
		m_CurrUpgrade = 0;
	}
}



INT cUnit::GetHp() const
{
	return m_Hp;
}

INT cUnit::GetScore() const
{
	return m_Score;
}


void cUnit::AddHp(INT hp)
{
	m_Hp += hp;

	if (m_Hp > m_MaxHp)
	{
		m_Hp = m_MaxHp;
	}
}

void cUnit::AddScore(INT score)
{
	m_Score += score;
}


BOOL cUnit::IsImmortal() const
{
	return m_bImmortal;
}

BOOL cUnit::IsSystemImmortal() const
{
	return m_bSystemImmortal;
}


void cUnit::SetImmortal(BOOL immortal)
{
	m_bImmortal = immortal;
}

void cUnit::SetSystemImmortal(BOOL immortal)
{
	m_bSystemImmortal = immortal;
}