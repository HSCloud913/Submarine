#pragma once
#include <vector>
#include "cGameObject.h"

class cTopography :public cGameObject
{
public:
	cTopography(INT num);
	~cTopography();

private:
	std::vector<RECT> m_CollRectList;

private:
	INT m_Num;
	FLOAT m_MoveSpeed;

private:
	virtual INT OnUpdate(cData* pData) override;
	virtual INT OnRender() override;

public:
	UINT GetSize() const;
	RECT GetCollRect(UINT Idx) const;
	FLOAT GetMoveSpeed() const;
};