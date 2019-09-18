#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "MoveDirection.h"

class Movement
{
public:
	Movement(MoveDirection move_direction = MoveDirection::NONE);
	void setMoveDirection(const MoveDirection& moveDirection);
	MoveDirection getMoveDirection() const;
	void changeHorizontalDirection();
	bool isMovingUp() const;
	bool isMovingDown() const;
	bool isMovingLeft() const;
	bool isMovingRight() const;
	bool isNotMoving() const;

private:
	MoveDirection move_direction_;
};

#endif
