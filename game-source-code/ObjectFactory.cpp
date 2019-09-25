#include <ObjectFactory.h>

template<typename A, typename B>
void loadObjects(std::vector<std::shared_ptr<A>> &upObjects,
		std::vector<std::shared_ptr<A>> &downObjects,
		std::vector<std::shared_ptr<B>> &AllObjects)
{
	for (auto &i : upObjects)
		AllObjects.push_back(i);

	for (auto &i : downObjects)
		AllObjects.push_back(i);
}

ObjectFactory::ObjectFactory()
{
	initializeObjects();
}

void ObjectFactory::initializeObjects()
{
	up_player_ = std::make_shared<Player>(Orientation::FACE_UP);
	down_player_ = std::make_shared<Player>(Orientation::FACE_DOWN);
	up_armada_ = std::make_shared<Armada>(Orientation::FACE_UP);
	down_armada_ = std::make_shared<Armada>(Orientation::FACE_DOWN);
	up_barriers_ = std::make_shared<BarrierFactory>(Orientation::FACE_UP);
	down_barriers_ = std::make_shared<BarrierFactory>(Orientation::FACE_DOWN);
	up_lives_ = std::make_shared<LifeFactory>(Orientation::FACE_UP,
			up_player_->getLives());
	down_lives_ = std::make_shared<LifeFactory>(Orientation::FACE_DOWN,
			down_player_->getLives());
}

void ObjectFactory::getMovingObjects(vec_of_moving_object_ptrs &movingObjects)
{
	vec_of_object_ptrs objects;
	getPlayers(movingObjects, objects);
	getAliens(movingObjects, objects);
	getPlayerBullets(movingObjects, objects);
	getAlienBullets(movingObjects, objects);
}

void ObjectFactory::getAllObjects(vec_of_object_ptrs &objects)
{
	vec_of_moving_object_ptrs movingObjects;
	getPlayers(movingObjects, objects);
	getAliens(movingObjects, objects);
	getPlayerBullets(movingObjects, objects);
	getAlienBullets(movingObjects, objects);
	getGlyphs(objects);
	getBarriers(objects);
}

void ObjectFactory::getGlyphs(vec_of_object_ptrs &objects)
{
	up_lives_->manageLives(up_player_->getLives());
	down_lives_->manageLives(down_player_->getLives());
	auto upLives = up_lives_->getGlyphs();
	auto downLives = down_lives_->getGlyphs();
	loadObjects(upLives,downLives,objects);
}

void ObjectFactory::getBarriers(vec_of_object_ptrs &objects)
{
	auto upBarriers = up_barriers_->getBarriers();
	auto downBarriers = down_barriers_->getBarriers();
	loadObjects(upBarriers,downBarriers,objects);
}

void ObjectFactory::getPlayers(vec_of_moving_object_ptrs &movingObjects, vec_of_object_ptrs &objects)
{
	movingObjects.push_back(up_player_);
	movingObjects.push_back(down_player_);
	objects.push_back(up_player_);
	objects.push_back(down_player_);
}

void ObjectFactory::getAliens(vec_of_moving_object_ptrs &movingObjects, vec_of_object_ptrs &objects)
{
	auto upAliens = up_armada_->getArmada();
	auto downAliens = down_armada_->getArmada();
	loadObjects(upAliens,downAliens,movingObjects);
	loadObjects(upAliens,downAliens,objects);
}

void ObjectFactory::getPlayerBullets(vec_of_moving_object_ptrs &movingObjects, vec_of_object_ptrs &objects)
{
	auto upPlayerBullets = up_player_->getShotsFired();
	auto downPlayerBullets = down_player_->getShotsFired();
	loadObjects(upPlayerBullets,downPlayerBullets,movingObjects);
	loadObjects(upPlayerBullets,downPlayerBullets,objects);
}

void ObjectFactory::getAlienBullets(vec_of_moving_object_ptrs &movingObjects, vec_of_object_ptrs &objects)
{
	auto upAlienBullets = up_armada_->getOnslaught();
	auto downAlienBullets = down_armada_->getOnslaught();
	loadObjects(upAlienBullets,downAlienBullets,movingObjects);
	loadObjects(upAlienBullets,downAlienBullets,objects);
}

bool ObjectFactory::gameOverStatus() const
{
	return (!(up_player_->getStatus()) || !(down_player_->getStatus())
			|| up_armada_->isGameOver() || down_armada_->isGameOver());
}

bool ObjectFactory::gameWonStatus() const
{
	return (up_armada_->isArmadaEmpty() && down_armada_->isArmadaEmpty());
}

void ObjectFactory::changePlayerDirections(std::vector<bool> &inputs)
{
	vec_of_object_ptrs barriers;
	getBarriers(barriers);
	player_input_handler_.changePlayerDirections(up_player_, down_player_,
			inputs, barriers);
}

void ObjectFactory::checkPlayer()
{
	if (up_player_->getHit())
		up_player_->resetPosition(Orientation::FACE_UP);
	else if (down_player_->getHit())
		down_player_->resetPosition(Orientation::FACE_DOWN);
}

void ObjectFactory::startPowerClock()
{
	up_player_->startClock();
	down_player_->startClock();
}

void ObjectFactory::getSizes(map_of_two_floats &sizes)
{
	Player temp_player;
	Alien temp_alien;
	Bullet temp_bullet;
	PiercerBullet temp_piercer;
	PlayerGlyph temp_glyph;
	Barrier temp_barrier;

	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::PLAYER, temp_player.getSize()));
	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::ALIEN, temp_alien.getSize()));
	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::PLAYER_BULLET, temp_bullet.getSize()));
	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::PIERCER_BULLET, temp_piercer.getSize()));
	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::PLAYER_GLYPH, temp_glyph.getSize()));
	sizes.insert(std::pair<ObjectType, two_floats>(ObjectType::BARRIER, temp_barrier.getSize()));
}
