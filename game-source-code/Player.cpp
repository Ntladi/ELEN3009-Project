#include <Player.h>

Player::Player(Orientation orientation)
{
	this->parameters_ = Parameters
	{ ObjectType::PLAYER, orientation };

	this->player_hitbox_ = HitBox
	{ this->getPosition(), this->getSize() };
}

Orientation Player::getOrientation() const
{
	return parameters_.getOrientation();
}

two_floats Player::getPosition() const
{
	return
	{	parameters_.getXposition(), parameters_.getYposition()};
}

two_floats Player::getSize() const
{
	return
	{	parameters_.getXLength(), parameters_.getYHeight()};
}

HitBox Player::getHitBox() const
{
	return player_hitbox_;
}

MoveDirection Player::getMoveDirection() const
{
	return parameters_.getMoveDirection();
}
void Player::setMoveDirection(const MoveDirection &direction)
{
	parameters_.setMoveDirection(direction);
}

Parameters Player::getParameters() const
{
	return parameters_;
}

void Player::move()
{

	if (isWithinScreenBounds())
		movePlayerHorizontally();

	updateHitBox();
	parameters_.setMoveDirection(MoveDirection::NONE);
}

bool Player::isWithinScreenBounds()
{

	updateHitBox();

	auto player_movement_direction = parameters_.getMoveDirection();

	if (player_movement_direction == MoveDirection::LEFT)
	{
		auto leftCorner = player_hitbox_.getTopLeft();
		auto left_x = std::get<0>(leftCorner);
		left_x -= parameters_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (player_movement_direction == MoveDirection::RIGHT)
	{
		auto rightCorner = player_hitbox_.getTopRight();
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

void Player::updateHitBox()
{
	player_hitbox_.setNewPositions(getPosition(), getSize());
}
