#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class StopWatch
{
public:
	StopWatch() : startTime_(0), elapsedTime_(0), stop_(0) {};
	void start();
	void stop();
	const float getTimeElapsed();
	const float getStopTime() const;

private:
	float startTime_;
	float elapsedTime_;
	float stop_;

	float getProcessTime();
	float timeElapsed();
};

#endif
