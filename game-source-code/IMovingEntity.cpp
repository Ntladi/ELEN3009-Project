#include <IMovingEntity.h>

MoveDirection IMovingEntity::getMoveDirection() const
{
	return movement_.getMoveDirection();
}

void IMovingEntity::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}

bool IMovingEntity::isAtEdgeOfScreen()
{
	updateHitBox();
	if ((position_.getXPosition() + movement_.getMovementStep()
			> parameters_.getRightEdge()) && movement_.isMovingRight())
		return true;

	else if ((position_.getXPosition() - movement_.getMovementStep()
			< parameters_.getLeftEdge()) && movement_.isMovingLeft())
		return true;

	return false;
}
