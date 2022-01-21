#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
private:
	RectangleShape _button;
	Text _buttonText;
	Font _font;

public:
	std::string text;
	FloatRect collider;

	Button(const Vector2f& position, const Vector2f& size,
		const Color& color, const std::string& buttonText);
	void draw(RenderWindow& window) const;
};

