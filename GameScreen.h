#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "ScreenManager.h"

class GameScreen:public Screen
{

public:
	GameScreen(ScreenManager screenManager, Vector2i resolution);
};

