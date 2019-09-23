#include <PlayerInputHandler.h>

PlayerInputHandler::PlayerInputHandler()
{
	resetInputs();
	stopwatch1_.start();
	stopwatch2_.start();
}

void PlayerInputHandler::resetInputs()
{
	moveUpPlayerLeft_ = false;
	moveUpPlayerRight_ = false;
	moveUpPlayerUp_ = false;
	moveUpPlayerDown_ = false;
	moveDownPlayerLeft_ = false;
	moveDownPlayerRight_ = false;
	moveDownPlayerUp_ = false;
	moveDownPlayerDown_ = false;
	upPlayerShoots_ = false;
	downPlayerShoots_ = false;

}

void PlayerInputHandler::multiPlayerInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveUpPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		moveUpPlayerRight_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		moveUpPlayerUp_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		moveUpPlayerDown_ = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		moveDownPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		moveDownPlayerRight_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		moveDownPlayerUp_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveDownPlayerDown_ = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			&& stopwatch1_.getTimeElapsed()
					> Constants::TIME_BETWEEN_PLAYER_SHOTS)
	{
		upPlayerShoots_ = true;
		stopwatch1_.start();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
			&& stopwatch2_.getTimeElapsed()
					> Constants::TIME_BETWEEN_PLAYER_SHOTS)
	{
		downPlayerShoots_ = true;
		stopwatch2_.start();
	}
}

void PlayerInputHandler::singlePlayerMirroredInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveUpPlayerLeft_ = true;
		moveDownPlayerLeft_ = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveUpPlayerRight_ = true;
		moveDownPlayerRight_ = true;
	}

	singlePlayerShooting();
}

void PlayerInputHandler::singlePlayerInvertedInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveUpPlayerLeft_ = true;
		moveDownPlayerRight_ = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveUpPlayerRight_ = true;
		moveDownPlayerLeft_ = true;
	}

	singlePlayerShooting();
}

std::vector<bool> PlayerInputHandler::getInputs()
{
	return
	{	moveUpPlayerLeft_, moveUpPlayerRight_, moveUpPlayerUp_, moveUpPlayerDown_, moveDownPlayerLeft_,
		moveDownPlayerRight_, moveDownPlayerUp_, moveDownPlayerDown_, upPlayerShoots_, downPlayerShoots_};
}

void PlayerInputHandler::singlePlayerShooting()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			&& stopwatch1_.getTimeElapsed()
					> Constants::TIME_BETWEEN_PLAYER_SHOTS)
	{
		upPlayerShoots_ = true;
		downPlayerShoots_ = true;
		stopwatch1_.start();
	}
}
