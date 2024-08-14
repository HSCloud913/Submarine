#pragma once
#include "cMapObject.h"

class cMapObj_Stone :public cMapObject
{
public:
	cMapObj_Stone();
	~cMapObj_Stone();
private:
	virtual INT OnUpdateMapObject(cData* pData) override;
	virtual INT OnRenderMapObject() override;
};