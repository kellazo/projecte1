#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"

ModuleRender::ModuleRender() : Module()
{
	
}


// Called before render is available
bool ModuleRender::Init()
{
	LOG("Dummy Init!");
	return true;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Dummy Cleanup!");
	return true;
}

//fer el SDL_CreateRenderer() i SDL_DestroyRenderer()  em tornara un punter i el guardem dins del modul renderer com una propietat pel divendres.