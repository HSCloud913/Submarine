#pragma once
#include "cMapObject.h"

class cMapObj_Seaweed :public cMapObject
{
public:
	cMapObj_Seaweed();
	~cMapObj_Seaweed();

private:
	virtual INT OnUpdateMapObject(cData* pData) override;
	virtual INT OnRenderMapObject() override;
};