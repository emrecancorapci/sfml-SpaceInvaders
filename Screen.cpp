#include "Screen.h"

void Screen::addPanel(unique_ptr<UIPanel> panel, ScreenManagerRemoteControl* smrc,
                      const shared_ptr<InputHandler> inputHandler)
{
	inputHandler->init(smrc, panel->getButtons(), &panel->view, this);
	panels.push_back(move(panel));
	inputHandlers.push_back(inputHandler);
}

void Screen::init()
{
	return;
}

void Screen::update(float fps)
{
	return;
}

void Screen::draw(RenderWindow& window)
{
	auto i = panels.begin();
	auto end = panels.end();
	for(i; i!=end; ++i)
		(*i)->draw(window);
}

void Screen::handleInput(RenderWindow window)
{
	Event event;

	auto i = inputHandlers.begin();
	auto end = inputHandlers.end();

	while (window.pollEvent(event))
	{
		for (i; i != end; ++i)
			(*i)->handleInput(window,event);
	}
}

