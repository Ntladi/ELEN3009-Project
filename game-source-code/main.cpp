#include "Logic.h"

/** \mainpage Duel Invaders
 * This project is a task that is based on object-oriented programming that requires
 * the implementation of a fixed shooter arcade game called Duel Invaders
 * The standard for compilation and the graphics library was chosen to be C++ 17
 * and SFML 2.5.0 library respectively
 * The game comprises of two players modeled as laser cannons that are capable of 
 * moving both horizontally and vertically in a confined area
 * The laser cannons can shoot at the armada of aliens as they attempt to reach the edges
 * of the screen while gaining points
 * Furthermore, the can obtain power ups and can destroy more than one alien at a time
 * depending on the amount of time they last without being shot by the aliens
 * There are two alien armadas that start back-to-back in the middle of the screen and
 * move towards the opposite ends of the screen to attempt invasion
 * Moreover, the armadas drops by one row as their move towards the players when they
 * hit the right-hand side and the left-hand of the screen

 */

int main()
{
	Logic logic;
	logic.run();
	return 0;
}