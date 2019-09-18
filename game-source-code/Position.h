#ifndef POSITION_H_
#define POSITION_H_
#include <tuple>
#include "ObjectType.h"
#include "Orientation.h"
#include "Constants.h"

class Position
{
public:
	Position(ObjectType object = ObjectType::NONE, Orientation orientation =
			Orientation::FACE_UP);
	void setXPosition(const float &x);
	void setYPosition(const float &y);
	float getXPosition() const;
	float getYPosition() const;
private:
	float x_position_;
	float y_position_;
	void initializePlayerPosition(Orientation &orientation);
	void initializeBulletPosition(Orientation &orientation);
	void initializeAliePosition(Orientation &orientation);

};

#endif
