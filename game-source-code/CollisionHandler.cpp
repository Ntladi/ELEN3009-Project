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
void CollisionHandler::handlecollisions(vec_of_object_ptrs & objects)
{
	seprateObjects(objects);
	dualCollisions(player_bullets_, aliens_);
	monoCollisions(player_bullets_, players_);
	dualCollisions(alien_bullets_, players_);
	dualCollisions(players_, aliens_);
	monoCollisions(player_bullets_, player_bullets_);
	monoCollisions(player_bullets_, alien_bullets_);
	monoCollisions(barriers_, alien_bullets_);
	dualCollisions(barriers_, player_bullets_);
}

void CollisionHandler::dualCollisions(vec_of_object_ptrs &player_bullets,
		vec_of_object_ptrs &aliens)
{
	for (auto &i : player_bullets)
	{
		if (i->getStatus())
			for (auto &j : aliens)
				if (j->getStatus())
					checkColision(i, j);
	}
}
void CollisionHandler::checkColision(object_ptr &object1, object_ptr &object2)
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

void CollisionHandler::monoCollisions(vec_of_object_ptrs &objects,
		vec_of_object_ptrs &players)
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

void CollisionHandler::checkMonoCollision(vec_of_object_ptrs &objects,
		object_ptr &object1, Orientation orientation)
{
	for (auto &j : objects)
		if (j->getOrientation() == orientation)
			checkColision(j, object1);
}

void CollisionHandler::seprateObjects(vec_of_object_ptrs & allObjects)
{
	players_.clear();
	aliens_.clear();
	player_bullets_.clear();
	alien_bullets_.clear();
	barriers_.clear();

	for(auto &i: allObjects)
	{
		switch(i->getObjectType())
		{
		case ObjectType::PLAYER:
			players_.push_back(i);
			break;
		case ObjectType::ALIEN:
			aliens_.push_back(i);
			break;
		case ObjectType::PLAYER_BULLET:
			player_bullets_.push_back(i);
			break;
		case ObjectType::PIERCER_BULLET:
			player_bullets_.push_back(i);
			break;
		case ObjectType::ALIEN_BULLET:
			alien_bullets_.push_back(i);
			break;
		case ObjectType::BARRIER:
			barriers_.push_back(i);
			break;
		default:
			break;
		}
	}
}

