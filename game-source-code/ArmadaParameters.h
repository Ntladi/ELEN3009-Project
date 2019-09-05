#ifndef ARMADAPARAMETERS_H_
#define ARMADAPARAMETERS_H_
#include "Orientation.h"
#include "Constants.h"
#include "Parameters.h"
#include <tuple>
using two_floats = std::tuple<float,float>;

class ArmadaParameters
{
public:
	ArmadaParameters(Orientation orientation = Orientation::FACE_UP);
	Orientation getOrientation() const;
	const unsigned int getMaxRows() const;
	const unsigned int getMaxCols() const;
	const float getSpaceBetweenRows() const;
	const float getSpaceBetweenCols() const;
	const unsigned int getCounter() const;
	const unsigned int getCounterMinus() const;
	two_floats getAlienPosition() const;
	two_floats getAlienSize() const;
	void incrementCounter();
	void setCounter(const unsigned int & i);
private:
	Orientation orientation_;
	unsigned int MAX_ROWS_;
	unsigned int MAX_COLS_;
	float SPACE_BETWEEN_ROWS_;
	float SPACE_BETWEEN_COLS_;
	unsigned int counter_;
	Parameters parameters_;


};

#endif
