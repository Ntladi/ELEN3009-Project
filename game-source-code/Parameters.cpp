#include <Parameters.h>
#include <iostream>

Parameters::Parameters(ObjectType object, Orientation orientation, four_floats params)
{
	this->object_ = object;
	this->orientation_ = orientation;
	this->is_Alive_ = true;

	std::tie(x_length_,y_length_,hit_points_, worth_) = params;

}

two_floats Parameters::getSize() const
{
	return {x_length_,y_length_};
}

two_floats Parameters::getScreenSize() const
{
	return {Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH};
}


void Parameters::damage()
{
	if(hit_points_ > 0)
		hit_points_--;
	if(hit_points_ <= 0)
		setStatus(false);
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

