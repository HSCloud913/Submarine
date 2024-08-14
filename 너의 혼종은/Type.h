#pragma once

namespace Team
{
	enum _Type
	{
		Player
		, Assist
		, Enemy
	};
}

namespace AI
{
	enum _Type
	{
		Player
		, AddOn

		, Y_Seahorse
		, R_Seahorse
		, Y_Puffer
		, R_Puffer

		, P_Cme
		, R_Cme
		, Y_MonkFish
		, R_MonkFish

		, Ray
		, Whale
		, Shark
		, Kraken
	};
}

namespace Unit
{
	enum _Type
	{
		Player
		, AddOn

		, Y_Seahorse
		, R_Seahorse
		, Y_Puffer
		, R_Puffer

		, P_Cme
		, R_Cme
		, Y_MonkFish
		, R_MonkFish
		
		, Ray
		, Whale
		, Shark
		, Kraken
	};
}

namespace Item
{
	enum _Type
	{
		OnceTorpedo
		, TripleTorpedo
		, GuidedTorpedo
		, Nuclear
		, Speed
		, Upgrade
	};
}

namespace MapObject
{
	enum _Type
	{
		Stone
		, Seaweed
	};
}

namespace Bullet
{
	enum _Type
	{
		Torpedo
		, GuidedTorpedo
		, Nuclear
		, AddOn

		, Y_Seahorse
		, R_Seahorse
		, Y_Puffer
		, R_Puffer
		, P_Cme
		, R_Cme
		, Y_MonkFish
		, R_MonkFish

		, Ray
		, Whale
		, Shark
		, Kraken
	};
}

namespace Effect
{
	enum _Type
	{
		Boom
		, Hit
		, Item
		, SonicWave
	};
}