#include <Movement.h>

Movement::Movement(MoveDirection move_direction, const float movement_step)
{
	move_direction_ = move_direction;
	movement_step_ = movement_step;
	edge_step_ = Constants::EDGE_STEP;
}

const float Movement::getMovementStep() const
{
	return movement_step_;
}

const float Movement::getEdgeStep() const
{
	return edge_step_;
}
const MoveDirection Movement::getMoveDirection() const
{
	return move_direction_;
}
const bool Movement::isMovingUp() const
{
	return move_direction_ == MoveDirection::UP;
}

const bool Movement::isMovingDown() const
{
	return move_direction_ == MoveDirection::DOWN;
}

const bool Movement::isMovingLeft() const
{
	return move_direction_ == MoveDirection::LEFT;
}

const bool Movement::isMovingRight() const
{
	return move_direction_ == MoveDirection::RIGHT;
}

const bool Movement::isNotMoving() const
{
	return move_direction_ == MoveDirection::NONE;
}

void Movement::changeHorizontalDirection()
{
	if (move_direction_ == MoveDirection::LEFT)
		move_direction_ = MoveDirection::RIGHT;
	else if (move_direction_ == MoveDirection::RIGHT)
		move_direction_ = MoveDirection::LEFT;
}

void Movement::setMoveDirection(const MoveDirection &move_direction)
{
	move_direction_ = move_direction;
}
