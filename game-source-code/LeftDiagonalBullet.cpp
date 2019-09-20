#include <LeftDiagonalBullet.h>

LeftDiagonalBullet::LeftDiagonalBullet(two_floats position, Orientation orientation)
{
	four_floats params =
	{ Constants::BULLET_X_LENGTH, Constants::BULLET_Y_LENGTH,
			Constants::BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	parameters_ = Parameters
	{ ObjectType::PLAYER_BULLET, orientation, params };

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

void LeftDiagonalBullet::moveBullet()
{
	Bullet::moveBullet();
	auto x_position = position_.getXPosition();
	x_position -= movement_.getMovementStep()/2;
	position_.setXPosition(x_position);
}
