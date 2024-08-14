#include "Util.h"

#include "cTexture.h"



cTexture::cTexture()
	: m_pTex(nullptr)
{
}

cTexture::~cTexture()
{
	CleanUp();
}



INT cTexture::Create(LPCWSTR fileName)
{
	D3DXGetImageInfoFromFileW(fileName, &m_ImgInf);

	HRESULT result;

	if (FAILED(result = D3DXCreateTextureFromFileExW(
		cD3DApp::Device.GetDevice()
		, fileName
		, m_ImgInf.Width
		, m_ImgInf.Height
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, D3DX_FILTER_NONE
		, D3DX_FILTER_NONE
		, 0x00000000
		, &m_ImgInf
		, nullptr
		, &m_pTex)))
	{
		return Util::ErrorMessage(fileName);
	}

	return 0;
}

INT cTexture::CleanUp()
{
	if (m_pTex != nullptr)
	{
		SAFE_RELEASE(m_pTex);
	}

	return 0;
}



INT cTexture::Width() const
{
	return m_ImgInf.Width;
}

INT cTexture::Height() const
{
	return m_ImgInf.Height;
}



LPDIRECT3DTEXTURE9 cTexture::GetTexture() const
{
	return m_pTex;
}