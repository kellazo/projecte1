#pragma once

class Application;

class Module
{
private :
	bool enabled;

public:
	Application* App;

	Module(Application* parent, bool start_enabled = true) : App(parent), enabled(start_enabled)
	{}

	bool IsEnabled() const
	{
		return enabled;
	}

	void Enable()
	{
		if(enabled == false)
		{
			enabled = true;
			Start();
		}
	}

	void Disable()
	{
		// TODO 0: Cridar al CleanUp() al fer un Disable
	}

	virtual bool Init() 
	{
		return true; 
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}
};