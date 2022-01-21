#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "ScreenManagerRemoteControl.h"
#include "GameScreen.h"
#include "SelectScreen.h"
#include "BitmapStore.h"
#include "LevelManager.h"

using namespace sf;
using namespace std;

class ScreenManager : public ScreenManagerRemoteControl
{
private:
	map<string, unique_ptr<Screen>> screens;
	LevelManager levelManager;

protected:
	string _currentScreen = "Select";

public:
	BitmapStore bitmapStore;

	ScreenManager(Vector2i resolution);

	void handleInput(RenderWindow& window);
	void update(float fps);
	void draw(const RenderWindow& window);

	void ScreenManagerRemoteControl::switchScreens(string screenToSwitch) override;
	void ScreenManagerRemoteControl::loadLevelInPlayMode(string screenToLoad) override;

	vector<GameObject>& ScreenManagerRemoteControl::getGameObjects();

	/*
	GameObjectSharer& shareGameObjectSharer()
	{
		return levelManager;
	}
	*/
};

