#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"

ModuleFadeToBlack::ModuleFadeToBlack(Application* app, bool start_enabled) :
Module(app, start_enabled),
start_time(0),
total_time(0),
fading_in(true)
{
	screen = {0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE};
}

ModuleFadeToBlack::~ModuleFadeToBlack()
{}

// Load assets
bool ModuleFadeToBlack::Start()
{
	LOG("Preparing Fade Screen");
	SDL_SetRenderDrawBlendMode(App->renderer->renderer, SDL_BLENDMODE_BLEND);
	return true;
}

// Update: draw background
update_status ModuleFadeToBlack::Update()
{
	if(start_time > 0)
	{
		Uint32 now = SDL_GetTicks() - start_time;
		float normalized = (float) now / (float) total_time;
		
		if(normalized > 1.0f)
			normalized = 1.0f;
		
		if(fading_in == false)
			normalized = 1.0f - normalized;

		SDL_SetRenderDrawColor(App->renderer->renderer, 0, 0, 0, (Uint8) (normalized * 255.0f));
		SDL_RenderFillRect(App->renderer->renderer, &screen);

		if(now >= total_time)
		{
			if(fading_in == true)
			{
				total_time += total_time;
				start_time = SDL_GetTicks();
				fading_in = false;
				// TODO 2: Fer un disable / enable dels moduls rebuts a FadeToBlack()
				off->Disable();
				on->Enable();
			}
			else
				start_time = 0;
		}
	}

	return UPDATE_CONTINUE;
}

// Fade to black. At mid point deactivate one module, then activate the other
void ModuleFadeToBlack::FadeToBlack(Module* module_off, Module* module_on, float time)
{
	fading_in = true;
	start_time = SDL_GetTicks();
	total_time = (Uint32) (time * 0.5f * 1000.0f);
	//guardem les variables
	off = module_off;
	on = module_on;

}