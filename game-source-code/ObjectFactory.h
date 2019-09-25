#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_
#include "Player.h"
#include "Armada.h"
#include "LifeFactory.h"
#include "PlayerObjectHandler.h"
#include "BarrierFactory.h"
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
using vec_of_moving_object_ptrs = std::vector<std::shared_ptr<IMovingEntity>>;
using vec_of_object_ptrs = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

/** \class ObjectFactory
 * \brief This class is a data layer class composed within the Logic class.
 * it stores all the objects that the Logic class manipulates. The class
 * also encapsulates the PlayerObjectHandlerClass.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class ObjectFactory
{
public:
	/** \brief Default ObjectFactory constructor. Initializes game object pointers.
	 */
	ObjectFactory();

	/** \brief This method manipulates a map containing the sizes of all game objects
	 * from the Logic class.
	 * \param sizes of type std::map<ObjectType, std::tuple<float, float> >
	 */
	void getSizes(map_of_two_floats& sizes);

	/** \brief This method manipulates a vector containing all game objects of type
	 *  IEntity from to the Logic class.
	 * \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getAllObjects(vec_of_object_ptrs& objects);

	/** \brief This method manipulates a vector containing all movable game objects
	 * of type IMovingEntity from the Logic class.
	 * \param movingObjects of type std::vector<std::shared_ptr<IMovingEntity> >
	 */
	void getMovingObjects(vec_of_moving_object_ptrs& movingObjects);

	/** \brief This method receives a vector of player inputs from the Logic class
	 * and queries the PlayerObjectHandler class to manipulate the player.
	 * \param inputs of type std::vector<bool>
	 */
	void changePlayerDirections(std::vector<bool> &inputs);

	/** \brief This method resets a Player object's position and its power-up counter
	 * if its hit.
	 */
	void resetPlayerIfHit();

	/** \brief This method returns true if the game over conditions have been met.
	 *	\return bool
	 */
	bool gameOverStatus() const;

	/** \brief This method returns true if the winning conditions have been met.
	 * \return bool
	 */
	bool gameWonStatus() const;

	/** \brief This method resets the power-up timer for both Player objects.
	 */
	void startPowerClock();

private:
	std::shared_ptr<Player> up_player_;
	std::shared_ptr<Player> down_player_;
	std::shared_ptr<Armada> up_armada_;
	std::shared_ptr<Armada> down_armada_;
	std::shared_ptr<BarrierFactory> up_barriers_;
	std::shared_ptr<BarrierFactory> down_barriers_;
	std::shared_ptr<LifeFactory> up_lives_;
	std::shared_ptr<LifeFactory> down_lives_;
	PlayerObjectHandler player_input_handler_;

	/** \brief This method initializes all shared pointer objects contained within
	 * the class.
	 */
	void initializeObjects();

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity from the getAllObjects method. It then appends all PlayerGlyph
	 *  objects to the vector.
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getGlyphs(vec_of_object_ptrs& objects);

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity from the getAllObjects method. It then appends all Barrier objects
	 *  to the vector.
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getBarriers(vec_of_object_ptrs& objects);

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity as well as a vector containing all movable game objects of type
	 *  IMovingEntity. It then appends all Player objects to both vectors.
	 *  \param movingObjects of type std::vector<std::shared_ptr<IMovingEntity> >
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getPlayers(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity as well as a vector containing all movable game objects of type
	 *  IMovingEntity. It then appends all Alien objects to both vectors.
	 *  \param movingObjects of type std::vector<std::shared_ptr<IMovingEntity> >
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getAliens(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity as well as a vector containing all movable game objects of type
	 *  IMovingEntity. It then appends all Bullet objects belonging to both Player
	 *  objects to both vectors.
	 *  \param movingObjects of type std::vector<std::shared_ptr<IMovingEntity> >
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getPlayerBullets(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);

	/** \brief This method receives a vector containing all game objects of type
	 *  IEntity as well as a vector containing all movable game objects of type
	 *  IMovingEntity. It then appends all Bullet objects belonging to both Armada
	 *  objects to both vectors.
	 *  \param movingObjects of type std::vector<std::shared_ptr<IMovingEntity> >
	 *  \param objects of type std::vector<std::shared_ptr<IEntity> >
	 */
	void getAlienBullets(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);

};

#endif
