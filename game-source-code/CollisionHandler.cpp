#include <CollisionHandler.h>
#include <iostream>

CollisionHandler::CollisionHandler()
{
	score_= 0;
}

float CollisionHandler::getScore() const
{
	return score_;
}
void CollisionHandler::handlecollisions(vec_of_moving_objects &player_bullets,
		vec_of_moving_objects &aliens, vec_of_moving_objects &players,
		vec_of_moving_objects &alien_bullets)
{
	//auto player_1_lives = players.at(0)->getLives();
	//is_up_player_hit_ = false;
	dualCollisions(player_bullets, aliens);
	monoCollisions(player_bullets, players);
	dualCollisions(alien_bullets,players);
	dualCollisions(players, aliens);
	monoCollisions(player_bullets,player_bullets);
	monoCollisions(player_bullets,alien_bullets);

	//if(player_1_lives < players.at(0)->getLives())
		//is_up_player_hit_ = true;
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
		object1->hitEntity();
		score_ += object1->getScore();
		object2->hitEntity();
		score_ += object2->getScore();
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

