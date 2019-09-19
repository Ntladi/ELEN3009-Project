#ifndef COLLISIONHANDLER_H_
#define COLLISIONHANDLER_H_
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "IEntity.h"
#include "IMovingEntity.h"
#include "SeperatingAxisTheorem.h"
#include "Orientation.h"
using moving_object = std::shared_ptr<IMovingEntity>;
using vec_of_moving_objects = std::vector<moving_object>;
class CollisionHandler
{
public:
	CollisionHandler();
	void handlecollisions(vec_of_moving_objects &player_bullets, vec_of_moving_objects &aliens, vec_of_moving_objects &players, vec_of_moving_objects &alien_bullets);
	float getScore() const;
private:
	void dualCollisions(vec_of_moving_objects &player_bullets, vec_of_moving_objects &aliens);
	void monoCollisions(vec_of_moving_objects &objects, vec_of_moving_objects &players);
	void checkColision(moving_object &object1, moving_object &object2);
	void checkMonoCollision(vec_of_moving_objects &objects, moving_object &object1, Orientation orientation);
	SeperatingAxisTheorem theorem_;
	float score_;
};

#endif
