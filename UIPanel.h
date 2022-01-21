#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace std;

class UIPanel
{
private:
	RectangleShape _UIPanel;
	vector<shared_ptr<Button>> _buttons;

	bool _hidden = false;

protected:
	Vector2f _buttonSize;
	float _buttonPadding;

	Font _font;
	Text _text;

	void addButton(Vector2f position, Vector2f size,
		Color color, string label);

public:
	View view;
	UIPanel(Vector2i res, Vector2f position, Vector2f size, Color color);

	vector<shared_ptr<Button>> getButtons();
	virtual void draw(RenderWindow& window);
	void show(bool showPanel);
};

