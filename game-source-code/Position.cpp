#include <Position.h>

Position::Position(two_floats initialPos)
{
	std::tie(x_position_,y_position_) = initialPos;
}

void Position::setXPosition(const float &x)
{
	x_position_ = x;
}

void Position::setYPosition(const float &y)
{
	y_position_ = y;
}

const float Position::getXPosition() const
{
	return x_position_;
}

const float Position::getYPosition() const
{
	return y_position_;
}
