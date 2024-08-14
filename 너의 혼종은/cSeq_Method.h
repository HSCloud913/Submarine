#pragma once
#include "cSequence.h"

class cSeq_Method :public cSequence
{
public:
	cSeq_Method();
	~cSeq_Method();

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};