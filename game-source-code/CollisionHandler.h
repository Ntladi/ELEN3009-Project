#ifndef COLLISIONHANDLER_H_
#define COLLISIONHANDLER_H_
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "IEntity.h"
#include "SeperatingAxisTheorem.h"
#include "Orientation.h"
using object = std::shared_ptr<IEntity>;
using vec_of_objects = std::vector<object>;
class CollisionHandler
{
public:
	CollisionHandler();
	void handlecollisions(vec_of_objects &player_bullets, vec_of_objects &aliens, vec_of_objects &players, vec_of_objects &alien_bullets);
private:
	void dualCollisions(vec_of_objects &player_bullets, vec_of_objects &aliens);
	void monoCollisions(vec_of_objects &objects, vec_of_objects &players);
	void checkColision(object &object1, object &object2);
	void checkMonoCollision(vec_of_objects &objects, object &object1, Orientation orientation);
	SeperatingAxisTheorem theorem_;
};

#endif
