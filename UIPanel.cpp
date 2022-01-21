#include "UIPanel.h"

UIPanel::UIPanel(const Vector2i res, const Vector2f position,
                 const Vector2f size, const Color color)
{
	_UIPanel.setFillColor(color);
	_UIPanel.setSize(size);

	view.setSize(size);
	view.setCenter(size.x /2, size.y/2);

	// Changed
	const Vector2f viewportPosition(position.x / static_cast<float>(res.x),
	                                position.y / static_cast<float>(res.y));
	const Vector2f viewportSize(size.x / static_cast<float>(res.x),
		size.y / static_cast<float>(res.y));

	view.setViewport(FloatRect(viewportPosition, viewportSize));
}

vector<shared_ptr<Button>> UIPanel::getButtons()
{
	return _buttons;
}

void UIPanel::addButton(Vector2f position, Vector2f size, Color color, string label)
{
	_buttons.push_back(make_shared<Button>(position,size,color,label));
}

void UIPanel::draw(RenderWindow& window)
{
	window.setView(view);
	if (_hidden)
	{
		window.draw(_UIPanel);

		auto i = _buttons.begin();
		auto end = _buttons.end();

		for(i; i != end; ++i) (*i)->draw(window);
	}
}

void UIPanel::show(const bool showPanel)
{
	_hidden = !showPanel;
}
