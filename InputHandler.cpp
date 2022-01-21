#include "InputHandler.h"
#include <sstream>
#include <utility>

using namespace sf;
using namespace std;

void InputHandler::init(ScreenManagerRemoteControl* smrc,
	vector<shared_ptr<Button>> buttons,
	View* pointerToUIView, Screen* parentScreen)
{
	_smrc = smrc;
	_buttons = std::move(buttons);
	_pointerToUIPanelView = pointerToUIView;
	_parentScreen = parentScreen;

}

void InputHandler::handleInput(RenderWindow& window, Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		handleKeyPressed(event, window);
	}
	if (event.type == Event::KeyReleased)
	{
		handleKeyReleased(event, window);
	}
	if (event.type == Event::MouseButtonReleased)
	{
		auto i = _buttons.begin();
		const auto end = _buttons.end();

		for(i; i!= end; ++i)
		{
			const Vector2f position = window.mapPixelToCoords(
				Mouse::getPosition(),
				(*getPointerToUIView()));

			if ((*i)->collider.contains(position));
			{
				handleLeftClick((*i)->text, window);
				break;
			}
		}
	}

	handleGamepad();
}

void InputHandler::handleGamepad()
{
	return;
}

void InputHandler::handleKeyPressed(Event& event, RenderWindow& window)
{
	return;
}

void InputHandler::handleLeftClick(string& buttonInteractedWith, RenderWindow& window)
{
	return;
}

View* InputHandler::getPointerToUIView() const
{
	return _pointerToUIPanelView;
}

ScreenManagerRemoteControl* InputHandler::getPointerToSMRC() const
{
	return _smrc;
}

Screen* InputHandler::getParentScreen() const
{
	return _parentScreen;
}


