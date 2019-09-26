#include <Presentation.h>
#include "Constants.h"
#include <iostream>

Presentation::Presentation()
{
	game_mode_ = GameMode::NONE;
	screen_state_ = ScreenState::SPLASHSCREEN;
	window_ = std::make_shared<sf::RenderWindow>();
	window_handler_.createWindow(window_);
}

void Presentation::initializeSpriteSizes(const map_of_two_floats &sizes)
{
	sprites_.setInitialSizes(sizes);
}

const bool Presentation::isPlaying() const
{
	return screen_state_ == ScreenState::GAME_SCREEN;
}

void Presentation::drawObject(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{
	sprites_.displaySprite(object,orientation,position);
	sprites_.drawLatestObject(window_);
}

void Presentation::setMode()
{
	if (screen_state_ == ScreenState::SPLASHSCREEN)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			game_mode_ = GameMode::MULTI_PLAYER;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			game_mode_ = GameMode::SINGLE_PLAYER_INVERTED;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			game_mode_ = GameMode::SINGLE_PLAYER_MIRRORED;
		if (game_mode_ != GameMode::NONE)
			screen_state_ = ScreenState::GAME_SCREEN;
	}
	else if (screen_state_ == ScreenState::GAME_OVER
			|| screen_state_ == ScreenState::GAME_WON)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			window_->close();
	}
}

const bool Presentation::isWindowOpen() const
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
		setMode();

	player_input_handler_.resetInputs();

	if (game_mode_ == GameMode::SINGLE_PLAYER_MIRRORED)
		player_input_handler_.singlePlayerMirroredInputs();
	else if (game_mode_ == GameMode::SINGLE_PLAYER_INVERTED)
		player_input_handler_.singlePlayerInvertedInputs();
	else if (game_mode_ == GameMode::MULTI_PLAYER)
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
	screen_state_ = ScreenState::GAME_OVER;
}

void Presentation::setGameWon()
{
	screen_state_ = ScreenState::GAME_WON;
}

void Presentation::drawScore(const int & score)
{
	score_.setScore(score);
}

