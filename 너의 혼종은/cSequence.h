#pragma once
#include <Windows.h>

class cSequence
{
public:
	cSequence();
	virtual ~cSequence();

public:
	INT Init();
	INT CleanUp();
	cSequence* Update();
	INT Render();

protected:
	virtual INT OnInit() = 0;
	virtual INT OnCleanUp() = 0;
	virtual cSequence* OnUpdate() = 0;
	virtual INT OnRender() = 0;
};