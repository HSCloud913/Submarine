#include "Util.h"

#include "c2DLine.h"



c2DLine::c2DLine()
	: m_pLine(nullptr)
{
}

c2DLine::~c2DLine()
{
	CleanUp();
}



INT c2DLine::Create()
{
	if (FAILED(D3DXCreateLine(cD3DApp::Device.GetDevice(), &m_pLine)))
	{
		return Util::ErrorMessage(L"D3DXCreateLine");
	}

	m_pLine->SetWidth(1.f);
	m_pLine->SetAntialias(TRUE);

	return 0;
}

INT c2DLine::CleanUp()
{
	if (m_pLine != nullptr)
	{
		SAFE_RELEASE(m_pLine);
	}

	return 0;
}



INT c2DLine::Begin()
{
	m_pLine->Begin();

	return 0;
}

INT c2DLine::End()
{
	m_pLine->End();

	return 0;
}



INT c2DLine::SetWidth(FLOAT width)
{
	m_pLine->SetWidth(width);

	return 0;
}



INT c2DLine::DrawLine(FLOAT left, FLOAT top, FLOAT right, FLOAT bottom, DWORD color)
{
	D3DXVECTOR2 CamPos(0.f, 0.f);

	if (cD3DApp::Sprite.CameraCheck())
	{
		CamPos = *cSystem::Camera.Pos();
	}

	D3DXVECTOR2 VtxList[2] =
	{
		D3DXVECTOR2(left, top) - CamPos
		, 	D3DXVECTOR2(right, bottom) - CamPos
	};

	m_pLine->Draw(VtxList, 2, color);

	return 0;
}

INT c2DLine::DrawLine(const D3DXVECTOR2* pVtx1, const D3DXVECTOR2* pVtx2, DWORD color)
{
	return DrawLine(pVtx1->x, pVtx1->y, pVtx2->x, pVtx2->y, color);
}

INT c2DLine::DrawLine(D3DXVECTOR2 vtxList[], UINT vtxNum, DWORD color)
{
	D3DXVECTOR2 CamPos(0.f, 0.f);

	if (cD3DApp::Sprite.CameraCheck())
	{
		CamPos = *cSystem::Camera.Pos();
	}

	D3DXVECTOR2* VtxList = new D3DXVECTOR2[vtxNum];

	for (UINT i = 0; i < vtxNum; i++)
	{
		VtxList[i] = vtxList[i] - CamPos;
	}

	m_pLine->Draw(VtxList, vtxNum, color);

	return 0;
}



INT c2DLine::RenderLine(FLOAT left, FLOAT top, FLOAT right, FLOAT bottom, DWORD color)
{
	Begin();
	DrawLine(left, top, right, bottom, color);
	End();

	return 0;
}

INT c2DLine::RenderLine(const D3DXVECTOR2* pVtx1, const D3DXVECTOR2* pVtx2, DWORD color)
{
	Begin();
	DrawLine(pVtx1, pVtx2, color);
	End();

	return 0;
}

INT c2DLine::RenderLine(D3DXVECTOR2 vtxList[], UINT vtxNum, DWORD color)
{
	Begin();
	DrawLine(vtxList, vtxNum, color);
	End();

	return 0;
}