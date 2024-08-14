#pragma once
#include "cData.h"
#include "Type.h"

class cEffectList;

class cUnit_Player;
class cUnit;
class cBullet;
class cItem;
class cMapObject;
class cTopography;

class cGameData :public cData
{
public:
	cGameData(INT stageNum);
	~cGameData();

private:
	cEffectList* m_pEffectList;

private:
	cUnit_Player* m_pPlayer;
	std::vector<cUnit*> m_pUnitList;
	std::vector<cBullet*> m_pBulletList;
	std::vector<cItem*> m_pItemList;
	std::vector<cMapObject*> m_pMapObjList;
	std::vector<cTopography*> m_pTopographyList;

private:
	BOOL m_bAddOn1;
	BOOL m_bAddOn2;

private:
	virtual INT OnUpdate() override;
	virtual INT OnRender() override;

private:
	virtual INT OnAddObject(cGameObject* pGameObject) override;
	virtual INT OnDeleteObject(UINT Idx) override;
	virtual INT OnDeleteAllObject() override;

public:
	cUnit_Player* GetPlayer() const;
};