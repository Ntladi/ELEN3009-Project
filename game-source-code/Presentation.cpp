#include <Presentation.h>
#include "Constants.h"
Presentation::Presentation()
{
	game_mode_ = GameModes::NONE;
	screen_state_ = ScreenStates::SPLASHSCREEN;
}

void Presentation::createWindow()
{
	window_ = std::make_shared<sf::RenderWindow>();
	window_->create(
			sf::VideoMode(Constants::SCREEN_X_LENGTH,
					Constants::SCREEN_Y_LENGTH), "Dual Invaders",
			sf::Style::Close);
}

void Presentation::initializeSpriteSizes(const vec_of_two_floats &sizes)
{
	sprites_.setInitialSizes(sizes);
}

bool Presentation::isPlaying() const
{
	return screen_state_ == ScreenStates::GAME_SCREEN;
}

void Presentation::moveSprite(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{

	sprites_.moveSprite(object,orientation,position);
	sprites_.drawLatestObject(window_);
}

void Presentation::events()
{
	sf::Event evnt;

	while (window_->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window_->close();
			break;
		case sf::Event::KeyPressed:
			checkPressed();
			break;
		default:
			break;
		}
	}
}

void Presentation::checkPressed()
{
	if (screen_state_ == ScreenStates::SPLASHSCREEN)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			game_mode_ = GameModes::MULTI_PLAYER;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			game_mode_ = GameModes::SINGLE_PLAYER_INVERTED;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			game_mode_ = GameModes::SINGLE_PLAYER_MIRRORED;
		if (game_mode_ != GameModes::NONE)
			screen_state_ = ScreenStates::GAME_SCREEN;
	}
	else if (screen_state_ == ScreenStates::GAME_OVER
			|| screen_state_ == ScreenStates::GAME_WON)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			window_->close();
	}
}

bool Presentation::isWindowOpen()
{
	return window_->isOpen();
}

void Presentation::displayWindow()
{
	window_->display();
}

std::vector<bool> Presentation::checkInputs()
{
	events();
	player_input_handler_.resetInputs();

	if (game_mode_ == GameModes::SINGLE_PLAYER_MIRRORED)
		player_input_handler_.singlePlayerMirroredInputs();
	else if (game_mode_ == GameModes::SINGLE_PLAYER_INVERTED)
		player_input_handler_.singlePlayerInvertedInputs();
	else if (game_mode_ == GameModes::MULTI_PLAYER)
		player_input_handler_.multiPlayerInputs();

	return player_input_handler_.getInputs();
}

void Presentation::clearWindow()
{
	window_->clear(sf::Color::White);

	if (screen_state_ == ScreenStates::SPLASHSCREEN)
		window_->draw(backgrounds_.getSplashScreen());
	if (screen_state_ == ScreenStates::GAME_SCREEN)
		window_->draw(backgrounds_.getBackgroundScreen());
	if (screen_state_ == ScreenStates::GAME_OVER)
		window_->draw(backgrounds_.getGameOverScreen());
	if (screen_state_ == ScreenStates::GAME_WON)
		window_->draw(backgrounds_.getGameWonScreen());
}

void Presentation::setGameOver()
{
	screen_state_ = ScreenStates::GAME_OVER;
}

void Presentation::setGameWon()
{
	screen_state_ = ScreenStates::GAME_WON;
}
