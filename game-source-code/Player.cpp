#include <Player.h>

Player::Player(Orientation orientation)
{
	four_floats params =
	{ Constants::PLAYER_X_LENGTH, Constants::PLAYER_Y_LENGTH,
			Constants::PLAYER_HIT_POINTS, Constants::PLAYER_WORTH };

	parameters_ = Parameters
	{ ObjectType::PLAYER, orientation, params };

	position_ = Position
	{ ObjectType::PLAYER, initializePosition() };

	movement_ = Movement
	{ MoveDirection::NONE, Constants::PLAYER_MAXIMUM_MOVEMENT_STEP };

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
		left_x -= movement_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (movement_.isMovingRight())
	{
		auto right_x = std::get<0>(hitbox_.getTopRight());
		right_x += movement_.getMovementStep();

		if (right_x <= std::get<0>(parameters_.getScreenSize()))
			return true;
	}

	return false;

}

void Player::movePlayerHorizontally()
{
	auto player_x_position = position_.getXPosition();
	if (movement_.isMovingLeft())
		player_x_position -= movement_.getMovementStep();
	else if (movement_.isMovingRight())
		player_x_position += movement_.getMovementStep();

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

two_floats Player::initializePosition()
{
	auto x_position = Constants::PLAYER_INITAL_X_POSITION;
	auto y_position = 0.0f;

	if (parameters_.isFacingUp())
		y_position = Constants::SCREEN_Y_LENGTH
				- Constants::PLAYER_Y_LENGTH/2;
	else if (parameters_.isFacingDown())
		y_position = Constants::PLAYER_Y_LENGTH*1.5;

	return {x_position,y_position};
}
