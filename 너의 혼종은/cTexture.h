#pragma once
#include <d3dx9.h>

class cTexture
{
public:
	cTexture();
	~cTexture();

private:
	LPDIRECT3DTEXTURE9 m_pTex;
	D3DXIMAGE_INFO m_ImgInf;

public:
	INT Create(LPCWSTR fileName);
	INT CleanUp();

public:
	INT Width() const;
	INT Height() const;

public:
	LPDIRECT3DTEXTURE9 GetTexture() const;
};