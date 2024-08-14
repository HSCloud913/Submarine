#pragma once
#include "cUnit.h"

class cTimer;

class cUnit_Player :public cUnit
{
public:
	cUnit_Player();
	~cUnit_Player();

private:
	cTimer* m_pTimer;

private:
	cTimer* m_pChaos;
	cTimer* m_pInk;

private:
	INT m_Nuclear;
	INT m_AddOn;

private:
	BOOL m_bChaos;
	BOOL m_bInk;

private:
	virtual INT OnUpdateUnit(cData* pData) override;
	virtual INT OnRenderUnit() override;

private:
	virtual INT OnItemDrop(cData* pData) override;

public:
	INT NuclearCnt() const;
	INT AddOnCnt() const;

public:
	void AddNuclear(INT num);
	BOOL AddOn(int num);

public:
	BOOL IsChaos() const;
	BOOL IsInk() const;

public:
	void SetChaos(BOOL bChaos = TRUE);
	void SetInk(BOOL bInk = TRUE);
};