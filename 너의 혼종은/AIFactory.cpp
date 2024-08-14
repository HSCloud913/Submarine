#include "cUnit.h"

#include "cAI_Player.h"
#include "cAI_AddOn.h"

#include "cAI_Y_Seahorse.h"
#include "cAI_R_Seahorse.h"
#include "cAI_Y_Puffer.h"
#include "cAI_R_Puffer.h"
#include "cAI_P_Cme.h"
#include "cAI_R_Cme.h"
#include "cAI_Y_MonkFish.h"
#include "cAI_R_MonkFish.h"

#include "cAI_Ray.h"
#include "cAI_Whale.h"
#include "cAI_Shark.h"
#include "cAI_Kraken.h"

#include "AIFactory.h"



AIFactory::AIFactory()
{
}

AIFactory::~AIFactory()
{
}



cAI* AIFactory::Create(AI::_Type aiType, cUnit* pUnit)
{
	cAI* pAI = nullptr;

	switch (aiType)
	{
	case AI::Player:
		pAI = new cAI_Player(pUnit);
		break;

	case AI::AddOn:
		pAI = new cAI_AddOn(pUnit);
		break;

	case AI::Y_Seahorse:
		pAI = new cAI_Y_Seahorse(pUnit);
		break;

	case AI::R_Seahorse:
		pAI = new cAI_R_Seahorse(pUnit);
		break;

	case AI::Y_Puffer:
		pAI = new cAI_Y_Puffer(pUnit);
		break;

	case AI::R_Puffer:
		pAI = new cAI_R_Puffer(pUnit);
		break;
	case AI::P_Cme:
		pAI = new cAI_P_Cme(pUnit);
		break;

	case AI::R_Cme:
		pAI = new cAI_R_Cme(pUnit);
		break;

	case AI::Y_MonkFish:
		pAI = new cAI_Y_MonkFish(pUnit);
		break;

	case AI::R_MonkFish:
		pAI = new cAI_R_MonkFish(pUnit);
		break;

	case AI::Ray:
		pAI = new cAI_Ray(pUnit);
		break;

	case AI::Whale:
		pAI = new cAI_Whale(pUnit);
		break;

	case AI::Shark:
		pAI = new cAI_Shark(pUnit);
		break;

	case AI::Kraken:
		pAI = new cAI_Kraken(pUnit);
		break;
	}

	return pAI;
}