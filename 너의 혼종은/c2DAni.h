#pragma once
#include "c2DCoord.h"

class cTexList;

class c2DAni :public c2DCoord
{
public:
	c2DAni(cTexList* pTexList, INT frameNum, DWORD delay);
	~c2DAni();

private:
	cTexList* m_pTexList;
	INT m_FrameNum;
	INT m_Delay;

private:
	DWORD m_PrevTime;
	INT m_CurrFrame;

private:
	BOOL m_bPlay;
	BOOL m_bEnd;

public:
	INT Update();
	INT Render();

public:
	INT Play();
	INT Pause();
	INT Stop();

public:
	INT GetCurrFrame() const;
	void SetCurrFrame(INT frame);

public:
	BOOL IsEnd() const;
};