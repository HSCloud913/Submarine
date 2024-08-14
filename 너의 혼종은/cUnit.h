#pragma once
#include <vector>
#include "c2DObject.h"
#include "Type.h"

class cAI;

class cWeapon;

class cUnit :public c2DObject
{
public:
	cUnit(FLOAT moveSpeed);
	virtual ~cUnit();

protected:
	Team::_Type m_TeamType;
	Unit::_Type m_UnitType;

protected:
	cAI* m_pAI;
	D3DXVECTOR2* m_pEnemyPos;

protected:
	std::vector<cWeapon*> m_pWeaponList;
	INT m_CurrWeaponNum;

protected:
	INT m_CurrUpgrade;

protected:
	INT m_MaxHp;
	INT m_Hp;

	INT m_Score;

protected:
	BOOL m_bImmortal;
	BOOL m_bSystemImmortal;

protected:
	INT Init(AI::_Type aiType, Team::_Type teamType, Unit::_Type unitType
		, INT hp, INT score);

private:
	virtual INT OnUpdateObject(cData* pData) override;
	virtual INT OnRenderObject() override;

protected:
	virtual INT OnUpdateUnit(cData* pData) = 0;
	virtual INT OnRenderUnit() = 0;

public:
	INT ItemDrop(cData* pData);

protected:
	virtual INT OnItemDrop(cData* pData) = 0;

public:
	cWeapon* GetWeapon() const;
	INT UseWeapon(cData* pData, FLOAT degree);

	INT GetCurrWeaponNum() const;
	void SetCurrWeaponNum(INT weaponNum);

public:
	Team::_Type GetTeamType() const;
	Unit::_Type GetUnitType() const;

public:
	D3DXVECTOR2* GetEnemyPos() const;
	void SetEnemyPos(const D3DXVECTOR2& pos);

public:
	INT GetCurrUpgrade() const;
	void AddCurrUpgrade(INT upgrade);

public:
	INT GetHp() const;
	INT GetScore() const;

	void AddHp(INT hp);
	void AddScore(INT score);

public:
	BOOL IsImmortal() const;
	BOOL IsSystemImmortal() const;

	void SetImmortal(BOOL immortal = TRUE);
	void SetSystemImmortal(BOOL immortal = TRUE);
};