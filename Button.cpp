#include "Button.h"

Button::Button(const Vector2f& position, const Vector2f& size,
	const Color& color, const std::string& buttonText)
{
	_button.setPosition(position);
	_button.setFillColor(color);
	_button.setSize(size);
	text = "" + buttonText;

	const Vector2f textPadding(size.x / 10, size.y / 10);

	_buttonText.setCharacterSize(size.y * .7f);
	_buttonText.setString(text);

	_font.loadFromFile("fonts/Roboto-bol.ttf");
	_buttonText.setFont(_font);
	_buttonText.setPosition(position+textPadding);

	collider = FloatRect(position, size);
}

void Button::draw(RenderWindow& window) const
{
	window.draw(_button);
	window.draw(_buttonText);
}

