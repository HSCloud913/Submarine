#include "Util.h"

#include "cEffect.h"

#include "cEffectList.h"



cEffectList::cEffectList()
{
	m_pEffect.clear();
}

cEffectList::~cEffectList()
{
	for (UINT i = 0; i < m_pEffect.size(); i++)
	{
		SAFE_DELETE(m_pEffect[i]);
	}

	m_pEffect.clear();
}



INT cEffectList::Update()
{
	for (UINT i = 0; i < m_pEffect.size(); i++)
	{
		m_pEffect[i]->Update();

		if (m_pEffect[i]->IsEnd())
		{
			SAFE_DELETE(m_pEffect[i]);
			m_pEffect.erase(m_pEffect.begin() + i);

			i--;
			continue;
		}
	}

	return 0;
}

INT cEffectList::Render()
{
	for (UINT i = 0; i < m_pEffect.size(); i++)
	{
		m_pEffect[i]->Render();
	}

	return 0;
}



INT cEffectList::AddEffect(cTexList* pTex, INT frameNum, DWORD delay, const D3DXVECTOR2& pos)
{
	UINT Idx = m_pEffect.size();
	m_pEffect.push_back(new cEffect(pTex, frameNum, delay));
	m_pEffect[Idx]->SetPos(&pos);

	return 0;
}