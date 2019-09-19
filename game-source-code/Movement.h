#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "MoveDirection.h"

class Movement
{
public:
	Movement(MoveDirection move_direction = MoveDirection::NONE, const float movement_step = 0);
	void setMoveDirection(const MoveDirection& moveDirection);
	MoveDirection getMoveDirection() const;
	const float getMovementStep() const;
	void changeHorizontalDirection();
	bool isMovingUp() const;
	bool isMovingDown() const;
	bool isMovingLeft() const;
	bool isMovingRight() const;
	bool isNotMoving() const;

private:
	MoveDirection move_direction_;
	float movement_step_;
};

#endif
