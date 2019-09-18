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
	MoveDirection getMoveDirection() const;
	HitBox getHitBox() const;
	Parameters getParameters() const;
	bool getStatus() const;
	void killEntity();
	virtual void move();

protected:
	Parameters parameters_;
	HitBox hitbox_;
	Position position_;
	Movement movement_;
	void updateHitBox();

};

#endif
