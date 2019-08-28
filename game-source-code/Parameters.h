#ifndef PARAMETERS_H_
#define PARAMETERS_H_
#include <Constants.h>
#include "ObjectType.h"
#include "Orientation.h"
#include "MoveDirection.h"

class Parameters {

public:
	Parameters(ObjectType object = ObjectType::NONE,  Orientation orientation = Orientation::FACE_UP, MoveDirection moveDirection = MoveDirection::NONE);
	const float getXLength() const;
	const float getYHeight() const;
	const float getScreenXLength() const;
	const float getScreenYHeight() const;
	const float getMovementStep() const;
	float getXposition() const;
	float getYposition() const;
	Orientation getOrientation() const;
	MoveDirection getMoveDirection() const;
	void setXPosition(const float &x);
	void setYPosition(const float &y);
	void setOrientation(const Orientation& orientation);
	void setMoveDirection(const MoveDirection& moveDirection);


private:
	ObjectType object_;
	Orientation orientation_;
	MoveDirection move_direction_;
	float x_length_;
	float y_length_;
	float x_position_;
	float y_position_;
	float movement_step_;


};

#endif
