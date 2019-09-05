#ifndef ARMADA_H_
#define ARMADA_H_
#include "Alien.h"
#include <memory>
#include <vector>
#include <algorithm>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;

class Armada
{
public:
	Armada(Orientation orientation);
	two_floats getAlienSize() const;
	vec_of_aliens getArmada();
	bool isGameOver();

private:
	vec_of_aliens aliens_;
	int counter_;
	Orientation orientation_;
	const unsigned int MAX_ROWS_ = 2;
	const unsigned int MAX_COLS_ = 8;
	const int SPACE_BETWEEN_ROWS_ = 3;
	const double SPACE_BETWEEN_COLS_ = 3;
	std::vector<Alien> latestCol;
	void generateColumn(const double & x_position);
	void generateRows();
	void removeWaste();
	void checkEdges();
	void moveAllVertically();
};

#endif
