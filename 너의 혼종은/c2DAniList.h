#pragma once
#include <vector>
#include "c2DCoord.h"

class cTexList;
class c2DAni;

class c2DAniList :public c2DCoord
{
public:
	c2DAniList();
	~c2DAniList();

private:
	std::vector<c2DAni*> m_pAniList;
	INT m_CurrAniNum;
	BOOL m_bLock;

public:
	INT Update();
	INT Render();

public:
	INT AddAni(cTexList* pTexList, INT frameNum, DWORD delay);

public:
	INT Play();
	INT Pause();
	INT Stop();

public:
	INT GetCurrFrame() const;
	void SetCurrFrame(INT frame);

public:
	INT GetCurrAniNum() const;
	void SetCurrAniNum(INT aniNum);

public:
	void Lock();
	void UnLock();
	BOOL IsLock() const;
	
public:
	BOOL IsEnd() const;
};