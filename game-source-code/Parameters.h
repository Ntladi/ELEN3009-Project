#ifndef PARAMETERS_H_
#define PARAMETERS_H_
#include <Constants.h>
#include <tuple>
#include "ObjectType.h"
#include "Orientation.h"
#include "MoveDirection.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float, float, float, float>;

class Parameters {

public:
	Parameters(ObjectType object = ObjectType::NONE, Orientation orientation = Orientation::FACE_UP, four_floats params = {0,0,0,0});
	two_floats getSize() const;
	float getWorth() const;
	float getTopEdge() const;
	float getBottomEdge() const;
	float getLeftEdge() const;
	float getRightEdge() const;
	int getLives() const;
	ObjectType getObjectType() const;
	Orientation getOrientation() const;
	void damage();
	bool getStatus() const;
	void setOrientation(const Orientation& orientation);
	void setStatus(const bool &status);
	bool isFacingUp();
	bool isFacingDown();

private:
	ObjectType object_;
	Orientation orientation_;
	bool is_Alive_;
	float x_length_;
	float y_length_;
	float hit_points_;
	float worth_;


};

#endif
