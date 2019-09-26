#include <Alien.h>

Alien::Alien(Orientation orientation)
{
	four_floats params
	{ Constants::ALIEN_X_LENGTH, Constants::ALIEN_Y_LENGTH,
			Constants::ALIEN_HIT_POINTS, Constants::ALIEN_WORTH };

	parameters_ = Parameters
	{ ObjectType::ALIEN, orientation, params };

	position_ = Position
	{ initializePosition() };

	movement_ = Movement
	{ MoveDirection::RIGHT, Constants::ALIEN_MAXIMUM_MOVEMENT_STEP };

	hitbox_ = HitBox
	{ getPosition(), getSize() };
}

void Alien::setMoveDirection(const MoveDirection &direction)
{
	movement_.setMoveDirection(direction);
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
	return Bullet
	{ getPosition(), ObjectType::ALIEN_BULLET, parameters_.getOrientation() };
}

const bool Alien::checkEdge()
{
	return isAtEdgeOfScreen();
}

const bool Alien::checkEnd()
{
	return isAtEndOfScreen();
}

void Alien::moveAlienVertically()
{
	auto alien_y_position = position_.getYPosition();

	if (parameters_.isFacingUp())
	{
		alien_y_position -= std::get<1>(parameters_.getSize());
		position_.setYPosition(alien_y_position);
	}

	else if (parameters_.isFacingDown())
	{
		alien_y_position += std::get<1>(parameters_.getSize());
		position_.setYPosition(alien_y_position);
	}
	movement_.changeHorizontalDirection();
}

void Alien::moveAlienHorizontally()
{
	auto alien_x_position = position_.getXPosition();

	if (movement_.isMovingLeft())
		alien_x_position -= movement_.getMovementStep();
	else if (movement_.isMovingRight())
		alien_x_position += movement_.getMovementStep();

	position_.setXPosition(alien_x_position);
}

const bool Alien::isAtEndOfScreen()
{
	updateHitBox();
	if ((position_.getYPosition() - movement_.getMovementStep()
			< parameters_.getTopEdge()) && parameters_.isFacingUp())
		return true;
	if ((position_.getYPosition() + movement_.getMovementStep()
			> parameters_.getBottomEdge()) && parameters_.isFacingDown())
		return true;
	return false;
}

two_floats Alien::initializePosition()
{
	auto x_position = Constants::ALIEN_INITAL_X_POSITION;
	auto y_position = 0.0f;

	if (parameters_.isFacingUp())
		y_position = Constants::ALIEN_INITAL_UP_Y_POSITION;
	else if (parameters_.isFacingDown())
		y_position = Constants::ALIEN_INITAL_DOWN_Y_POSITION;

	return
	{	x_position,y_position};
}
