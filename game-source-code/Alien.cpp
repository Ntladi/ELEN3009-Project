#include <Alien.h>

Alien::Alien(Orientation orientation)
{
	four_floats params
	{ Constants::ALIEN_X_LENGTH, Constants::ALIEN_Y_LENGTH,
			Constants::ALIEN_HIT_POINTS, Constants::ALIEN_WORTH };

	parameters_ = Parameters
	{ ObjectType::ALIEN, orientation, params };

	position_ = Position
	{ ObjectType::ALIEN, orientation };

	movement_ = Movement
	{ MoveDirection::RIGHT, Constants::ALIEN_MAXIMUM_MOVEMENT_STEP };

	hitbox_ = HitBox
	{ getPosition(), getSize() };
}

void Alien::setMoveDirection(const MoveDirection &direction)
{
	movement_.setMoveDirection(direction);
}

void Alien::setPosition(const two_floats &position)
{
	position_.setXPosition(std::get<0>(position));
	position_.setYPosition(std::get<1>(position));
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

bool Alien::isAtEdgeOfScreen()
{
	updateHitBox();

	if (movement_.isMovingLeft())
	{
		auto left_x = std::get<0>(hitbox_.getTopLeft());
		left_x += movement_.getMovementStep();

		if (left_x <= 0)
			return true;
	}

	else if (movement_.isMovingRight())
	{
		auto right_x = std::get<0>(hitbox_.getTopRight());
		right_x -= movement_.getMovementStep();

		if (right_x >= std::get<0>(parameters_.getScreenSize()))
			return true;
	}
	return false;

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

bool Alien::isAtEndOfScreen()
{
	updateHitBox();

	if (parameters_.isFacingUp())
	{
		auto left_y = std::get<1>(hitbox_.getTopLeft());
		left_y += std::get<1>(parameters_.getSize());

		if (left_y <= std::get<1>(parameters_.getSize()) / 2)
			return true;
	}

	else if (parameters_.isFacingDown())
	{
		auto right_y = std::get<1>(hitbox_.getBottomRight());
		right_y -= std::get<1>(parameters_.getSize());

		if (right_y
				>= std::get<1>(parameters_.getScreenSize())
						- std::get<1>(parameters_.getSize()) / 2)
			return true;
	}
	return false;
}

