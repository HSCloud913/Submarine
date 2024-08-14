#pragma once
#include <Windows.h>
#include "FadeType.h"

class cFade
{
public:
	cFade(Fade::_Type fadeType, FLOAT speed);
	~cFade();

private:
	Fade::_Type m_FadeType;
	FLOAT m_Alpha;
	FLOAT m_Speed;

private:
	BOOL m_bEnd;

public:
	INT Init();

	INT Update();
	INT Render();

public:
	BOOL GetAlpha() const;

public:
	BOOL IsEnd() const;
};