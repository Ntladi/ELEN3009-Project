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
	bool getStatus() const;
	MoveDirection getMoveDirection() const;
	HitBox getHitBox() const;
	Parameters getParameters() const;
	void setMoveDirection(const MoveDirection &direction);
	void setYPosition(const float& position);
	void setXPosition(const float& position);
	void moveAlienVertically();
	bool isAtEdgeOfScreen();
	bool isAtEndOfScreen();
	void move();
	void killObject();

private:
	Parameters parameters_;
	HitBox alien_hitbox_;
	bool isAlive_;
	void moveAlienHorizontally();
	void incrementAlienPosition();
	void updateHitBox();
};

#endif
