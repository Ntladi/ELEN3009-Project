#ifndef IENTITY_H_
#define IENTITY_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "Parameters.h"
#include "ObjectType.h"
#include "HitBox.h"
#include "Position.h"
#include "Movement.h"
using two_floats = std::tuple<float, float>;

class IEntity
{
public:
	virtual ~IEntity();
	Orientation getOrientation() const;
	ObjectType getObjectType() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	HitBox getHitBox() const;
	bool getStatus() const;
	float getScore() const;
	int getLives() const;
	void killEntity();
	void hitEntity();

protected:
	Parameters parameters_;
	HitBox hitbox_;
	Position position_;
	virtual two_floats initializePosition() = 0;
	void updateHitBox();

};

#endif
