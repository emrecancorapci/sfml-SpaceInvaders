#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "InputHandler.h"
#include "UIPanel.h"
#include "Button.h"

#include "ScreenManagerRemoteControl.h"

using namespace sf;

class Screen
{
private:
	vector<shared_ptr<InputHandler>> inputHandlers;
	vector<unique_ptr<UIPanel>> panels;

protected:
	void addPanel(unique_ptr<UIPanel> panel,
		ScreenManagerRemoteControl* smrc,
		shared_ptr<InputHandler> inputHandler);
public:
	virtual void init();
	void virtual update(float fps);
	void virtual draw(RenderWindow& window);
	void handleInput(RenderWindow window);

	View view;
};

