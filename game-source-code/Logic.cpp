#include <Logic.h>
#include <iostream>

Logic::Logic()
{
	presentation_.createWindow();
}

void Logic::loadSizes()
{
	vec_of_two_floats sizes;
	sizes.clear();

	auto player_param = Parameters
	{ ObjectType::PLAYER };

	auto alien_param = Parameters
	{ ObjectType::ALIEN };

	auto bullet_param = Parameters
	{ ObjectType::PLAYER_BULLET};

	sizes.push_back(player_param.getSize());
	sizes.push_back(alien_param.getSize());
	sizes.push_back(bullet_param.getSize());
	presentation_.initializeSpriteSizes(sizes);

}

void Logic::reset()
{
	object_factory_ = ObjectFactory {};
	loadSizes();
	loadPositions();
}

void Logic::loadPositions()
{
	vec_of_moving_objects objects;
	object_factory_.getMovingObjects(objects);

	for (auto &i : objects)
		moveObject(i);
}

void Logic::process(std::vector<bool> &inputs)
{
	object_factory_.changePlayerDirections(inputs);
	moveAllObjects();
	loadPositions();
	checkColisions();
	checkGameOver();

}

void Logic::moveAllObjects()
{
	vec_of_moving_objects objects;
	object_factory_.getMovingObjects(objects);

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

		if (presentation_.isPlaying())
			process(inputs);
		presentation_.displayWindow();
	}
}

void Logic::moveObject(std::shared_ptr<IMovingEntity> &object)
{
	presentation_.moveSprite(object->getObjectType(), object->getOrientation(),
			object->getPosition());
}

void Logic::checkColisions()
{
	vec_of_moving_objects player_bullets;
	vec_of_moving_objects aliens;
	vec_of_moving_objects players;
	vec_of_moving_objects alien_bullets;
	object_factory_.getPlayerBullets(player_bullets);
	object_factory_.getAliens(aliens);
	object_factory_.getPlayers(players);
	object_factory_.getAlienBullets(alien_bullets);
	collision_handler_.handlecollisions(player_bullets, aliens, players,
			alien_bullets);
}

void Logic::checkGameOver()
{
	if (object_factory_.gameOverStatus())
		presentation_.setGameOver();
	if(object_factory_.gameWonStatus())
		presentation_.setGameWon();
}
