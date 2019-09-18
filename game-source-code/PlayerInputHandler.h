#ifndef PLAYERINPUTHANDLER_H_
#define PLAYERINPUTHANDLER_H_
#include <StopWatch.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class PlayerInputHandler
{
public:
	PlayerInputHandler();
	void multiPlayerInputs();
	void singlePlayerMirroredInputs();
	void singlePlayerInvertedInputs();
	std::vector<bool> getInputs();
	void resetInputs();

private:
	bool moveUpPlayerLeft_;
	bool moveUpPlayerRight_;
	bool upPlayerShoots_;
	bool moveDownPlayerLeft_;
	bool moveDownPlayerRight_;
	bool downPlayerShoots_;
	StopWatch stopwatch1_;
	StopWatch stopwatch2_;
	void singlePlayerShooting();

};

#endif
