#include "Util.h"

#include "c2DAniList.h"

#include "c2DObject.h"



c2DObject::c2DObject(FLOAT moveSpeed)
	: m_MoveSpeed(moveSpeed)

	, m_pAniList(new c2DAniList)
	, m_Color(0xffffffff)
{
}

c2DObject::~c2DObject()
{
}



INT c2DObject::OnUpdate(cData* pData)
{
	m_pAniList->SetPos(&m_Pos);
	m_pAniList->SetScale(&m_Scale);
	m_pAniList->SetAngle(m_Angle);

	m_pAniList->Update();

	return OnUpdateObject(pData);
}

INT c2DObject::OnRender()
{
	cD3DApp::Sprite.SetColor(m_Color);
	m_pAniList->Render();
	
	return OnRenderObject();
}



c2DAniList* c2DObject::GetAniList() const
{
	return m_pAniList;
}



RECT c2DObject::GetCollRect()
{
	RECT Rect;

	Rect.left = m_Pos.x + m_CollRect.left;
	Rect.right = m_Pos.x + m_CollRect.right;
	Rect.top = m_Pos.y + m_CollRect.top;
	Rect.bottom = m_Pos.y + m_CollRect.bottom;

	return Rect;
}

FLOAT c2DObject::GetMoveSpeed()
{
	return m_MoveSpeed;
}

void c2DObject::AddMoveSpeed(FLOAT moveSpeed)
{
	m_MoveSpeed += moveSpeed;

	if (m_MoveSpeed > 15.f)
	{
		m_MoveSpeed = 15.f;
	}

	if (m_MoveSpeed < 5.f)
	{
		m_MoveSpeed = 5.f;
	}
}