#include <ObjectFactory.h>

ObjectFactory::ObjectFactory()
{
	initializeObjects();
}

void ObjectFactory::initializeObjects()
{
	upPlayer_ = std::make_shared<Player>(Orientation::FACE_UP);
	downPlayer_ = std::make_shared<Player>(Orientation::FACE_DOWN);
	upArmada_ = std::make_shared<Armada>(Orientation::FACE_UP);
	downArmada_ = std::make_shared<Armada>(Orientation::FACE_DOWN);
}

void ObjectFactory::getObjects(vec_of_objects &objects)
{
	getPlayers(objects);
	getAliens(objects);
	getPlayerBullets(objects);
	getAlienBullets(objects);

}

void ObjectFactory::getPlayers(vec_of_objects &objects)
{
	objects.push_back(upPlayer_);
	objects.push_back(downPlayer_);
}

void ObjectFactory::getAliens(vec_of_objects &objects)
{
	auto upAliens = upArmada_->getArmada();
	auto downAliens = downArmada_->getArmada();

	for (auto &i : upAliens)
		objects.push_back(i);

	for (auto &i : downAliens)
		objects.push_back(i);
}

void ObjectFactory::getPlayerBullets(vec_of_objects &objects)
{
	auto upPlayerBullets = upPlayer_->getShotsFired();
	auto downPlayerBullets = downPlayer_->getShotsFired();

	for (auto &i : upPlayerBullets)
		objects.push_back(i);

	for (auto &i : downPlayerBullets)
		objects.push_back(i);
}

void ObjectFactory::getAlienBullets(vec_of_objects &objects)
{
	auto upAlienBullets = upArmada_->getOnslaught();
	auto downAlienBullets = downArmada_->getOnslaught();

	for (auto &i : upAlienBullets)
		objects.push_back(i);

	for (auto &i : downAlienBullets)
		objects.push_back(i);
}

bool ObjectFactory::gameOverStatus() const
{
	return (!(upPlayer_->getStatus()) || !(downPlayer_->getStatus())
			|| upArmada_->isGameOver() || downArmada_->isGameOver());
}

bool ObjectFactory::gameWonStatus() const
{
	return (upArmada_->isArmadaEmpty() && downArmada_->isArmadaEmpty());
}

void ObjectFactory::changePlayerDirections(std::vector<bool> &inputs)
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

