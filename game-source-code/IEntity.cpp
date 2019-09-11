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
	return {parameters_.getXposition(), parameters_.getYposition()};
}

two_floats IEntity::getSize() const
{
	return
	{	parameters_.getXLength(), parameters_.getYHeight()};
}

HitBox IEntity::getHitBox() const
{
	return hitbox_;
}

MoveDirection IEntity::getMoveDirection() const
{
	return parameters_.getMoveDirection();
}

Parameters IEntity::getParameters() const
{
	return parameters_;
}

bool IEntity::getStatus() const
{
	return parameters_.getStatus();
}

void IEntity::killEntity()
{
	parameters_.setStatus(false);
}

void IEntity::move()
{

}
