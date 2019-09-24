#include <PlayerBulletFactory.h>

PlayerBulletFactory::PlayerBulletFactory()
{
	stopwatch_.start();
}
void PlayerBulletFactory::shoot(Orientation orientation, two_floats position)
{
	if (stopwatch_.getTimeElapsed() < Constants::TIME_BEFORE_1ST_POWER_UP)
		makeStandardBullet(orientation, position);
	else if (stopwatch_.getTimeElapsed()
			> Constants::TIME_BEFORE_1ST_POWER_UP
			&& stopwatch_.getTimeElapsed()
					< Constants::TIME_BEFORE_2ND_POWER_UP)
		makeMultiShotBullets(orientation, position);
	else if (stopwatch_.getTimeElapsed() > Constants::TIME_BEFORE_2ND_POWER_UP)
		makeMultiShotPiercer(orientation,position);
}

void PlayerBulletFactory::makeStandardBullet(Orientation orientation,
		two_floats position)
{
	bullet_ptr newBullet = std::make_shared<Bullet>(position,
			ObjectType::PLAYER_BULLET, orientation);

	bulletsFired_.push_back(newBullet);
}


void PlayerBulletFactory::makeMultiShotPiercer(Orientation orientation, two_floats position)
{
	makePiercerBullet(orientation,position);

	auto [x_position, y_position] = position;
	x_position += Constants::PLAYER_X_LENGTH/2;
	two_floats new_pos = {x_position, y_position};

	makePiercerBullet(orientation, new_pos);

	std::tie(x_position,y_position) = position;
	x_position -= Constants::PLAYER_X_LENGTH/2;
	new_pos = {x_position, y_position};

	makePiercerBullet(orientation, new_pos);

}
void PlayerBulletFactory::makePiercerBullet(Orientation orientation,
		two_floats position)
{
	bullet_ptr newBullet = std::make_shared<PiercerBullet>(position,
			orientation);
	bulletsFired_.push_back(newBullet);
}

void PlayerBulletFactory::makeMultiShotBullets(Orientation orientation,
		two_floats position)
{
	bullet_ptr newLeftBullet = std::make_shared<LeftDiagonalBullet>(position,
			orientation);
	bulletsFired_.push_back(newLeftBullet);

	bullet_ptr newRightBullet = std::make_shared<RightDiagonalBullet>(position,
			orientation);
	bulletsFired_.push_back(newRightBullet);
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

void PlayerBulletFactory::resetFactory()
{
	stopwatch_.start();
}
