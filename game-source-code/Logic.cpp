#include <Logic.h>

Logic::Logic()
{
}

void Logic::loadSizes()
{
	map_of_two_floats sizes;
	sizes.clear();
	object_factory_.getSizes(sizes);
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
	vec_of_moving_objects moving_objects;
	object_factory_.getMovingObjects(moving_objects);

	for (auto &i : moving_objects)
		setObjects(i);

	vec_of_static_objects static_objects;
	object_factory_.getStaticObjects(static_objects);

	for (auto &i : static_objects)
		setObjects(i);
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
		else
			object_factory_.startPowerClock();
		presentation_.displayWindow();
	}
}

void Logic::setObjects(std::shared_ptr<IMovingEntity> &object)
{
	presentation_.drawObject(object->getObjectType(), object->getOrientation(),
			object->getPosition());
}

void Logic::setObjects(std::shared_ptr<IEntity> &object)
{
	presentation_.drawObject(object->getObjectType(), object->getOrientation(),
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
	object_factory_.checkPlayer();

	presentation_.drawScore(collision_handler_.getScore());
}

void Logic::checkGameOver()
{
	if (object_factory_.gameOverStatus())
		presentation_.setGameOver();
	if(object_factory_.gameWonStatus())
		presentation_.setGameWon();
}


