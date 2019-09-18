#include <SeperatingAxisTheorem.h>
#include <iostream>

SeperatingAxisTheorem::SeperatingAxisTheorem()
{
	this->axis_ = vector<two_floats> {};
	this->vertecies_obj_1_ = vector<two_floats> {};
	this->vertecies_obj_2_ = vector<two_floats> {};
}

bool SeperatingAxisTheorem::isOverlapping(HitBox& obj_1, HitBox& obj_2)
{
	if(!axis_.empty())
		clearAll();

	vertecies_obj_1_ = obj_1.getVertecies();
	vertecies_obj_2_ = obj_2.getVertecies();


	makeAxes();

	return checkProjectionOverLap();
}

two_floats SeperatingAxisTheorem::normalizeAxis(two_floats& axis)
{
	auto [axis_x,axis_y] = axis;
	auto axis_magnitude = std::sqrt((std::pow(axis_x,2))+(std::pow(axis_y,2)));

	return {axis_x/axis_magnitude, axis_y/axis_magnitude};

}

void SeperatingAxisTheorem::makeAxes()
{
	auto top_left = vertecies_obj_1_.at(0);
	auto top_right = vertecies_obj_1_.at(1);
	auto bottom_left = vertecies_obj_1_.at(2);
	auto bottom_right = vertecies_obj_1_.at(3);

	auto obj1_x_1 = std::get<0>(top_right) - std::get<0>(top_left);
	auto obj1_x_2 = std::get<1>(top_right) - std::get<1>(top_left);
	auto obj1_axis = two_floats{obj1_x_1, obj1_x_2};
	axis_.push_back(normalizeAxis(obj1_axis));

	auto obj1_y_1 = std::get<0>(top_right) - std::get<0>(bottom_right);
	auto obj1_y_2 = std::get<1>(top_right) - std::get<1>(bottom_right);
	obj1_axis = two_floats{obj1_y_1, obj1_y_2};
	axis_.push_back(normalizeAxis(obj1_axis));

	obj1_x_1 = std::get<0>(top_left) - std::get<0>(bottom_left);
	obj1_x_2 = std::get<1>(top_left) - std::get<1>(bottom_left);
	obj1_axis = two_floats{obj1_x_1, obj1_x_2};
	axis_.push_back(normalizeAxis(obj1_axis));

	obj1_y_1 = std::get<0>(top_left) - std::get<0>(top_right);
	obj1_y_2 = std::get<1>(top_left) - std::get<1>(top_right);
	obj1_axis = two_floats{obj1_y_1, obj1_y_2};
	axis_.push_back(normalizeAxis(obj1_axis));

}

float SeperatingAxisTheorem::getDotProduct(const two_floats& pointA, const two_floats& pointB)
{
	auto dot_product = (std::get<0>(pointA) * std::get<0>(pointB)) + (std::get<1>(pointA) * std::get<1>(pointB));
	return dot_product;
}

two_floats SeperatingAxisTheorem::projection(const two_floats& axis,vector<two_floats>& verticies)
{
	vector<two_floats> projected_verticies(4);
	auto iter_projected_vertecies = begin(projected_verticies);

	auto [axis_x,axis_y] = axis;
	auto axis_magnitude_sqrd = (std::pow(axis_x,2))+(std::pow(axis_y,2));

	for(const auto &vertex:verticies)
	{
		auto dot_product = getDotProduct(vertex,axis)/axis_magnitude_sqrd;
		*iter_projected_vertecies = two_floats{dot_product * axis_x, dot_product * axis_y};
		++iter_projected_vertecies;
	}

	auto minimum_projection = getDotProduct(axis,projected_verticies.at(0));
	auto maximum_projection = minimum_projection;

	for(auto &i:projected_verticies)
	{
		auto projection_ = getDotProduct(axis,i);

		if(projection_ < minimum_projection)
			minimum_projection = projection_;
		else if(projection_> maximum_projection)
			maximum_projection = projection_;
	}

	return {minimum_projection,maximum_projection};
}

bool SeperatingAxisTheorem::checkProjectionOverLap()
{
	for(const auto& axis:axis_)
	{
		auto [minimum_projection_A, maximum_projection_A] = projection(axis,vertecies_obj_1_);
		auto [minimum_projection_B, maximum_projection_B] = projection(axis,vertecies_obj_2_);

		bool overlapOccured = (minimum_projection_B <= maximum_projection_A && maximum_projection_B >= minimum_projection_A);

		if(!overlapOccured)
			return false;
	}
	return true;
}


void SeperatingAxisTheorem::clearAll()
{
	axis_.clear();
	vertecies_obj_1_.clear();
	vertecies_obj_2_.clear();
}

