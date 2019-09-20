#include <PiercerBullet.h>
#include <iostream>

PiercerBullet::PiercerBullet(two_floats position,
		Orientation orientation)
{
	four_floats params =
	{ Constants::PIERCER_BULLET_X_LENGTH, Constants::PIERCER_BULLET_Y_LENGTH,
			Constants::PIERCER_BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	parameters_ = Parameters
	{ ObjectType::PIERCER_BULLET, orientation, params };

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
