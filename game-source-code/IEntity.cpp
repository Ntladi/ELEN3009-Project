#include <IEntity.h>


IEntity::~IEntity()
{
}

Orientation IEntity::getOrientation() const
{
	return parameters_.getOrientation();
}

ObjectType IEntity::getObjectType() const
{
	return parameters_.getObjectType();
}
two_floats IEntity::getPosition() const
{
	return {position_.getXPosition(), position_.getYPosition()};
}

two_floats IEntity::getSize() const
{
	return parameters_.getSize();
}

HitBox IEntity::getHitBox() const
{
	return hitbox_;
}

float IEntity::getScore() const
{
	return parameters_.getWorth();
}

bool IEntity::getStatus() const
{
	return parameters_.getStatus();
}

int IEntity::getLives() const
{
	return parameters_.getLives();
}
void IEntity::killEntity()
{
	parameters_.setStatus(false);
}

void IEntity::hitEntity()
{
	parameters_.damage();
}
