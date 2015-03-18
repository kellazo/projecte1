#pragma once
#include "List.h"
#include "Globals.h"
#include "Module.h"
#include "Dummy.h"

class Application
{
public:

	p2List<Module*> list_modules;

public:

	Application()
	{
		ModuleDummy* pDummy = new ModuleDummy();

		AddModule(pDummy);
	}

	bool Init()
	{
		bool ret = true
		p2List_item<Module*>* item = list_modules.getFirst();

		while (item != NULL && ret == true)
		{
			item->data->Init();
			item = item->next;
		}

		
		
		//TODO: fer que torni false si algun Init torna false, quan torni false pasara que noslatres hem de parar, treure misatge d'error i tancar.
		return ret;
		
		}
			
	}

	int Update() { 
		Update_status ret = UPDATE_CONTINUE;

		p2List_item<Module*>* item = list_modules.getFirst();

		while (item != NULL && ret == UPDATE_CONTINUE)
		{
			item->data->Update();
			item = item->next;
		}

		//TODO: que retorni els 3 estats i el maeix amb el cleanup
		//return UPDATE_STOP;
		return ret;
	 }


	bool CleanUp() { 
		
		p2List_item<Module*>* item = list_modules.getLast();

		while (item != NULL)
		{
			item->data->CleanUp();
			item = item->prev;
		}
		
		
		return true; 
	
	}

private:

	void AddModule(Module* mod)
	{
		list_modules.add(mod);
	}
};