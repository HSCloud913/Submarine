#pragma once
#include <Windows.h>
#include "cDevice.h"
#include "cSprite.h"

class cD3DApp
{
public:
	cD3DApp();
	~cD3DApp();

public:
	static cDevice Device;
	static cSprite Sprite;

public:
	INT Init(BOOL bWindowed);
	INT CleanUp();
};