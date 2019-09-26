#include "StopWatch.h"

void StopWatch::start()
{
	startTime_ = getProcessTime();
}

const float StopWatch::getTimeElapsed()
{
	return timeElapsed();
}

const float StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time) / CLOCKS_PER_SEC;
}

const float StopWatch::timeElapsed()
{
	elapsedTime_ = getProcessTime();

	elapsedTime_ -= startTime_;

	return elapsedTime_;

}
