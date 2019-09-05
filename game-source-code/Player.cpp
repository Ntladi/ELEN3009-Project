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

	auto player_movement_direction = parameters_.getMoveDirection();

	if (player_movement_direction == MoveDirection::LEFT)
	{
		auto leftCorner = hitbox_.getTopLeft();
		auto left_x = std::get<0>(leftCorner);
		left_x -= parameters_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (player_movement_direction == MoveDirection::RIGHT)
	{
		auto rightCorner = hitbox_.getTopRight();
		auto right_x = std::get<0>(rightCorner);
		right_x += parameters_.getMovementStep();

		if (right_x <= parameters_.getScreenXLength())
			return true;

	}

	return false;

}

void Player::movePlayerHorizontally()
{
	auto player_movement_direction_ = parameters_.getMoveDirection();
	auto player_x_position = parameters_.getXposition();

	if (player_movement_direction_ == MoveDirection::LEFT)
		player_x_position -= parameters_.getMovementStep();
	else if (player_movement_direction_ == MoveDirection::RIGHT)
		player_x_position += parameters_.getMovementStep();

	parameters_.setXPosition(player_x_position);

}

void Player::removeWaste()
{
	auto lambda = [](std::shared_ptr<Bullet> i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bulletsFired_.begin(),
			bulletsFired_.end(), lambda);

	bulletsFired_.erase(remove_idiom, bulletsFired_.end());

}

void Player::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}
