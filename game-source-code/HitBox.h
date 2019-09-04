
#ifndef HITBOX_H_
#define HITBOX_H_
#include <tuple>
#include <vector>
using two_floats = std::tuple<float, float>;

class HitBox {
public:
	HitBox(two_floats position = {}, two_floats size = {});
	void setNewPositions(two_floats position, two_floats size);
	std::vector<two_floats> getVertecies() const;
	two_floats getTopLeft() const;
	two_floats getTopRight() const;
	two_floats getBottomLeft() const;
	two_floats getBottomRight() const;

private:
	double x_centre_;
	double y_centre_;
	double x_length_from_centre_;
	double y_length_from_centre_;
	two_floats top_left_;
	two_floats top_right_;
	two_floats bottom_left_;
	two_floats bottom_right_;
	void calculateVertecies();


};

#endif
