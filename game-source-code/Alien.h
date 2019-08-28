#ifndef ALIEN_H_
#define ALIEN_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
using two_floats = std::tuple<float, float>;

class Alien
{
public:
	Alien(Orientation orientation);
	Orientation getOriention() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	MoveDirection getMoveDirection() const;
	HitBox getHitBox() const;
	Parameters getParameters() const;
	void setMoveDirection(const MoveDirection &direction);
	void move();

private:
	Parameters parameters_;
	HitBox alien_hitbox_;
	void moveAlienVertically();
	void moveAlienHorizontally();
	void incrementAlienPosition();
	bool isAtEdgeOfScreen();
	void updateHitBox();
};

#endif
