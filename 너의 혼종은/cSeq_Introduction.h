#pragma once
#include "cSequence.h"

class cSeq_Introduction :public cSequence
{
public:
	cSeq_Introduction();
	~cSeq_Introduction();

private:
	virtual INT OnInit() override;
	virtual INT OnCleanUp() override;
	virtual cSequence* OnUpdate() override;
	virtual INT OnRender() override;
};