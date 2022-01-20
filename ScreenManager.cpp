#include "ScreenManager.h"

ScreenManager::ScreenManager(Vector2i resolution)
{
	screens["Game"] = unique_ptr<GameScreen>(new GameScreen(this, resolution));
	screens["Select"] = unique_ptr<SelectScreen>(new SelectScreen(this, resolution));
}

void ScreenManager::handleInput(RenderWindow& window)
{
	screens[_currentScreen]->handleInput(window);
}

void ScreenManager::update(float fps)
{
	screens[_currentScreen]->update(fps);
}

void ScreenManager::draw(const RenderWindow& window)
{
	screens[_currentScreen]-> draw(window);
}



