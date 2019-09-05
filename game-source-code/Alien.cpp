#include <Alien.h>
#include <iostream>

Alien::Alien(Orientation orientation)
{
	parameters_ = Parameters
	{ ObjectType::ALIEN, orientation, MoveDirection::RIGHT };
	hitbox_ = HitBox
	{ getPosition(), getSize() };
}


void Alien::setMoveDirection(const MoveDirection &direction)
{
	parameters_.setMoveDirection(direction);
}

void Alien::setXPosition(const float & position)
{
	parameters_.setXPosition(position);
}

void Alien::setYPosition(const float & position)
{
	parameters_.setYPosition(position);
}

void Alien::move()
{
	if (isAtEdgeOfScreen())
		moveAlienVertically();

	moveAlienHorizontally();
	updateHitBox();
}

void Alien::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}

bool Alien::isAtEdgeOfScreen()
{
	updateHitBox();
	auto alien_movement_direction = parameters_.getMoveDirection();

	if (alien_movement_direction == MoveDirection::LEFT)
	{
		auto leftCorner = hitbox_.getTopLeft();
		auto left_x = std::get<0>(leftCorner);
		left_x += parameters_.getMovementStep();

		if (left_x <= 0)
			return true;
	}

	else if (alien_movement_direction == MoveDirection::RIGHT)
	{
		auto rightCorner = hitbox_.getTopRight();
		auto right_x = std::get<0>(rightCorner);
		right_x -= parameters_.getMovementStep();

		if (right_x >= parameters_.getScreenXLength())
			return true;
	}
	return false;

}

void Alien::moveAlienVertically()
{
	auto alien_orientation = parameters_.getOrientation();
	auto alien_y_position = parameters_.getYposition();
	auto alien_movement_direction = parameters_.getMoveDirection();

	if (alien_orientation == Orientation::FACE_UP)
	{
		alien_y_position -= parameters_.getYHeight();
		parameters_.setYPosition(alien_y_position);

	}

	else if (alien_orientation == Orientation::FACE_DOWN)
	{
		alien_y_position += parameters_.getYHeight();
		parameters_.setYPosition(alien_y_position);
	}

	if (alien_movement_direction == MoveDirection::LEFT)
		parameters_.setMoveDirection(MoveDirection::RIGHT);
	else if (alien_movement_direction == MoveDirection::RIGHT)
		parameters_.setMoveDirection(MoveDirection::LEFT);
}

void Alien::moveAlienHorizontally()
{
	auto alien_x_position = parameters_.getXposition();
	auto alien_movement_direction = parameters_.getMoveDirection();

	if (alien_movement_direction == MoveDirection::LEFT)
		alien_x_position -= parameters_.getMovementStep();
	else if (alien_movement_direction == MoveDirection::RIGHT)
		alien_x_position += parameters_.getMovementStep();

	parameters_.setXPosition(alien_x_position);
}

bool Alien::isAtEndOfScreen()
{
	updateHitBox();
	auto alien_orientation = parameters_.getOrientation();

	if (alien_orientation == Orientation::FACE_UP)
	{
		auto leftCorner = hitbox_.getTopLeft();
		auto left_y = std::get<1>(leftCorner);
		left_y += parameters_.getYHeight();

		if (left_y <= parameters_.getYHeight())
			return true;
	}

	else if (alien_orientation == Orientation::FACE_DOWN)
	{
		auto rightCorner = hitbox_.getBottomRight();
		auto right_y = std::get<1>(rightCorner);
		right_y -= parameters_.getYHeight();

		if (right_y >= parameters_.getScreenYHeight() - parameters_.getYHeight())
			return true;
	}
	return false;
}

