#pragma once
#include <d3dx9.h>

class c2DCoord
{
public:
	c2DCoord();
	virtual ~c2DCoord();

protected:
	D3DXMATRIX m_WorldMat;
	D3DXMATRIX m_Mat[3];

protected:
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_Speed;
	
	D3DXVECTOR2 m_Scale;

	FLOAT m_Angle;
	FLOAT m_AngleSpeed;

public:
	virtual const D3DXVECTOR2* Pos() const;
	virtual const D3DXVECTOR2* Speed() const;
	virtual const D3DXVECTOR2* Scale() const;
	FLOAT Angle() const;
	FLOAT AngleSpeed() const;

public:
	void SetPos(const D3DXVECTOR2* pPos);
	void SetPos(FLOAT x, FLOAT y);
	void SetXPos(FLOAT x);
	void SetYPos(FLOAT y);

	void SetSpeed(const D3DXVECTOR2* pSpeed);
	void SetSpeed(FLOAT x, FLOAT y);
	void SetXSpeed(FLOAT x);
	void SetYSpeed(FLOAT y);

	void SetScale(const D3DXVECTOR2* pScale);
	void SetScale(FLOAT x, FLOAT y);
	void SetXScale(FLOAT x);
	void SetYScale(FLOAT y);

	void SetAngle(FLOAT angle);
	void SetAngleSpeed(FLOAT angleSpeed);

public:
	void AddPos(const D3DXVECTOR2* pPos);
	void AddPos(FLOAT x, FLOAT y);
	void AddXPos(FLOAT x);
	void AddYPos(FLOAT y);

	void AddSpeed(const D3DXVECTOR2* pSpeed);
	void AddSpeed(FLOAT x, FLOAT y);
	void AddXSpeed(FLOAT x);
	void AddYSpeed(FLOAT y);

	void AddScale(const D3DXVECTOR2* pScale);
	void AddScale(FLOAT x, FLOAT y);
	void AddXScale(FLOAT x);
	void AddYScale(FLOAT y);

	void AddAngle(FLOAT angle);
	void AddAngleSpeed(FLOAT angleSpeed);

public:
	const D3DXMATRIX* WorldMatrix() const;
	virtual D3DXMATRIX* Matrix();
};