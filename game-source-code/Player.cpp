#include <Player.h>

Player::Player(Orientation orientation)
{
	this->parameters_ = Parameters
	{ ObjectType::PLAYER, orientation };
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

	movePlayerHorizontally();

	parameters_.setMoveDirection(MoveDirection::NONE);
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
