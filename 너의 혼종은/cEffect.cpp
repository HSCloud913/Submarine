#include "Util.h"

#include "cTexList.h"
#include "c2DAni.h"


#include "cEffect.h"



cEffect::cEffect(cTexList* pTexList, INT frameNum, INT delay)
	: m_pAni(new c2DAni(pTexList, frameNum, delay))
{
	m_pAni->Play();
}

cEffect::~cEffect()
{
	if (m_pAni != nullptr)
	{
		SAFE_DELETE(m_pAni);
	}
}



INT cEffect::Update()
{
	m_Pos += VFR(m_Speed);
	m_Angle += VFR(m_AngleSpeed);

	m_pAni->SetPos(&m_Pos);
	m_pAni->SetAngle(m_Angle);

	m_pAni->Update();

	return 0;
}

INT cEffect::Render()
{
	m_pAni->Render();

	return 0;
}



BOOL cEffect::IsEnd() const
{
	return m_pAni->IsEnd();
}