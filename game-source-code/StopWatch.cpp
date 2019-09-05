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

const float StopWatch::getTimeElapsed()
{
	return timeElapsed();
}

const float StopWatch::getStopTime() const
{
	return stop_;
}

float StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time) / CLOCKS_PER_SEC;
}

float StopWatch::timeElapsed()
{
	elapsedTime_ = getProcessTime();

	elapsedTime_ -= startTime_;

	return elapsedTime_;

}
