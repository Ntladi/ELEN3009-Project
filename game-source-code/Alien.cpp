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

void Alien::setPosition(const two_floats& position)
{
	parameters_.setXPosition(std::get<0>(position));
	parameters_.setYPosition(std::get<1>(position));
}

void Alien::move()
{
	if (isAtEdgeOfScreen())
		moveAlienVertically();

	moveAlienHorizontally();
	updateHitBox();
}

Bullet Alien::shoot()
{
	return Bullet{getPosition(), parameters_.getOrientation()};
}

void Alien::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}

bool Alien::isAtEdgeOfScreen()
{
	updateHitBox();

	if (parameters_.getMoveDirection() == MoveDirection::LEFT)
	{
		auto left_x = std::get<0>(hitbox_.getTopLeft());
		left_x += parameters_.getMovementStep();

		if (left_x <= 0)
			return true;
	}

	else if (parameters_.getMoveDirection() == MoveDirection::RIGHT)
	{
		auto right_x = std::get<0>(hitbox_.getTopRight());
		right_x -= parameters_.getMovementStep();

		if (right_x >= parameters_.getScreenXLength())
			return true;
	}
	return false;

}

void Alien::moveAlienVertically()
{
	auto alien_y_position = parameters_.getYposition();

	if (parameters_.getOrientation() == Orientation::FACE_UP)
	{
		alien_y_position -= parameters_.getYHeight();
		parameters_.setYPosition(alien_y_position);
	}

	else if (parameters_.getOrientation() == Orientation::FACE_DOWN)
	{
		alien_y_position += parameters_.getYHeight();
		parameters_.setYPosition(alien_y_position);
	}

	if (parameters_.getMoveDirection() == MoveDirection::LEFT)
		parameters_.setMoveDirection(MoveDirection::RIGHT);
	else if (parameters_.getMoveDirection() == MoveDirection::RIGHT)
		parameters_.setMoveDirection(MoveDirection::LEFT);
}

void Alien::moveAlienHorizontally()
{
	auto alien_x_position = parameters_.getXposition();

	if (parameters_.getMoveDirection() == MoveDirection::LEFT)
		alien_x_position -= parameters_.getMovementStep();
	else if (parameters_.getMoveDirection() == MoveDirection::RIGHT)
		alien_x_position += parameters_.getMovementStep();

	parameters_.setXPosition(alien_x_position);
}

bool Alien::isAtEndOfScreen()
{
	updateHitBox();

	if (parameters_.getOrientation() == Orientation::FACE_UP)
	{
		auto left_y = std::get<1>(hitbox_.getTopLeft());
		left_y += parameters_.getYHeight();

		if (left_y <= parameters_.getYHeight())
			return true;
	}

	else if (parameters_.getOrientation() == Orientation::FACE_DOWN)
	{
		auto right_y = std::get<1>(hitbox_.getBottomRight());
		right_y -= parameters_.getYHeight();

		if (right_y >= parameters_.getScreenYHeight() - parameters_.getYHeight())
			return true;
	}
	return false;
}

