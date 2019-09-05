#ifndef ARMADA_H_
#define ARMADA_H_
#include "Alien.h"
#include "ArmadaParameters.h"
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
	ArmadaParameters parameters_;
	//Orientation orientation_;
	//int counter_;
	//const static unsigned int MAX_ROWS_ = 2;
	//const static unsigned int MAX_COLS_ = 8;
	//const static constexpr float SPACE_BETWEEN_ROWS_ = 3;
	//const static constexpr float SPACE_BETWEEN_COLS_ = 3;
	void generateColumn(const double & x_position);
	void generateRows();
	void removeWaste();
	void checkEdges();
	void moveAllVertically();
};

#endif
