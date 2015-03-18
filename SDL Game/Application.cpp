#pragma once
#include "Application.h"

Application::Application()
{
	ModuleDummy* pDummy = new ModuleDummy();
	ModuleWindow* pWindow = new ModuleWindow();

	AddModule(pDummy);
	AddModule(pWindow);
}

bool Application::Init()
{
	bool ret = true;
	p2List_item<Module*>* item = list_modules.getFirst();

	while(item != NULL && ret == true)
	{
		ret = item->data->Init();
		item = item->next;
	}

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
	p2List_item<Module*>* item = list_modules.getFirst();

	while(item != NULL && ret == UPDATE_CONTINUE)
	{
		ret = item->data->Update();
		item = item->next;
	}

	// TODO: fer que torni false si algun Init torna false
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;
	p2List_item<Module*>* item = list_modules.getLast();

	while(item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->prev;
	}
	return ret;
}

void Application::AddModule(Module* mod)
{
	list_modules.add(mod);
}