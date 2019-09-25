#include <IEntity.h>


IEntity::~IEntity()
{
}

const Orientation IEntity::getOrientation() const
{
	return parameters_.getOrientation();
}

const ObjectType IEntity::getObjectType() const
{
	return parameters_.getObjectType();
}
const two_floats IEntity::getPosition() const
{
	return {position_.getXPosition(), position_.getYPosition()};
}

const two_floats IEntity::getSize() const
{
	return parameters_.getSize();
}

const HitBox IEntity::getHitBox() const
{
	return hitbox_;
}

const float IEntity::getScore() const
{
	return parameters_.getWorth();
}

const bool IEntity::getStatus() const
{
	return parameters_.getStatus();
}

const int IEntity::getLives() const
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

void IEntity::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}
