#include "Util.h"

#include "cData.h"

#include "cGameObject.h"



cGameObject::cGameObject()
{
}

cGameObject::~cGameObject()
{
}



INT cGameObject::Update(cData* pData)
{
	m_Pos += VFR(m_Speed);
	m_Angle += VFR(m_AngleSpeed);

	return OnUpdate(pData);
}

INT cGameObject::Render()
{
	return OnRender();
}