#include <IMovingEntity.h>

MoveDirection IMovingEntity::getMoveDirection() const
{
	return movement_.getMoveDirection();
}

void IMovingEntity::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}
