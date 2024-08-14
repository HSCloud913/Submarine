#include "cSequence.h"



cSequence::cSequence()
{
}

cSequence::~cSequence()
{
}



INT cSequence::Init()
{
	return OnInit();
}

INT cSequence::CleanUp()
{
	return OnCleanUp();
}

cSequence* cSequence::Update()
{
	return OnUpdate();
}

INT cSequence::Render()
{
	return OnRender();
}