#include <ArmadaParameters.h>

ArmadaParameters::ArmadaParameters(Orientation orientation)
{
	orientation_ = orientation;
	MAX_ROWS_ = Constants::MAX_ARMADA_ROWS;
	MAX_COLS_ = Constants::MAX_ARMADA_COLS;
	SPACE_BETWEEN_ROWS_ = Constants::SPACE_BETWEEN_ARMADA_ROWS;
	SPACE_BETWEEN_COLS_ = Constants::SPACE_BETWEEN_ARMADA_COLS;
	counter_ = 0;
	parameters_ = Parameters{ObjectType::ALIEN, orientation};
	stopwatch_ = StopWatch{};
	stopwatch_.start();

}

Orientation ArmadaParameters::getOrientation() const
{
	return orientation_;
}

const unsigned int ArmadaParameters::getMaxRows() const
{
	return MAX_ROWS_;
}

const unsigned int ArmadaParameters::getMaxCols() const
{
	return MAX_COLS_;
}

const float ArmadaParameters::getSpaceBetweenRows() const
{
	return SPACE_BETWEEN_ROWS_;
}

const float ArmadaParameters::getSpaceBetweenCols() const
{
	return SPACE_BETWEEN_COLS_;
}

const unsigned int ArmadaParameters::getCounter() const
{
	return counter_;
}

const unsigned int ArmadaParameters::getCounterMinus() const
{
	return counter_ - 1;
}

float ArmadaParameters::getElapsedTime()
{
	return stopwatch_.getTimeElapsed();
}
two_floats ArmadaParameters::getAlienPosition() const
{
	return {parameters_.getXposition(), parameters_.getYposition()};
}

two_floats ArmadaParameters::getAlienSize() const
{
	return
		{	parameters_.getXLength(), parameters_.getYHeight()};
}

void ArmadaParameters::incrementCounter()
{
	counter_++;
}

void ArmadaParameters::setCounter(const unsigned int &i)
{
	counter_ = i;
}
