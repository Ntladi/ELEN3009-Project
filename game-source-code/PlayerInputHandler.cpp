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
	moveDownPlayerLeft_ = false;
	moveDownPlayerRight_ = false;
	upPlayerShoots_ = false;
	downPlayerShoots_ = false;

}

void PlayerInputHandler::multiPlayerInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveUpPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		moveUpPlayerRight_ = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveDownPlayerLeft_ = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
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
	{	moveUpPlayerLeft_, moveUpPlayerRight_, moveDownPlayerLeft_,
		moveDownPlayerRight_, upPlayerShoots_, downPlayerShoots_};
}

void PlayerInputHandler::singlePlayerShooting()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			&& stopwatch1_.getTimeElapsed()
					> Constants::SECONDS_BETWEEN_PLAYER_SHOTS)
	{
		upPlayerShoots_ = true;
		downPlayerShoots_ = true;
		stopwatch1_.start();
	}
}
