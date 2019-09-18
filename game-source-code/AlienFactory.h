#ifndef ALIENFACTORY_H_
#define ALIENFACTORY_H_
#include "Constants.h"
#include "Alien.h"
#include "Orientation.h"
#include "ObjectType.h"
#include <vector>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using two_floats = std::tuple<float,float>;

class AlienFactory
{
public:
	void initializeArmada(aliens_2d &armada, Orientation orientation);
	unsigned int getCounter() const;
	void setCounter(const unsigned int i);
	void incrementCounter();
private:
	two_floats size_;
	Position position_;
	int counter_;
	const unsigned int MAX_ROWS_ = Constants::MAX_ARMADA_ROWS;
	const unsigned int MAX_COLS_ = Constants::MAX_ARMADA_COLS;
	const float SPACE_BETWEEN_ROWS_ = Constants::SPACE_BETWEEN_ARMADA_ROWS;
	const float SPACE_BETWEEN_COLS_ = Constants::SPACE_BETWEEN_ARMADA_COLS;
	void generateRows(Orientation &orientation, aliens_2d &armada);
	void generateColumn(const double &x_position, const unsigned int &index,
			Orientation &orientation, aliens_2d &armada);

};

#endif