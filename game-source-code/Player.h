#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "Orientation.h"
#include "MoveDirection.h"
#include "Parameters.h"
using two_floats = std::tuple<float, float>;

class Player
{
public:
	Player(Orientation orientation);
	Orientation getOrientation() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	MoveDirection getMoveDirection() const;
	Parameters getParameters() const;
	void setMoveDirection(const MoveDirection &direction);
	void move();

private:
	Parameters parameters_;
	void incrementPlayerPosition();
	void movePlayerHorizontally();
};

#endif
