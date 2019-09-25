#include <Parameters.h>
#include <iostream>

Parameters::Parameters(ObjectType object, Orientation orientation,
		four_floats params)
{
	this->object_ = object;
	this->orientation_ = orientation;
	this->is_Alive_ = true;
	this->is_Hit_ = false;

	std::tie(x_length_, y_length_, hit_points_, worth_) = params;

}

const two_floats Parameters::getSize() const
{
	return
	{	x_length_,y_length_};
}

const float Parameters::getBottomEdge() const
{
	return Constants::SCREEN_Y_LENGTH - (y_length_ / 2);
}

const float Parameters::getTopEdge() const
{
	return y_length_ * 1.5;
}

const float Parameters::getLeftEdge() const
{
	return x_length_ / 2;
}

const float Parameters::getRightEdge() const
{
	return Constants::SCREEN_X_LENGTH - (x_length_ / 2);
}

void Parameters::damage()
{
	if (hit_points_ > 0)
	{
		hit_points_--;
		is_Hit_= true;
	}
	if (hit_points_ <= 0)
		setStatus(false);
}

const float Parameters::getWorth() const
{
	return worth_;
}

const int Parameters::getLives() const
{
	return hit_points_;
}

const ObjectType Parameters::getObjectType() const
{
	return object_;
}
const Orientation Parameters::getOrientation() const
{
	return orientation_;
}

const bool Parameters::getStatus() const
{
	return is_Alive_;
}

void Parameters::setOrientation(const Orientation &orientation)
{
	orientation_ = orientation;
}

void Parameters::setStatus(const bool &status)
{
	is_Alive_ = status;
}

const bool Parameters::isFacingDown() const
{
	return orientation_ == Orientation::FACE_DOWN;
}

const bool Parameters::isFacingUp() const
{
	return orientation_ == Orientation::FACE_UP;
}

const bool Parameters::isHit() const
{
	return is_Hit_;
}

void Parameters::resetHit()
{
	is_Hit_ = false;
}
