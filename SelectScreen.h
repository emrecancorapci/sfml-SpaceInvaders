#pragma once
#include "Screen.h"
#include "ScreenManager.h"

class SelectScreen:public Screen
{

public:
	SelectScreen(ScreenManager screenManager, Vector2i resolution);
};

