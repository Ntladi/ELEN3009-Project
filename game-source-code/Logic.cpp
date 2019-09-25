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
	vec_of_object_ptrs all_objects;
	object_factory_.getAllObjects(all_objects);

	for (auto &i : all_objects)
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
	vec_of_moving_object_ptrs moving_objects;
	object_factory_.getMovingObjects(moving_objects);

	for (auto &i : moving_objects)
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
	vec_of_object_ptrs all_objects;
	object_factory_.getAllObjects(all_objects);
	collision_handler_.handlecollisions(all_objects);
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


