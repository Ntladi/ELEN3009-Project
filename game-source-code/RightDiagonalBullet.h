#ifndef RIGHTDIAGONALBULLET_H_
#define RIGHTDIAGONALBULLET_H_
#include "Bullet.h"

class RightDiagonalBullet : public Bullet
{
public:
	RightDiagonalBullet(two_floats position = {0,0}, Orientation orientation = Orientation::FACE_UP);
private:
	void moveBullet() override;
};

#endif
