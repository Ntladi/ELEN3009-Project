#ifndef LOGIC_H_
#define LOGIC_H_
#include "Presentation.h"
#include "CollisionHandler.h"
#include "ObjectFactory.h"
#include "IMovingEntity.h"
#include <tuple>
#include <memory>
#include <vector>
using moving_object = std::shared_ptr<IMovingEntity>;
using vec_of_moving_object_ptrs = std::vector<std::shared_ptr<IMovingEntity>>;
using two_floats = std::tuple<float,float>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

/** \class Logic
 * \brief This class is the main class of the logic layer. The class
 * manages when and how the game entities on the screen
 * move. It then relays that information to the Presentation class.
 * The class queries the ObjectFactory class to move the objects.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */

class Logic {
public:
	/** \brief Default Logic constructor. Creates an instance of
	 * the game.
	 */
	Logic();

	/** \brief This method runs the main game loop.
	 */
	void run();

private:
	Presentation presentation_;
	CollisionHandler collision_handler_;
	ObjectFactory object_factory_;

	/** \brief This method initializes the sizes and positions
	 * of all game objects.
	 */
	void reset();

	/** \brief While the game is running, this method receives
	 * a vector containing all player inputs from the Presentation
	 * class and manipulates all game objects accordingly.
	 * \param inputs of type const std::vector<bool>.
	 */
	void process(const std::vector<bool> & inputs);

	/** \brief This method communicates the initial sizes of all
	 *  game objects to the Presentation class.
	 */
	void loadSizes();

	/** \brief This method communicates the current positions of
	 * all game objects to the presentation class.
	 */
	void setPositions();

	/** \brief This method moves all objects of type IMovingEntity.
	 */
	void moveAllObjects();

	/** \brief This method handles collisions between game objects
	 * through the CollisionHandler class.
	 */
	void checkColisions();

	/** \brief This method checks if a game has ended and communicates
	 * the final game state to the Presentation class.
	 */
	void checkGameOver();
};

#endif
