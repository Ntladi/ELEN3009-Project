#ifndef COLLISIONHANDLER_H_
#define COLLISIONHANDLER_H_
#include <SeparatingAxisTheorem.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "IEntity.h"
#include "IMovingEntity.h"
#include "Orientation.h"
using object_ptr = std::shared_ptr<IEntity>;
using vec_of_object_ptrs = std::vector<object_ptr>;

/** \class CollisionHandler
 * \brief This class checks for and handles collision detection for all game objects.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class CollisionHandler
{
public:

	/** \brief Default CollisionHandler constructor. Initializes the game score to zero.
	 */
	CollisionHandler();

	/** \brief This method receives a vector of game object shared pointers
	 * in order to perform collision detection on them.
	 * \param objects of type std::vector<std::shared_ptr<IEntity>>;
	 */
	void handlecollisions(vec_of_object_ptrs & objects);
	float getScore() const;
private:
	/** \brief This method checks for collision detection between all objects_1
	 * and all objects_2 regardless of orientation.
	 * \param objects_1 of type std::vector<std::shared_ptr<IEntity>>;
	 * \param objects_2 of type std::vector<std::shared_ptr<IEntity>>;
	 */
	void dualCollisions(vec_of_object_ptrs &objects_1, vec_of_object_ptrs &objects_2);

	/** \brief This method checks for collision detection between all objects_1
	 * and all objects_2, so long as their orientations are different.
	 * \param objects_1 of type std::vector<std::shared_ptr<IEntity>>;
	 * \param objects_2 of type std::vector<std::shared_ptr<IEntity>>;
	 */
	void monoCollisions(vec_of_object_ptrs &objects_1, vec_of_object_ptrs &objects_2);

	/** \brief This method ignores orientation checking for the monoCollisions() method.
	 * \param objects of type std::vector<std::shared_ptr<IEntity>>;
	 * \param object1 of type std::vector<std::shared_ptr<IEntity>>;
	 * \param orientation of type Orientation
	 */
	void checkMonoCollision(vec_of_object_ptrs &objects, object_ptr &object1, Orientation orientation);

	/** \brief This method uses the separation of axis theorem to perform collision detection between object
	 * 1 and object 2.
	 * \param object1
	 * \param object2
	 */
	void checkColision(object_ptr &object1, object_ptr &object2);

	/** \brief This method separates the game objects by type into distinct vectors.
	 * \param allObjects of type std::vector<std::shared_ptr<IEntity>>;
	 */
	void seprateObjects(vec_of_object_ptrs & allObjects);
	SeparatingAxisTheorem theorem_;
	float score_;
	vec_of_object_ptrs players_;
	vec_of_object_ptrs aliens_;
	vec_of_object_ptrs player_bullets_;
	vec_of_object_ptrs alien_bullets_;
	vec_of_object_ptrs barriers_;
};

#endif
