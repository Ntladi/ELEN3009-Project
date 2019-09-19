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

bool IEntity::getStatus() const
{
	return parameters_.getStatus();
}

void IEntity::killEntity()
{
	parameters_.setStatus(false);
}
