#include <Bullet.h>
#include <iostream>

Bullet::Bullet(two_floats position, ObjectType bullet_type,
		Orientation orientation)
{
	four_floats params =
	{ Constants::BULLET_X_LENGTH, Constants::BULLET_Y_LENGTH,
			Constants::BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	parameters_ = Parameters
	{ bullet_type, orientation, params };

	if (parameters_.isFacingUp())
		movement_ = Movement
		{ MoveDirection::UP, Constants::BULLET_MAXIMUM_MOVEMENT_STEP };

	else if (parameters_.isFacingDown())
		movement_ = Movement
		{ MoveDirection::DOWN, Constants::BULLET_MAXIMUM_MOVEMENT_STEP };

	position_.setXPosition(std::get<0>(position));
	position_.setYPosition(std::get<1>(position));
	hitbox_ = HitBox
	{ getPosition(), getSize() };

}

void Bullet::move()
{
	if (isOnScreen())
		moveBullet();
	else
		killEntity();

	updateHitBox();
}

bool Bullet::isOnScreen()
{
	updateHitBox();
	if (movement_.isMovingDown())
	{
		auto y_top_left = std::get<1>(hitbox_.getTopLeft());

		if (y_top_left <= std::get<1>(parameters_.getScreenSize()))
			return true;
	}
	else if (movement_.isMovingUp())
	{
		auto y_bottom_right = std::get<1>(hitbox_.getBottomLeft());

		if (y_bottom_right >= 0)
			return true;
	}

	return false;
}

void Bullet::moveBullet()
{
	auto bullet_y_position = position_.getYPosition();

	if (movement_.isMovingUp())
	{
		bullet_y_position -= movement_.getMovementStep();
		position_.setYPosition(bullet_y_position);
	}
	else if (movement_.isMovingDown())
	{
		bullet_y_position += movement_.getMovementStep();
		position_.setYPosition(bullet_y_position);

	}
}

