#pragma once
#include <Windows.h>

#define LOG(txt) OutputDebugString(txt)

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};
