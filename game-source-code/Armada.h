#ifndef ARMADA_H_
#define ARMADA_H_
#include "Alien.h"
#include "IEntity.h"
#include <memory>
#include <vector>
#include <algorithm>
#include "BulletFactory.h"
#include "AlienFactory.h"
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class Armada
{
public:
	Armada(Orientation orientation = Orientation::FACE_DOWN);
	vec_of_aliens getArmada();
	vec_of_bullets getOnslaught();
	bool isGameOver();
	bool isArmadaEmpty();

private:
	aliens_2d armada_;
	BulletFactory bullet_factory_;
	AlienFactory alien_factory_;
	void removeWaste();
	void checkEdges();
	void moveAllVertically();
	vec_of_aliens aliens1D();
	void removeForEach(vec_of_aliens & aliens);
};

#endif
