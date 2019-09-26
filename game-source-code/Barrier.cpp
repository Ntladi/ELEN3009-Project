#include <Barrier.h>

Barrier::Barrier(Orientation orientation)
{
	four_floats params =
	{ Constants::BARRIER_X_LENGTH, Constants::BARRIER_Y_LENGTH,
			Constants::BARRIER_HIT_POINTS, Constants::BARRIER_HIT_POINTS };

	parameters_ = Parameters
	{ ObjectType::BARRIER, orientation, params };

	position_ = Position
	{ initializePosition() };

	hitbox_ = HitBox
	{ getSize(), getPosition() };

}

two_floats Barrier::initializePosition()
{
	auto x_position = Constants::BARRIER_INITAL_X_POSITION;
	auto y_position = 0;

	if (parameters_.isFacingUp())
		y_position = Constants::BARRIER_INITAL_UP_Y_POSITION;
	else if(parameters_.isFacingDown())
		y_position = Constants::BARRIER_INITAL_DOWN_Y_POSITION;

	return
	{	x_position, y_position};
}
