#include <Bullet.h>
#include <iostream>

Bullet::Bullet(two_floats position, ObjectType bullet_type,
		Orientation orientation)
{
	parameters_ = Parameters
	{ bullet_type, orientation };

	if (parameters_.isFacingUp())
		movement_ = Movement
		{ MoveDirection::UP };

	else if (parameters_.isFacingDown())
		movement_ = Movement
		{ MoveDirection::DOWN };

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

		if (y_top_left <= parameters_.getScreenYHeight())
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
		bullet_y_position -= parameters_.getMovementStep();
		position_.setYPosition(bullet_y_position);
	}
	else if (movement_.isMovingDown())
	{
		bullet_y_position += parameters_.getMovementStep();
		position_.setYPosition(bullet_y_position);

	}
}
