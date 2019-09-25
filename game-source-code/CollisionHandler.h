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
using object_ptr = std::shared_ptr<IEntity>;
using vec_of_object_ptrs = std::vector<object_ptr>;
class CollisionHandler
{
public:
	CollisionHandler();
	void handlecollisions(vec_of_object_ptrs & objects);
	float getScore() const;
private:
	void dualCollisions(vec_of_object_ptrs &player_bullets, vec_of_object_ptrs &aliens);
	void monoCollisions(vec_of_object_ptrs &objects, vec_of_object_ptrs &players);
	void checkMonoCollision(vec_of_object_ptrs &objects, object_ptr &object1, Orientation orientation);
	void checkColision(object_ptr &object1, object_ptr &object2);
	void seprateObjects(vec_of_object_ptrs & allObjects);
	SeperatingAxisTheorem theorem_;
	float score_;
	vec_of_object_ptrs players_;
	vec_of_object_ptrs aliens_;
	vec_of_object_ptrs player_bullets_;
	vec_of_object_ptrs alien_bullets_;
	vec_of_object_ptrs barriers_;
};

#endif
