#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#include <iostream>
#include <iomanip>
#include <ctime>

/** \class StopWatch
 * \brief This class keeps track of amount of time passed as the game is running.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class StopWatch
{
public:
	/** \brief Default StopWatch constructor. Initializes member variables.
	 */
	StopWatch() : startTime_(0), elapsedTime_(0), stop_(0) {};

	/** \brief This method starts recording how much time has elapsed from the
	 * moment it is called.
	 */
	void start();

	/** \brief This method returns a constant float which describes how much time has
	 * passed since the last time the start() method was called.
	 * \return float
	 */
	const float getTimeElapsed();

private:
	float startTime_;
	float elapsedTime_;
	float stop_;

	/** \brief This method returns a constant float, which describes the total runtime
	 * of the game in seconds. It uses the system's built in clock to calculate this result.
	 * \return float
	 */
	const float getProcessTime();

	/** \brief This method returns a constant float, which describes difference between the
	 * getProcessTime() and start() methods.
	 * \return float
	 */
	const float timeElapsed();
};

#endif
