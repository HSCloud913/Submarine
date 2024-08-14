#pragma once
#include "cGameObject.h"

class c2DAniList;

class c2DObject :public cGameObject
{
public:
	c2DObject(FLOAT moveSpeed);
	virtual ~c2DObject();

protected:
	c2DAniList* m_pAniList;
	DWORD m_Color;

protected:
	RECT m_CollRect;
	FLOAT m_MoveSpeed;

private:
	virtual INT OnUpdate(cData* pData) override;
	virtual INT OnRender() override;

protected:
	virtual INT OnUpdateObject(cData* pData) = 0;
	virtual INT OnRenderObject() = 0;

public:
	c2DAniList* GetAniList() const;

public:
	RECT GetCollRect();
	FLOAT GetMoveSpeed();
	void AddMoveSpeed(FLOAT moveSpeed);
};