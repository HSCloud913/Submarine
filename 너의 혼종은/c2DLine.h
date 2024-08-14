#pragma once
#include <d3dx9.h>

class c2DLine
{
public:
	c2DLine();
	~c2DLine();

private:
	LPD3DXLINE m_pLine;

public:
	INT Create();
	INT CleanUp();

public:
	INT Begin();
	INT End();

public:
	INT SetWidth(FLOAT width);

public:
	INT DrawLine(FLOAT left, FLOAT top, FLOAT right, FLOAT bottom, DWORD color);
	INT DrawLine(const D3DXVECTOR2* pVtx1, const D3DXVECTOR2* pVtx2, DWORD color);
	INT DrawLine(D3DXVECTOR2 vtxList[], UINT vtxNum, DWORD color);

public:
	INT RenderLine(FLOAT left, FLOAT top, FLOAT right, FLOAT bottom, DWORD color);
	INT RenderLine(const D3DXVECTOR2* pVtx1, const D3DXVECTOR2* pVtx2, DWORD color);
	INT RenderLine(D3DXVECTOR2 vtxList[], UINT vtxNum, DWORD color);
};