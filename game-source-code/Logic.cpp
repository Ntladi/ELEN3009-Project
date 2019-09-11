#include <Logic.h>

Logic::Logic()
{
	presentation_.createWindow();
	initializeObjects();
	stopwatch_.start();
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

	auto objects = objectVector();

	for (auto &i : objects)
		moveObject(i);
}

void Logic::process(std::vector<bool> &inputs)
{
	changePlayerDirections(inputs);
	moveAllObjects();
	checkColisions();

	loadPositions();
}

void Logic::moveAllObjects()
{
	auto objects = objectVector();

	for (auto &i : objects)
		i->move();

}
void Logic::run()
{
	reset();
	while (presentation_.isWindowOpen())
	{
		stopwatch_.start();
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

std::vector<std::shared_ptr<IEntity> > Logic::objectVector()
{
	auto upPlayerBullets = upPlayer_->getShotsFired();
	auto downPlayerBullets = downPlayer_->getShotsFired();
	auto upAliens = upArmada_->getArmada();
	auto downAliens = downArmada_->getArmada();
	auto upAlienBullets = upArmada_->getOnslaught();
	auto downAlienBullets = downArmada_->getOnslaught();

	auto objects = vec_of_objects
	{ upPlayer_, downPlayer_ };

	for (auto &i : upAliens)
		objects.push_back(i);

	for (auto &i : downAliens)
		objects.push_back(i);

	for (auto &i : upPlayerBullets)
		objects.push_back(i);

	for (auto &i : downPlayerBullets)
		objects.push_back(i);

	for (auto &i : upAlienBullets)
		objects.push_back(i);

	for (auto &i : downAlienBullets)
		objects.push_back(i);

	return objects;
}
