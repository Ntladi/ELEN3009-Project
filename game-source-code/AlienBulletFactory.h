#ifndef ALIENBULLETFACTORY_H_
#define ALIENBULLETFACTORY_H_
#include "StopWatch.h"
#include "Bullet.h"
#include "Alien.h"
#include <ctime>
#include <cstdlib>
#include <vector>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class BulletFactory
{
public:
	BulletFactory();
	vec_of_bullets getOnslaught();
	void generateBullets(aliens_2d &aliens, const int &size);
private:
	vec_of_bullets bullets_;
	StopWatch stopwatch_;
	const unsigned int getAlienToShoot();
	const float getSecondsBetweenShots() const;
	void addBullet(std::vector<unsigned int> &endOfCols,
			const unsigned int &index, aliens_2d &aliens);
	void removeWaste();
};

#endif
