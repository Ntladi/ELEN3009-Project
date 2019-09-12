#ifndef COLLISIONHANDLER_H_
#define COLLISIONHANDLER_H_
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "IEntity.h"
#include "SeperatingAxisTheorem.h"
using object = std::shared_ptr<IEntity>;
using vec_of_objects = std::vector<object>;
class CollisionHandler
{
public:
	CollisionHandler();
	void handlecollisions(vec_of_objects &playerBullets, vec_of_objects &aliens );
private:
	void playerBulletsAliens(vec_of_objects &playerBullets, vec_of_objects &aliens);
	void handleObjectCollisions();
	void checkColision(object &object1, object &object2);
	SeperatingAxisTheorem theorem_;
};

#endif
