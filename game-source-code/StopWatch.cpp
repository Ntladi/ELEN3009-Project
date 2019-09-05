#include "StopWatch.h"
#include <iostream>
#include <iomanip>
#include <ctime>


void StopWatch::start()
{
	startTime_ = getProcessTime();
}

void StopWatch::stop()
{
	stop_ = timeElapsed();
}

const double StopWatch::getTimeElapsed()
{
	return timeElapsed();
}

const double StopWatch::getStopTime() const
{
	return stop_;
}

double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time) / CLOCKS_PER_SEC;
}

double StopWatch::timeElapsed()
{
	elapsedTime_ = getProcessTime();

	elapsedTime_ -= startTime_;

	return elapsedTime_;

}
