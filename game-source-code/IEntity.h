#ifndef IENTITY_H_
#define IENTITY_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "Parameters.h"
#include "HitBox.h"
using two_floats = std::tuple<float, float>;

class IEntity
{
public:
	virtual ~IEntity();
	Orientation getOrientation() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	MoveDirection getMoveDirection() const;
	HitBox getHitBox() const;
	Parameters getParameters() const;
	bool getStatus() const;
	void killEntity();
	virtual void move() = 0;

protected:
	Parameters parameters_;
	HitBox hitbox_;
};

#endif
