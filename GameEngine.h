#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "SoundEngine.h"

using namespace sf;

class GameEngine
{
private:
	Clock clock;
	Time deltaTime;
	RenderWindow window;

	std::unique_ptr<ScreenManager> screenManager;

	float FPS = 0;
	Vector2f resolution;

	void handleInput();
	void update();
	void draw();

public:
	SoundEngine soundEngine;

	GameEngine();
	void run();
};

