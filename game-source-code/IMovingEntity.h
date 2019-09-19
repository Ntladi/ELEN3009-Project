#ifndef IMOVINGENTITY_H_
#define IMOVINGENTITY_H_
#include "IEntity.h"

class IMovingEntity : public IEntity
{
public:
	MoveDirection getMoveDirection() const;
	virtual void move() = 0;
protected:
	Movement movement_;
	void updateHitBox();

};

#endif
