#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class StopWatch
{
public:
	StopWatch() : startTime_(0), elapsedTime_(0), stop_(0) {};
	void start();
	void stop();
	const double getTimeElapsed();
	const double getStopTime() const;

private:
	double startTime_;
	double elapsedTime_;
	double stop_;

	double getProcessTime();
	double timeElapsed();
};

#endif
