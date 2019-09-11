#ifndef ARMADA_H_
#define ARMADA_H_
#include "Alien.h"
#include "ArmadaParameters.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;
using vec_of_two_floats = std::vector<std::tuple<float,float>>;

class Armada
{
public:
	Armada(Orientation orientation = Orientation::FACE_DOWN);
	two_floats getAlienSize() const;
	vec_of_two_floats getPositions();
	vec_of_aliens getArmada();
	vec_of_bullets getOnslaught();
	bool isGameOver();
	void generateBullets();

private:
	aliens_2d armada_;
	vec_of_bullets bullets_;
	ArmadaParameters parameters_;
	void generateColumn(const double & x_position, const unsigned int & index);
	void generateRows();
	void removeWaste();
	void checkEdges();
	void moveAllVertically();
	vec_of_aliens aliens1D();
	void removeForEach(vec_of_aliens & aliens);
};

#endif
