#include <Player.h>

Player::Player(Orientation orientation)
{
	parameters_ = Parameters
	{ ObjectType::PLAYER, orientation };

	position_ = Position
	{ ObjectType::PLAYER, orientation };

	movement_ = Movement
	{ MoveDirection::NONE };

	hitbox_ = HitBox
	{ getPosition(), getSize() };
}

void Player::setMoveDirection(const MoveDirection &direction)
{
	movement_.setMoveDirection(direction);
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
	movement_.setMoveDirection(MoveDirection::NONE);
}

void Player::shoot()
{
	auto newBullet = std::make_shared<Bullet>(getPosition(),
			ObjectType::PLAYER_BULLET, getOrientation());

	bulletsFired_.push_back(newBullet);
}

bool Player::isWithinScreenBounds()
{

	updateHitBox();

	if (movement_.isMovingLeft())
	{
		auto left_x = std::get<0>(hitbox_.getTopLeft());
		left_x -= parameters_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (movement_.isMovingRight())
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
	auto player_x_position = position_.getXPosition();
	if (movement_.isMovingLeft())
		player_x_position -= parameters_.getMovementStep();
	else if (movement_.isMovingRight())
		player_x_position += parameters_.getMovementStep();

	position_.setXPosition(player_x_position);

}

void Player::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bulletsFired_.begin(),
			bulletsFired_.end(), lambda);

	bulletsFired_.erase(remove_idiom, bulletsFired_.end());

}
