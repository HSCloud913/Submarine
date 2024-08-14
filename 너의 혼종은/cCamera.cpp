#include "Util.h"

#include "cCamera.h"



cCamera::cCamera()
{
}

cCamera::~cCamera()
{
}



INT cCamera::FrameMove()
{
	m_Pos += VFR(m_Speed);

	return 0;
}

INT cCamera::Control()
{
	return 0;
}

INT cCamera::Reset()
{
	m_Pos = D3DXVECTOR2(0.f, 0.f);
	m_Speed = D3DXVECTOR2(0.f, 0.f);

	m_Scale = D3DXVECTOR2(1.f, 1.f);

	m_Angle = 0.f;
	m_AngleSpeed = 0.f;

	return 0;
}



const D3DXVECTOR2* cCamera::Pos() const
{
	if (cD3DApp::Sprite.CameraCheck())
	{
		return &m_Pos;
	}

	return &D3DXVECTOR2(0.f, 0.f);
}

D3DXMATRIX* cCamera::Matrix()
{
	D3DXMatrixScaling(&m_Mat[0], m_Scale.x, m_Scale.y, 1.f);
	D3DXMatrixRotationZ(&m_Mat[1], D3DXToRadian(m_Angle));
	D3DXMatrixTranslation(&m_Mat[2], -m_Pos.x, -m_Pos.y, 0.f);

	m_WorldMat = m_Mat[0] * m_Mat[1] * m_Mat[2];

	return &m_WorldMat;
}