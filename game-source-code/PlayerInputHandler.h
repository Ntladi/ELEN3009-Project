#ifndef PLAYERINPUTHANDLER_H_
#define PLAYERINPUTHANDLER_H_
#include <StopWatch.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"

/** \class PlayerInputHandler
 * \brief This class is detects player inputs and relays them back to the Presentation class
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class PlayerInputHandler
{
public:
	/** Default PlayerInputHandler constructor. Initializes all member variables.
	 */
	PlayerInputHandler();

	/** \brief This method checks if the relevant inputs for multi player
	 * mirrored mode have been entered, and sets the appropriate
	 * member booleans to false.
	 */
	void multiPlayerInputs();
	/** \brief This method checks if the relevant inputs for single player
	 * mirrored mode have been entered, and sets the appropriate
	 * member booleans to false.
	 */
	void singlePlayerMirroredInputs();

	/** \brief This method checks if the relevant inputs for single player
	 * inverted mode have been entered, and sets the appropriate
	 * member booleans to false.
	 */
	void singlePlayerInvertedInputs();

	/** \brief This method returns a vector of boolean variables back to the presentation
	 * layer for processing.
	 * \return std::vector<bool>
	 */
	std::vector<bool> getInputs();

	/** \brief This method resets all member booleans to false;
	 */
	void resetInputs();

private:
	bool moveUpPlayerLeft_;
	bool moveUpPlayerRight_;
	bool moveUpPlayerUp_;
	bool moveUpPlayerDown_;
	bool upPlayerShoots_;
	bool moveDownPlayerLeft_;
	bool moveDownPlayerRight_;
	bool moveDownPlayerUp_;
	bool moveDownPlayerDown_;
	bool downPlayerShoots_;
	StopWatch stopwatch1_;
	StopWatch stopwatch2_;

	/** This method only allows the member booleans concerned with shooting to
	 * be set to true only if enough time has elapsed according to the appropriate
	 * stop-watch.
	 */
	void singlePlayerShooting();
};

#endif
