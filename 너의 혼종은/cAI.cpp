#include "cData.h"

#include "cUnit.h"

#include "cAI.h"



cAI::cAI(cUnit* pUnit)
	: m_pUnit(pUnit)
{
	m_pUnit->SetXSpeed(-m_pUnit->GetMoveSpeed());
}

cAI::~cAI()
{
}



INT cAI::Update(cData* pData)
{
	return OnUpdate(pData);
}