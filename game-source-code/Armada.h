#ifndef ARMADA_H_
#define ARMADA_H_
#include "Alien.h"
#include "ArmadaParameters.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class Armada
{
public:
	Armada(Orientation orientation);
	two_floats getAlienSize() const;
	vec_of_aliens getArmada();
	vec_of_bullets getOnslaught();
	bool isGameOver();
	void makeBullets();

private:
	vec_of_aliens aliens_;
	vec_of_bullets bullets_;
	ArmadaParameters parameters_;
	void generateColumn(const double & x_position);
	void generateRows();
	void removeWaste();
	void checkEdges();
	void moveAllVertically();
};

#endif
