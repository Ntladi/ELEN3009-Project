#include <CollisionHandler.h>
#include <iostream>

CollisionHandler::CollisionHandler()
{

}

void CollisionHandler::handlecollisions(vec_of_objects &playerBullets,
		vec_of_objects &aliens)
{
	playerBulletsAliens(playerBullets,aliens);
}

void CollisionHandler::playerBulletsAliens(vec_of_objects &playerBullets,
		vec_of_objects &Aliens)
{
	for (auto &i : playerBullets)
	{
		if (i->getStatus())
			for (auto &j : Aliens)
				if (j->getStatus())
					checkColision(i, j);

	}
}
void CollisionHandler::checkColision(object &object1, object &object2)
{
	auto box_1 = object1->getHitBox();
	auto box_2 = object2->getHitBox();

	if (theorem_.isOverlapping(box_1, box_2))
	{
		object1->killEntity();
		object2->killEntity();
	}

}
