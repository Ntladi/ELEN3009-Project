#ifndef PLAYERBULLETFACTORY_H_
#define PLAYERBULLETFACTORY_H_
#include <Orientation.h>
#include <vector>
#include <memory>
#include <algorithm>
#include "Bullet.h"
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class PlayerBulletFactory
{
public:
	void shoot(Orientation orientation, two_floats position);
	vec_of_bullets getShotsFired();
private:
	vec_of_bullets bulletsFired_;
	void removeWaste();
	void makeStandardBullet();
	void makePiercerBullet();
	void makeMultiShotBullets();
};

#endif
