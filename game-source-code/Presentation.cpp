#include <Presentation.h>
#include "Constants.h"
#include <iostream>

Presentation::Presentation()
{
	game_mode_ = GameModes::NONE;
	screen_state_ = ScreenStates::SPLASHSCREEN;
	window_ = std::make_shared<sf::RenderWindow>();
	window_handler_.createWindow(window_);
}

void Presentation::initializeSpriteSizes(const map_of_two_floats &sizes)
{
	sprites_.setInitialSizes(sizes);
}

bool Presentation::isPlaying() const
{
	return screen_state_ == ScreenStates::GAME_SCREEN;
}

void Presentation::drawObject(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{
	sprites_.displaySprite(object,orientation,position);
	sprites_.drawLatestObject(window_);
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
	if (window_handler_.events(window_))
		checkPressed();

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
	auto score = score_.getScore(screen_state_);
	auto high_score = score_.getHighScore(screen_state_);
	window_handler_.clearWindow(screen_state_,window_, score, high_score);
}

void Presentation::setGameOver()
{
	screen_state_ = ScreenStates::GAME_OVER;
}

void Presentation::setGameWon()
{
	screen_state_ = ScreenStates::GAME_WON;
}

void Presentation::drawScore(const int & score)
{
	score_.setScore(score);
}

