#ifndef PIERCERBULLET_H_
#define PIERCERBULLET_H_
#include "Bullet.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float,float,float, float>;

class PiercerBullet : public Bullet
{
public:
	PiercerBullet(two_floats position = {0,0}, Orientation orientation = Orientation::FACE_UP);
};

#endif
