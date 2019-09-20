#include <PlayerBulletFactory.h>

void PlayerBulletFactory::shoot(Orientation orientation, two_floats position)
{
	auto newBullet = std::make_shared<Bullet>(position,
			ObjectType::PLAYER_BULLET, orientation);

	bulletsFired_.push_back(newBullet);
}

vec_of_bullets PlayerBulletFactory::getShotsFired()
{
	removeWaste();
	return bulletsFired_;
}

void PlayerBulletFactory::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bulletsFired_.begin(),
			bulletsFired_.end(), lambda);

	bulletsFired_.erase(remove_idiom, bulletsFired_.end());

}
