#include "cUnit_Player.h"
#include "cUnit_AddOn.h"

#include "cUnit_Y_Seahorse.h"
#include "cUnit_R_Seahorse.h"
#include "cUnit_Y_Puffer.h"
#include "cUnit_R_Puffer.h"
#include "cUnit_P_Cme.h"
#include "cUnit_R_Cme.h"
#include "cUnit_Y_MonkFish.h"
#include "cUnit_R_MonkFish.h"

#include "cUnit_Ray.h"
#include "cUnit_Whale.h"
#include "cUnit_Shark.h"
#include "cUnit_Kraken.h"

#include "UnitFactory.h"



UnitFactory::UnitFactory()
{
}

UnitFactory::~UnitFactory()
{
}



cUnit* UnitFactory::Create(Unit::_Type unitType, const D3DXVECTOR2& pos)
{
	cUnit* pUnit = nullptr;

	switch (unitType)
	{
	case Unit::Player:
		pUnit = new cUnit_Player;
		break;

	case Unit::AddOn:
		pUnit = new cUnit_AddOn;
		break;

	case Unit::Y_Seahorse:
		pUnit = new cUnit_Y_Seahorse;
		break;

	case Unit::R_Seahorse:
		pUnit = new cUnit_R_Seahorse;
		break;

	case Unit::Y_Puffer:
		pUnit = new cUnit_Y_Puffer;
		break;

	case Unit::R_Puffer:
		pUnit = new cUnit_R_Puffer;
		break;

	case Unit::P_Cme:
		pUnit = new cUnit_P_Cme;
		break;

	case Unit::R_Cme:
		pUnit = new cUnit_R_Cme;
		break;

	case Unit::Y_MonkFish:
		pUnit = new cUnit_Y_MonkFish;
		break;

	case Unit::R_MonkFish:
		pUnit = new cUnit_R_MonkFish;
		break;

	case Unit::Ray:
		pUnit = new cUnit_Ray;
		break;

	case Unit::Whale:
		pUnit = new cUnit_Whale;
		break;

	case Unit::Shark:
		pUnit = new cUnit_Shark;
		break;

	case Unit::Kraken:
		pUnit = new cUnit_Kraken;
		break;
	}

	if (pUnit != nullptr)
	{
		pUnit->SetPos(&pos);
	}

	return pUnit;
}