#include <CollisionHandler.h>
#include <iostream>

CollisionHandler::CollisionHandler()
{

}

void CollisionHandler::handlecollisions(vec_of_moving_objects &player_bullets,
		vec_of_moving_objects &aliens, vec_of_moving_objects &players,
		vec_of_moving_objects &alien_bullets)
{
	dualCollisions(player_bullets, aliens);
	monoCollisions(player_bullets, players);
	dualCollisions(alien_bullets,players);
	//dualCollisions(players, aliens);
	monoCollisions(player_bullets,player_bullets);
	monoCollisions(player_bullets,alien_bullets);

}

void CollisionHandler::dualCollisions(vec_of_moving_objects &player_bullets,
		vec_of_moving_objects &aliens)
{
	for (auto &i : player_bullets)
	{
		if (i->getStatus())
			for (auto &j : aliens)
				if (j->getStatus())
					checkColision(i, j);

	}
}
void CollisionHandler::checkColision(moving_object &object1, moving_object &object2)
{
	auto box_1 = object1->getHitBox();
	auto box_2 = object2->getHitBox();

	if (theorem_.isOverlapping(box_1, box_2))
	{
		object1->killEntity();
		object2->killEntity();
	}

}

void CollisionHandler::monoCollisions(vec_of_moving_objects &objects,
		vec_of_moving_objects &players)
{
	for (auto &i : objects)
	{
		if (i->getStatus())
		{
			if (i->getOrientation() == Orientation::FACE_UP)
				checkMonoCollision(players, i, Orientation::FACE_DOWN);
			else if (i->getOrientation() == Orientation::FACE_DOWN)
				checkMonoCollision(players, i, Orientation::FACE_UP);

		}
	}
}

void CollisionHandler::checkMonoCollision(vec_of_moving_objects &objects,
		moving_object &object1, Orientation orientation)
{
	for (auto &j : objects)
		if (j->getOrientation() == orientation)
			checkColision(j, object1);
}
