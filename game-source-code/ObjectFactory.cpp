#include <ObjectFactory.h>

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
	up_lives_ = std::make_shared<LifeFactory>(Orientation::FACE_UP,
			up_player_->getLives());
	down_lives_ = std::make_shared<LifeFactory>(Orientation::FACE_DOWN,
			down_player_->getLives());
}

void ObjectFactory::getMovingObjects(vec_of_moving_objects &objects)
{
	getPlayers(objects);
	getAliens(objects);
	getPlayerBullets(objects);
	getAlienBullets(objects);
}

void ObjectFactory::getStaticObjects(vec_of_static_objects &objects)
{
	getGlyphs(objects);
}

void ObjectFactory::getGlyphs(vec_of_static_objects &objects)
{
	up_lives_->manageLives(up_player_->getLives());
	down_lives_->manageLives(down_player_->getLives());

	auto upLives = up_lives_->getGlyphs();
	auto downLives = down_lives_->getGlyphs();

	for (auto &i : upLives)
		objects.push_back(i);

	for (auto &i : downLives)
		objects.push_back(i);
}

void ObjectFactory::getPlayers(vec_of_moving_objects &objects)
{
	objects.push_back(up_player_);
	objects.push_back(down_player_);
}

void ObjectFactory::getAliens(vec_of_moving_objects &objects)
{
	auto upAliens = up_armada_->getArmada();
	auto downAliens = down_armada_->getArmada();

	for (auto &i : upAliens)
		objects.push_back(i);

	for (auto &i : downAliens)
		objects.push_back(i);
}

void ObjectFactory::getPlayerBullets(vec_of_moving_objects &objects)
{
	auto upPlayerBullets = up_player_->getShotsFired();
	auto downPlayerBullets = down_player_->getShotsFired();

	for (auto &i : upPlayerBullets)
		objects.push_back(i);

	for (auto &i : downPlayerBullets)
		objects.push_back(i);
}

void ObjectFactory::getAlienBullets(vec_of_moving_objects &objects)
{
	auto upAlienBullets = up_armada_->getOnslaught();
	auto downAlienBullets = down_armada_->getOnslaught();

	for (auto &i : upAlienBullets)
		objects.push_back(i);

	for (auto &i : downAlienBullets)
		objects.push_back(i);
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
	player_input_handler_.changePlayerDirections(up_player_, down_player_,
			inputs);
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

void ObjectFactory::getSizes(map_of_two_floats & sizes)
{
	Player temp_player;
	Alien temp_alien;
	Bullet temp_bullet;
	PiercerBullet temp_piercer;
	PlayerGlyph temp_glyph;

	sizes.insert(std::pair<ObjectType,two_floats>(ObjectType::PLAYER,temp_player.getSize()));
	sizes.insert(std::pair<ObjectType,two_floats>(ObjectType::ALIEN,temp_alien.getSize()));
	sizes.insert(std::pair<ObjectType,two_floats>(ObjectType::PLAYER_BULLET,temp_bullet.getSize()));
	sizes.insert(std::pair<ObjectType,two_floats>(ObjectType::PIERCER_BULLET,temp_piercer.getSize()));
	sizes.insert(std::pair<ObjectType,two_floats>(ObjectType::PLAYER_GLYPH,temp_glyph.getSize()));
}
