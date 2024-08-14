#include "cD3DApp.h"



cDevice cD3DApp::Device;
cSprite cD3DApp::Sprite;



cD3DApp::cD3DApp()
{
}

cD3DApp::~cD3DApp()
{
	CleanUp();
}



INT cD3DApp::Init(BOOL bWindowed)
{
	Device.Create(bWindowed);
	Sprite.Create();

	return 0;
}

INT cD3DApp::CleanUp()
{
	Sprite.CleanUp();
	Device.CleanUp();

	return 0;
}