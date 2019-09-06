#include <Player.h>

Player::Player(Orientation orientation)
{
	parameters_ = Parameters
	{ ObjectType::PLAYER, orientation };

	hitbox_ = HitBox
	{ getPosition(), getSize() };
}

void Player::setMoveDirection(const MoveDirection &direction)
{
	parameters_.setMoveDirection(direction);
}

vec_of_bullets Player::getShotsFired()
{
	removeWaste();
	return bulletsFired_;
}

void Player::move()
{

	if (isWithinScreenBounds())
		movePlayerHorizontally();

	updateHitBox();
	parameters_.setMoveDirection(MoveDirection::NONE);
}

void Player::shoot()
{
	auto newBullet = std::make_shared<Bullet>(getPosition(), getOrientation());

	bulletsFired_.push_back(newBullet);
}

bool Player::isWithinScreenBounds()
{

	updateHitBox();

	if (parameters_.getMoveDirection() == MoveDirection::LEFT)
	{
		auto left_x = std::get<0>(hitbox_.getTopLeft());
		left_x -= parameters_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (parameters_.getMoveDirection() == MoveDirection::RIGHT)
	{
		auto right_x = std::get<0>(hitbox_.getTopRight());
		right_x += parameters_.getMovementStep();

		if (right_x <= parameters_.getScreenXLength())
			return true;
	}

	return false;

}

void Player::movePlayerHorizontally()
{
	auto player_x_position = parameters_.getXposition();

	if (parameters_.getMoveDirection() == MoveDirection::LEFT)
		player_x_position -= parameters_.getMovementStep();
	else if (parameters_.getMoveDirection() == MoveDirection::RIGHT)
		player_x_position += parameters_.getMovementStep();

	parameters_.setXPosition(player_x_position);

}

void Player::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bulletsFired_.begin(),
			bulletsFired_.end(), lambda);

	bulletsFired_.erase(remove_idiom, bulletsFired_.end());

}

void Player::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}

