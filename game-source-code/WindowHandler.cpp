#include <WindowHandler.h>

void WindowHandler::clearWindow(ScreenStates & state, window_ptr & window)
{
	window->clear(sf::Color::White);

	if (state == ScreenStates::SPLASHSCREEN)
		window->draw(backgrounds_.getSplashScreen());
	if (state == ScreenStates::GAME_SCREEN)
		window->draw(backgrounds_.getBackgroundScreen());
	if (state == ScreenStates::GAME_OVER)
		window->draw(backgrounds_.getGameOverScreen());
	if (state == ScreenStates::GAME_WON)
		window->draw(backgrounds_.getGameWonScreen());
}

void WindowHandler::createWindow(window_ptr & window)
{
	window->create(
			sf::VideoMode(Constants::SCREEN_X_LENGTH,
					Constants::SCREEN_Y_LENGTH), "Dual Invaders",
			sf::Style::Close);
	window->setFramerateLimit(60);
}

bool WindowHandler::events(window_ptr & window)
{
	bool isPressed = false;
	sf::Event evnt;

	while (window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			isPressed = true;
			break;
		default:
			break;
		}
	}
	return isPressed;
}
