#include <Bullet.h>
#include <iostream>

Bullet::Bullet(two_floats position, ObjectType bullet_type,
		Orientation orientation)
{
	four_floats params =
	{ Constants::BULLET_X_LENGTH,Constants::BULLET_Y_LENGTH,
			Constants::BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	setup(params,bullet_type,orientation,position);

}

void Bullet::move()
{
	if (!isAtEndOfScreen())
		moveBullet();
	else
		killEntity();

	updateHitBox();
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

two_floats Bullet::initializePosition()
{
	auto x_position = 0.0f;
	auto y_position = 0.0f;

	return
	{	x_position,y_position};
}

void Bullet::setup(four_floats params,ObjectType bullet_type, Orientation orientation, two_floats position)
{
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
