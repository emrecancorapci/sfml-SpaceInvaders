#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"

using namespace sf;
using namespace std;

class Screen;

class InputHandler
{
private:
	Screen* _parentScreen;
	vector<shared_ptr<Button>> _buttons;
	View* _pointerToUIPanelView;
	ScreenManagerRemoteControl* _smrc;
public:
	void init(ScreenManagerRemoteControl* smrc,
		vector<shared_ptr<Button>> buttons,
		View* pointerToUIView,
		Screen* parentScreen);
	void handleInput(RenderWindow& window, Event& event);

	virtual void handleGamepad();
	virtual void handleKeyPressed(Event& event, RenderWindow& window);
	virtual void handleKeyReleased(Event& event, RenderWindow& window);
	virtual void handleLeftClick(string& buttonInteractedWith, RenderWindow& window);

	View* getPointerToUIView() const;

	ScreenManagerRemoteControl* getPointerToSMRC() const;
	Screen* getParentScreen() const;
};

