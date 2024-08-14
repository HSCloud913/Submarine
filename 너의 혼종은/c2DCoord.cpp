#include "c2DCoord.h"



c2DCoord::c2DCoord()
	: m_Pos(0.f, 0.f)
	, m_Speed(0.f, 0.f)

	, m_Scale(1.f, 1.f)
	
	, m_Angle(0.f)
	, m_AngleSpeed(0.f)
{
}

c2DCoord::~c2DCoord()
{
}



const D3DXVECTOR2* c2DCoord::Pos() const
{
	return &m_Pos;
}

const D3DXVECTOR2* c2DCoord::Speed() const
{
	return &m_Speed;
}

const D3DXVECTOR2* c2DCoord::Scale() const
{
	return &m_Scale;
}

FLOAT c2DCoord::Angle() const
{
	return m_Angle;
}

FLOAT c2DCoord::AngleSpeed() const
{
	return m_AngleSpeed;
}



void c2DCoord::SetPos(const D3DXVECTOR2* pPos)
{
	m_Pos = *pPos;
}

void c2DCoord::SetPos(FLOAT x, FLOAT y)
{
	m_Pos = D3DXVECTOR2(x, y);
}

void c2DCoord::SetXPos(FLOAT x)
{
	m_Pos.x = x;
}

void c2DCoord::SetYPos(FLOAT y)
{
	m_Pos.y = y;
}


void c2DCoord::SetSpeed(const D3DXVECTOR2* pSpeed)
{
	m_Speed = *pSpeed;
}

void c2DCoord::SetSpeed(FLOAT x, FLOAT y)
{
	m_Speed = D3DXVECTOR2(x, y);
}

void c2DCoord::SetXSpeed(FLOAT x)
{
	m_Speed.x = x;
}

void c2DCoord::SetYSpeed(FLOAT y)
{
	m_Speed.y = y;
}


void c2DCoord::SetScale(const D3DXVECTOR2* pScale)
{
	m_Scale = *pScale;
}

void c2DCoord::SetScale(FLOAT x, FLOAT y)
{
	m_Scale = D3DXVECTOR2(x, y);
}

void c2DCoord::SetXScale(FLOAT x)
{
	m_Scale.x = x;
}

void c2DCoord::SetYScale(FLOAT y)
{
	m_Scale.y = y;
}


void c2DCoord::SetAngle(FLOAT angle)
{
	m_Angle = angle;
}

void c2DCoord::SetAngleSpeed(FLOAT angleSpeed)
{
	m_AngleSpeed = angleSpeed;
}



void c2DCoord::AddPos(const D3DXVECTOR2* pPos)
{
	m_Pos += *pPos;
}

void c2DCoord::AddPos(FLOAT x, FLOAT y)
{
	m_Pos += D3DXVECTOR2(x, y);
}

void c2DCoord::AddXPos(FLOAT x)
{
	m_Pos.x += x;
}

void c2DCoord::AddYPos(FLOAT y)
{
	m_Pos.y += y;
}


void c2DCoord::AddSpeed(const D3DXVECTOR2* pSpeed)
{
	m_Speed += *pSpeed;
}

void c2DCoord::AddSpeed(FLOAT x, FLOAT y)
{
	m_Speed += D3DXVECTOR2(x, y);
}

void c2DCoord::AddXSpeed(FLOAT x)
{
	m_Speed.x += x;
}

void c2DCoord::AddYSpeed(FLOAT y)
{
	m_Speed.y += y;
}


void c2DCoord::AddScale(const D3DXVECTOR2* pScale)
{
	m_Scale += *pScale;
}

void c2DCoord::AddScale(FLOAT x, FLOAT y)
{
	m_Scale += D3DXVECTOR2(x, y);
}

void c2DCoord::AddXScale(FLOAT x)
{
	m_Scale.x += x;
}

void c2DCoord::AddYScale(FLOAT y)
{
	m_Scale.y += y;
}


void c2DCoord::AddAngle(FLOAT angle)
{
	m_Angle += angle;
}

void c2DCoord::AddAngleSpeed(FLOAT angleSpeed)
{
	m_AngleSpeed += angleSpeed;
}



const D3DXMATRIX* c2DCoord::WorldMatrix() const
{
	return &m_WorldMat;
}

D3DXMATRIX* c2DCoord::Matrix()
{
	D3DXMatrixScaling(&m_Mat[0], m_Scale.x, m_Scale.y, 1.f);
	D3DXMatrixRotationZ(&m_Mat[1], D3DXToRadian(m_Angle));
	D3DXMatrixTranslation(&m_Mat[2], m_Pos.x, m_Pos.y, 0.f);

	m_WorldMat = m_Mat[0] * m_Mat[1] * m_Mat[2];

	return &m_WorldMat;
}