#include <IMovingEntity.h>

MoveDirection IMovingEntity::getMoveDirection() const
{
	return movement_.getMoveDirection();
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

bool IMovingEntity::isAtEndOfScreen()
{
	updateHitBox();
	if ((position_.getYPosition() - movement_.getEdgeStep()
			< parameters_.getTopEdge()) && movement_.isMovingUp())
		return true;
	if ((position_.getYPosition() + movement_.getEdgeStep()
			> parameters_.getBottomEdge()) && movement_.isMovingDown())
		return true;
	return false;
}
