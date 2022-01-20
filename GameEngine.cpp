#include "GameEngine.h"

VideoMode VideoModeV(const Vector2f &res)
{
	return VideoMode(res.x, res.y);
}

GameEngine::GameEngine()
{
	const std::string title = "Space Invaders++";

	resolution = Vector2f(VideoMode::getDesktopMode().width,
		VideoMode::getDesktopMode().height);

	window.create(VideoModeV(resolution),title, Style::Fullscreen);
	screenManager = std::unique_ptr<ScreenManager>(new ScreenManager(Vector2i(resolution)));
}

void GameEngine::run()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		FPS = deltaTime.asSeconds();

		handleInput();
		update();
		draw();
	}
}

void GameEngine::handleInput()
{
	screenManager->handleInput();
}

void GameEngine::update()
{
	screenManager->update();
}

void GameEngine::draw()
{
	window.clear(Color::Black);
	screenManager->draw(window);
	window.display();
}




