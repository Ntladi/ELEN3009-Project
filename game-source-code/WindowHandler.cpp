#include <WindowHandler.h>

void WindowHandler::clearWindow(ScreenStates &state, window_ptr &window,
		text_ptr &score, text_ptr &high_score)
{
	window->clear(sf::Color::White);

	switch (state)
	{
	case ScreenStates::SPLASHSCREEN:
		window->draw(backgrounds_.getSplashScreen());
		window->draw(*high_score);
		break;
	case ScreenStates::GAME_SCREEN:
		window->draw(backgrounds_.getBackgroundScreen());
		window->draw(*score);
		break;
	case ScreenStates::GAME_OVER:
		window->draw(backgrounds_.getGameOverScreen());
		window->draw(*score);
		window->draw(*high_score);
		break;
	case ScreenStates::GAME_WON:
		window->draw(backgrounds_.getGameWonScreen());
		window->draw(*score);
		window->draw(*high_score);
		break;
	}

}

void WindowHandler::createWindow(window_ptr &window)
{
	window->create(
			sf::VideoMode(Constants::SCREEN_X_LENGTH,
					Constants::SCREEN_Y_LENGTH), "Dual Invaders",
			sf::Style::Close);
	window->setFramerateLimit(60);
}

bool WindowHandler::events(window_ptr &window)
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
