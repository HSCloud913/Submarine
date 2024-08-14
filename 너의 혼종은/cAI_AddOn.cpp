#include "Util.h"

#include "cGameData.h"

#include "cUnit.h"
#include "cUnit_Player.h"

#include "c2DAniList.h"

#include "cAI_AddOn.h"



INT cAI_AddOn::m_Count = 0;



cAI_AddOn::cAI_AddOn(cUnit* pUnit)
	: cAI(pUnit)
{
	m_Num = ++m_Count;
}

cAI_AddOn::~cAI_AddOn()
{
}



INT cAI_AddOn::OnUpdate(cData* pData)
{
	cGameData* pGameData = dynamic_cast<cGameData*>(pData);

	if (pGameData != nullptr)
	{
		if (pGameData->GetPlayer() != nullptr)
		{
			if (m_pUnit->GetAniList()->GetCurrFrame() == 6)
			{
				m_pUnit->UseWeapon(pData, 90.f);
			}

			D3DXVECTOR2 Pos = *pGameData->GetPlayer()->Pos();


			if (m_Num % 2 == 0)
			{
				Pos.y -= 90.f;
				Pos.x += 75.f;
			}

			else if (m_Num % 2 == 1)
			{
				Pos.y += 90.f;
				Pos.x -= 75.f;
			}
			

			m_pUnit->SetPos(&Pos);
		}

		else
		{
			m_pUnit->AddHp(-1);
		}
	}

	return 0;
}