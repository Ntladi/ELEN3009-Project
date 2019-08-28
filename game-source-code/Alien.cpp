#include <Alien.h>

Alien::Alien(Orientation orientation)
{
	this->parameters_ = Parameters
	{ ObjectType::ALIEN, orientation, MoveDirection::RIGHT };
	this->alien_hitbox_ = HitBox
	{ this->getPosition(), this->getSize() };
}

Orientation Alien::getOriention() const
{
	return parameters_.getOrientation();
}

two_floats Alien::getPosition() const
{
	return
	{	parameters_.getXposition(), parameters_.getYposition()};
}

two_floats Alien::getSize() const
{
	return
	{	parameters_.getXLength(), parameters_.getYHeight()};
}

HitBox Alien::getHitBox() const
{
	return alien_hitbox_;
}

MoveDirection Alien::getMoveDirection() const
{
	return parameters_.getMoveDirection();
}

void Alien::setMoveDirection(const MoveDirection &direction)
{
	parameters_.setMoveDirection(direction);
}

Parameters Alien::getParameters() const
{
	return parameters_;
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
	alien_hitbox_.setNewPositions(this->getPosition(), this->getSize());
}

bool Alien::isAtEdgeOfScreen()
{
	updateHitBox();
	auto alien_movement_direction = parameters_.getMoveDirection();

	if (alien_movement_direction == MoveDirection::LEFT)
	{
		auto leftCorner = alien_hitbox_.getTopLeft();
		auto left_x = std::get<0>(leftCorner);
		left_x += parameters_.getMovementStep();

		if (left_x <= 0)
			return true;
	}

	else if (alien_movement_direction == MoveDirection::RIGHT)
	{
		auto rightCorner = alien_hitbox_.getTopRight();
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
