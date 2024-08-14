#include "Util.h"

#include "cData.h"

#include "cTopography.h"



cTopography::cTopography(INT num)
	: m_Num(num)
	, m_MoveSpeed(-5.f)
{
	if (num == 0)
	{
		RECT Rect1 = { 80 - 640, 568 - 360, 190 - 640, 720 - 360 };
		RECT Rect2 = { 190 - 640, 550 - 360, 1190 - 640, 720 - 360 };
		RECT Rect3 = { 206 - 640, 466 - 360, 487 - 640, 550 - 360 };
		RECT Rect4 = { 570 - 640, 451 - 360, 1171 - 640, 550 - 360 };
		RECT Rect5 = { 593 - 640, 315 - 360, 1157 - 640, 453 - 360 };
		RECT Rect6 = { 613 - 640, 111 - 360, 865 - 640, 319 - 360 };
		RECT Rect7 = { 867 - 640, 250 - 360, 1070 - 640, 321 - 360 };
		RECT Rect8 = { 865 - 640, 162 - 360, 909 - 640, 249 - 360 };
		RECT Rect9 = { 735 - 640, 69 - 360, 830 - 640, 112 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
		m_CollRectList.push_back(Rect7);
		m_CollRectList.push_back(Rect8);
		m_CollRectList.push_back(Rect9);
	}

	if (num == 1)
	{
		RECT Rect1 = { 221 - 640, 490 - 360, 270 - 640, 608 - 360 };
		RECT Rect2 = { 271 - 640, 477 - 360, 874 - 640, 720 - 360 };
		RECT Rect3 = { 880 - 522, 526 - 360, 1060 - 640, 720 - 360 };
		RECT Rect4 = { 1060 - 640, 669 - 360, 1106 - 640, 720 - 360 };
		RECT Rect5 = { 875 - 640, 490 - 360, 911 - 640, 525 - 360 };
		RECT Rect6 = { 955 - 640, 497 - 360, 1060 - 640, 524 - 360 };
		RECT Rect7 = { 308 - 640, 392 - 360, 813 - 640, 471 - 360 };
		RECT Rect8 = { 355 - 640, 323 - 360, 766 - 640, 386 - 360 };
		RECT Rect9 = { 487 - 640, 241 - 360, 618 - 640, 321 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
		m_CollRectList.push_back(Rect7);
		m_CollRectList.push_back(Rect8);
		m_CollRectList.push_back(Rect9);
	}

	if (num == 2)
	{
		RECT Rect1 = { 163 - 640, 517 - 360, 196 - 640, 718 - 360 };
		RECT Rect2 = { 128 - 640, 587 - 360, 195 - 640, 653 - 360 };
		RECT Rect3 = { 152 - 522, 552 - 360, 197 - 640, 587 - 360 };
		RECT Rect4 = { 163 - 640, 517 - 360, 197 - 640, 553 - 360 };
		RECT Rect5 = { 199 - 640, 487 - 360, 1180 - 640, 720 - 360 };
		RECT Rect6 = { 201 - 640, 406 - 360, 674 - 640, 490 - 360 };
		RECT Rect7 = { 672 - 640, 450 - 360, 978 - 640, 488 - 360 };
		RECT Rect8 = { 840 - 640, 420 - 360, 941 - 640, 453 - 360 };
		RECT Rect9 = { 227 - 640, 365 - 360, 671 - 640, 407 - 360 };
		RECT Rect10 = { 266 - 640, 497 - 330, 602 - 640, 367 - 360 };
		RECT Rect11 = { 300 - 640, 245 - 360, 462 - 640, 332 - 360 };
		RECT Rect12 = { 536 - 640, 323 - 360, 596 - 640, 330 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
		m_CollRectList.push_back(Rect7);
		m_CollRectList.push_back(Rect8);
		m_CollRectList.push_back(Rect9);
		m_CollRectList.push_back(Rect10);
		m_CollRectList.push_back(Rect11);
		m_CollRectList.push_back(Rect12);
	}

	if (num == 3)
	{
		RECT Rect1 = { 53 - 640, 589 - 360, 1208 - 640, 720 - 360 };
		RECT Rect2 = { 119 - 640, 552 - 360, 1207 - 640, 589 - 360 };
		RECT Rect3 = { 181 - 640, 490 - 360, 237 - 640, 551 - 360 };
		RECT Rect4 = { 237 - 640, 468 - 360, 487 - 640, 549 - 360 };
		RECT Rect5 = { 565 - 640, 477 - 360, 1193 - 640, 552 - 360 };
		RECT Rect6 = { 610 - 640, 175 - 360, 669 - 640, 477 - 360 };
		RECT Rect7 = { 669 - 640, 139 - 360, 878 - 640, 476 - 360 };
		RECT Rect8 = { 877 - 640, 199 - 360, 920 - 640, 277 - 360 };
		RECT Rect9 = { 878 - 640, 278 - 360, 1076 - 640, 474 - 360 };
		RECT Rect10 = { 1078 - 640, 333 - 330, 1179 - 640, 476 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
		m_CollRectList.push_back(Rect7);
		m_CollRectList.push_back(Rect8);
		m_CollRectList.push_back(Rect9);
		m_CollRectList.push_back(Rect10);
	}

	if (num == 4)
	{
		RECT Rect1 = { 221 - 640, 489 - 360, 267 - 640, 598 - 360 };
		RECT Rect2 = { 264 - 640, 477 - 360, 873 - 640, 718 - 360 };
		RECT Rect3 = { 870 - 640, 501 - 360, 1063 - 640, 718 - 360 };
		RECT Rect4 = { 316 - 640, 388 - 360, 493 - 640, 476 - 360 };
		RECT Rect5 = { 491 - 640, 241 - 360, 622 - 640, 478 - 360 };
		RECT Rect6 = { 623 - 640, 340 - 360, 816 - 640, 479 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
	}

	if (num == 5)
	{
		RECT Rect1 = { 108 - 640, 0 - 360, 1182 - 640, 161 - 360 };
		RECT Rect2 = { 161 - 640, 159 - 360, 1134 - 640, 230 - 360 };
		RECT Rect3 = { 335 - 640, 233 - 360, 1088 - 640, 292 - 360 };
		RECT Rect4 = { 610 - 640, 294 - 360, 1076 - 640, 337 - 360 };
		RECT Rect5 = { 651 - 640, 336 - 360, 1059 - 640, 376 - 360 };
		RECT Rect6 = { 689 - 640, 373 - 360, 759 - 640, 413 - 360 };
		RECT Rect7 = { 813 - 640, 377 - 360, 1021 - 640, 469 - 360 };

		m_CollRectList.push_back(Rect1);
		m_CollRectList.push_back(Rect2);
		m_CollRectList.push_back(Rect3);
		m_CollRectList.push_back(Rect4);
		m_CollRectList.push_back(Rect5);
		m_CollRectList.push_back(Rect6);
		m_CollRectList.push_back(Rect7);
	}
}

cTopography::~cTopography()
{
}



INT cTopography::OnUpdate(cData* pData)
{
	if (pData->MapScroll())
	{
		m_Speed.x = m_MoveSpeed;
	}

	else
	{
		m_Speed.x = 0.f;
	}
	

	return 0;
}

INT cTopography::OnRender()
{
	cD3DApp::Sprite.RenderTextureCenter(
		cSystem::Resource.m_pTexList[TexList_Topography]->GetTexture(m_Num), m_Pos);


	
	return 0;
}



UINT cTopography::GetSize() const
{
	return m_CollRectList.size();
}

RECT cTopography::GetCollRect(UINT Idx) const
{
	RECT Rect = { 0, 0, 0 ,0 };

	if (Idx < GetSize())
	{
		Rect.left = m_Pos.x + m_CollRectList[Idx].left;
		Rect.right = m_Pos.x + m_CollRectList[Idx].right;
		Rect.top = m_Pos.y + m_CollRectList[Idx].top;
		Rect.bottom = m_Pos.y + m_CollRectList[Idx].bottom;
	}

	return Rect;
}

FLOAT cTopography::GetMoveSpeed() const
{
	return m_MoveSpeed;
}