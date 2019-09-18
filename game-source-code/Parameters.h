#ifndef PARAMETERS_H_
#define PARAMETERS_H_
#include <Constants.h>
#include <tuple>
#include "ObjectType.h"
#include "Orientation.h"
#include "MoveDirection.h"
using two_floats = std::tuple<float, float>;

class Parameters {

public:
	Parameters(ObjectType object = ObjectType::NONE, Orientation orientation = Orientation::FACE_UP);
	const float getXLength() const;
	const float getYHeight() const;
	two_floats getSize() const;
	const float getScreenXLength() const;
	const float getScreenYHeight() const;
	const float getMovementStep() const;
	ObjectType getObjectType() const;
	Orientation getOrientation() const;
	bool getStatus() const;
	void setOrientation(const Orientation& orientation);
	void setStatus(const bool &status);
	bool isFacingUp();
	bool isFacingDown();

private:
	ObjectType object_;
	Orientation orientation_;
	float x_length_;
	float y_length_;
	float movement_step_;
	bool is_Alive_;
	void initializePlayer();
	void initializeBullet();
	void initializeAlien();


};

#endif
