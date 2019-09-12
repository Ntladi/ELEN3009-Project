#include <Presentation.h>
#include "Constants.h"
Presentation::Presentation()
{
	resetInputs();
	stopwatch1_.start();
	stopwatch2_.start();
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

void Presentation::moveSprite(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{

	switch (object)
	{
	case ObjectType::PLAYER:
		sprites_.movePlayer(orientation, position);
		break;
	case ObjectType::ALIEN:
		sprites_.moveAlien(orientation, position);
		break;
	case ObjectType::PLAYER_BULLET:
		sprites_.movePlayerBullet(orientation, position);
		break;
	case ObjectType::ALIEN_BULLET:
		sprites_.moveAlienBullet(orientation, position);
		break;
	default:
		break;
	}

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
		{
			screen_state_ = ScreenStates::GAME_SCREEN;
			game_mode_ = GameModes::SINGLE_PLAYER;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			screen_state_ = ScreenStates::GAME_SCREEN;
			game_mode_ = GameModes::MULTI_PLAYER;
		}
	}
	else if (screen_state_ == ScreenStates::GAME_OVER)
		window_->close();
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
	resetInputs();

	if(game_mode_ == GameModes::SINGLE_PLAYER)
		singlePlayerInputs();

	return
	{	moveUpPlayerLeft_, moveUpPlayerRight_, moveDownPlayerLeft_,
		moveDownPlayerRight_, upPlayerShoots_, downPlayerShoots_};

}

ScreenStates Presentation::getScreenstate() const
{
	return screen_state_;
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
}

void Presentation::resetInputs()
{
	moveUpPlayerLeft_ = false;
	moveUpPlayerRight_ = false;
	moveDownPlayerLeft_ = false;
	moveDownPlayerRight_ = false;
	upPlayerShoots_ = false;
	downPlayerShoots_ = false;
}

void Presentation::setGameOver()
{
	screen_state_ = ScreenStates::GAME_OVER;
}

void Presentation::setGameWon()
{
	screen_state_ = ScreenStates::GAME_WON;
}

void Presentation::singlePlayerInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveUpPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		moveUpPlayerRight_ = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveDownPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveDownPlayerRight_ = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			&& stopwatch1_.getTimeElapsed()
					> Constants::SECONDS_BETWEEN_PLAYER_SHOTS)
	{
		upPlayerShoots_ = true;
		stopwatch1_.start();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
			&& stopwatch2_.getTimeElapsed()
					> Constants::SECONDS_BETWEEN_PLAYER_SHOTS)
	{
		downPlayerShoots_ = true;
		stopwatch2_.start();
	}
}

void Presentation::multiPlayerInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveUpPlayerLeft_ = true;
		moveDownPlayerLeft_ = true;
	}
}
