#include <HitBox.h>

HitBox::HitBox(two_floats position, two_floats size)
{
	setNewPositions(position, size);
	calculateVertecies();
}

std::vector<two_floats> HitBox::getVertecies(two_floats position,
		two_floats size)
{
	setNewPositions(position, size);
	calculateVertecies();

	return
	{ top_left_,top_right_,bottom_left_,bottom_right_ };

}

two_floats HitBox::getTopLeft() const
{
	return this->top_left_;
}

two_floats HitBox::getTopRight() const
{
	return this->top_right_;
}

two_floats HitBox::getBottomLeft() const
{
	return this->bottom_left_;
}

two_floats HitBox::getBottomRight() const
{
	return this->bottom_right_;
}
void HitBox::calculateVertecies()
{
	auto x_left = x_centre_ - x_length_from_centre_;
	auto x_right = x_centre_ + x_length_from_centre_;
	auto y_top = y_centre_ - y_length_from_centre_;
	auto y_bottom = y_centre_ + y_length_from_centre_;

	this->top_left_ = { x_left, y_top };
	this->top_right_ = { x_right, y_top };
	this->bottom_left_ = { x_left, y_bottom };
	this->bottom_right_ = { x_right, y_bottom };
}

void HitBox::setNewPositions(two_floats position, two_floats size)
{
	this->x_centre_ = std::get<0>(position);
	this->y_centre_ = std::get<1>(position);

	auto x_length = std::get<0>(size);
	auto y_length = std::get<1>(size);

	this->x_length_from_centre_ = x_length / 2;
	this->y_length_from_centre_ = y_length / 2;

	calculateVertecies();
}
