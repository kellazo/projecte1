#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleRender : public Module
{
	bool Init()
	{
		LOG("Render Init!");
		return true;
	}

	bool CleanUp()
	{
		LOG("Render CleanUp!");
		return true;
	}
};