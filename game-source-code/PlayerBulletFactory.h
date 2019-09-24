#ifndef PLAYERBULLETFACTORY_H_
#define PLAYERBULLETFACTORY_H_
#include <Orientation.h>
#include <vector>
#include <memory>
#include <algorithm>
#include "Bullet.h"
#include "PiercerBullet.h"
#include "RightDiagonalBullet.h"
#include "LeftDiagonalBullet.h"
#include "StopWatch.h"
using bullet_ptr = std::shared_ptr<Bullet>;
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<bullet_ptr>;

class PlayerBulletFactory
{
public:
	PlayerBulletFactory();
	void shoot(Orientation orientation, two_floats position);
	vec_of_bullets getShotsFired();
	void resetFactory();
private:
	vec_of_bullets bulletsFired_;
	StopWatch stopwatch_;
	void removeWaste();
	void makeStandardBullet(Orientation orientation, two_floats position);
	void makeMultiShotPiercer(Orientation orientation, two_floats position);
	void makePiercerBullet(Orientation orientation, two_floats position);
	void makeMultiShotBullets(Orientation orientation, two_floats position);
};

#endif
