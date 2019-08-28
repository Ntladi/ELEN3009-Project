#ifndef BULLET_H_
#define BULLET_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
using two_floats = std::tuple<float, float>;

class Bullet
{
public:
	Bullet(two_floats position, Orientation orientation);
	~Bullet();
	Orientation getOrientation() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	bool getStatus() const;
	MoveDirection getMoveDirection() const;
	HitBox getHitBox();
	Parameters getParameters() const;
	void move();
	void killBullet();
	bool isOnScreen();

private:
	Parameters parameters_;
	HitBox hitbox_;
	bool isAlive_;
	void updateHitBox();
	void moveBullet();
};

#endif
