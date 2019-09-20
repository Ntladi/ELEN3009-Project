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

two_floats Parameters::getSize() const
{
	return
	{	x_length_,y_length_};
}

float Parameters::getBottomEdge() const
{
	return Constants::SCREEN_Y_LENGTH - (y_length_ / 2);
}

float Parameters::getTopEdge() const
{
	return y_length_ * 1.5;
}

float Parameters::getLeftEdge() const
{
	return x_length_ / 2;
}

float Parameters::getRightEdge() const
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

float Parameters::getWorth() const
{
	return worth_;
}

int Parameters::getLives() const
{
	return hit_points_;
}

ObjectType Parameters::getObjectType() const
{
	return object_;
}
Orientation Parameters::getOrientation() const
{
	return orientation_;
}

bool Parameters::getStatus() const
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

bool Parameters::isFacingDown()
{
	return orientation_ == Orientation::FACE_DOWN;
}

bool Parameters::isFacingUp()
{
	return orientation_ == Orientation::FACE_UP;
}

bool Parameters::isHit() const
{
	return is_Hit_;
}

void Parameters::resetHit()
{
	is_Hit_ = false;
}
