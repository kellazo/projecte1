#pragma once

class Module
{
public:

	virtual bool Init() { return true; }
	virtual update_status Update()
	{
		return UPDATE_CONTINUE;
	}
	virtual bool CleanUp() { return true; }
};