#ifndef LEFTDIAGONALBULLET_H_
#define LEFTDIAGONALBULLET_H_
#include "Bullet.h"

class LeftDiagonalBullet : public Bullet
{
public:
	LeftDiagonalBullet(two_floats position = {0,0}, Orientation orientation = Orientation::FACE_UP);
private:
	void moveBullet() override;
};

#endif
