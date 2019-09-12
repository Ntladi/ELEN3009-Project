#include <Logic.h>
#include <iostream>

Logic::Logic()
{
	presentation_.createWindow();
	initializeObjects();
}

void Logic::loadInitialPositions()
{
	initializeObjects();
	loadPositions();
}

void Logic::loadInitialSizes()
{
	initializeObjects();
	loadSizes();
}

void Logic::loadSizes()
{
	vec_of_two_floats sizes;
	sizes.clear();
	auto bulletSize = Parameters
	{ ObjectType::PLAYER_BULLET };
	sizes.push_back(upPlayer_->getSize());
	sizes.push_back(upArmada_->getAlienSize());
	auto bullet_size = two_floats
	{ bulletSize.getXLength(), bulletSize.getYHeight() };
	sizes.push_back(bullet_size);
	presentation_.initializeSpriteSizes(sizes);

}

void Logic::reset()
{
	loadInitialSizes();
	loadInitialPositions();

}

void Logic::loadPositions()
{

	vec_of_objects objects;
	getObjects(objects);

	for (auto &i : objects)
		moveObject(i);
}

void Logic::process(std::vector<bool> &inputs)
{
	changePlayerDirections(inputs);
	moveAllObjects();

	loadPositions();
	checkColisions();
	checkGameOver();

}

void Logic::moveAllObjects()
{
	vec_of_objects objects;
	getObjects(objects);

	for (auto &i : objects)
		i->move();

}
void Logic::run()
{
	reset();
	while (presentation_.isWindowOpen())
	{
		presentation_.clearWindow();
		auto inputs = presentation_.checkInputs();

		if (presentation_.getScreenstate() == ScreenStates::GAME_SCREEN)
			process(inputs);
		presentation_.displayWindow();
	}
}

void Logic::moveObject(std::shared_ptr<IEntity> &object)
{
	presentation_.moveSprite(object->getObjectType(), object->getOrientation(),
			object->getPosition());
}

void Logic::initializeObjects()
{
	upPlayer_ = std::make_shared<Player>(Orientation::FACE_UP);
	downPlayer_ = std::make_shared<Player>(Orientation::FACE_DOWN);
	upArmada_ = std::make_shared<Armada>(Orientation::FACE_UP);
	downArmada_ = std::make_shared<Armada>(Orientation::FACE_DOWN);
}

void Logic::changePlayerDirections(std::vector<bool> &inputs)
{
	if (inputs.at(0))
		upPlayer_->setMoveDirection(MoveDirection::LEFT);
	else if (inputs.at(1))
		upPlayer_->setMoveDirection(MoveDirection::RIGHT);
	if (inputs.at(2))
		downPlayer_->setMoveDirection(MoveDirection::LEFT);
	else if (inputs.at(3))
		downPlayer_->setMoveDirection(MoveDirection::RIGHT);
	if (inputs.at(4))
		upPlayer_->shoot();
	if (inputs.at(5))
		downPlayer_->shoot();
}

void Logic::getObjects(vec_of_objects & objects)
{

	getPlayers(objects);

	getAliens(objects);

	getPlayerBullets(objects);

	getAlienBullets(objects);


}

void Logic::getPlayers(vec_of_objects & objects)
{
	objects.push_back(upPlayer_);
	objects.push_back(downPlayer_);
}

void Logic::getAliens(vec_of_objects & objects)
{
	auto upAliens = upArmada_->getArmada();
	auto downAliens = downArmada_->getArmada();

	for (auto &i : upAliens)
		objects.push_back(i);

	for (auto &i : downAliens)
		objects.push_back(i);
}

void Logic::getPlayerBullets(vec_of_objects & objects)
{
	auto upPlayerBullets = upPlayer_->getShotsFired();
	auto downPlayerBullets = downPlayer_->getShotsFired();

	for (auto &i : upPlayerBullets)
		objects.push_back(i);

	for (auto &i : downPlayerBullets)
		objects.push_back(i);
}

void Logic::getAlienBullets(vec_of_objects & objects)
{
	auto upAlienBullets = upArmada_->getOnslaught();
	auto downAlienBullets = downArmada_->getOnslaught();

	for (auto &i : upAlienBullets)
		objects.push_back(i);

	for (auto &i : downAlienBullets)
		objects.push_back(i);
}

void Logic::checkColisions()
{
	vec_of_objects player_bullets;
	vec_of_objects aliens;
	vec_of_objects players;
	vec_of_objects alien_bullets;
	getPlayerBullets(player_bullets);
	getAliens(aliens);
	getPlayers(players);
	getAlienBullets(alien_bullets);
	collision_handler_.handlecollisions(player_bullets,aliens,players,alien_bullets);
}

void Logic::checkGameOver()
{
	if(!(upPlayer_->getStatus()) || !(downPlayer_->getStatus()))
		presentation_.setGameOver();
	if(upArmada_->isGameOver() || downArmada_->isGameOver())
		presentation_.setGameOver();
}
