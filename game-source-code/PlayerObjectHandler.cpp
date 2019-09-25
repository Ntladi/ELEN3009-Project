#include <PlayerObjectHandler.h>

void PlayerObjectHandler::changePlayerDirections(player_ptr &up_player,
		player_ptr &down_player,const std::vector<bool> &inputs,
		vec_of_object_ptrs &barriers)
{
	up_direction_ = MoveDirection::NONE;
	down_direction_ = MoveDirection::NONE;
	getDirection(inputs, up_player, down_player);

	if (!isColliding(up_player, down_player, up_direction_, down_direction_,
			up_player->getOrientation(), down_player->getOrientation(),
			barriers))
	{
		up_player->setMoveDirection(up_direction_);
		down_player->setMoveDirection(down_direction_);
	}

	if (inputs.at(8))
		up_player->shoot();
	if (inputs.at(9))
		down_player->shoot();
}

bool PlayerObjectHandler::isColliding(player_ptr &up_player,
		player_ptr &down_player, MoveDirection up_direction,
		MoveDirection down_direction, Orientation up_orientation,
		Orientation down_orientation, vec_of_object_ptrs &barriers)
{
	auto temp_up_player = Player
	{ up_orientation };
	auto temp_down_player = Player
	{ down_orientation };
	temp_up_player.setPosition(up_player->getPosition());
	temp_down_player.setPosition(down_player->getPosition());

	temp_up_player.setMoveDirection(up_direction);
	temp_up_player.move();
	temp_down_player.setMoveDirection(down_direction);
	temp_down_player.move();

	auto hit_box_1 = temp_up_player.getHitBox();
	auto hit_box_2 = temp_down_player.getHitBox();

	if ((up_direction == MoveDirection::UP || up_direction == MoveDirection::DOWN) && checkBarrierCollisions(hit_box_1, barriers))
		return true;

	if ((down_direction == MoveDirection::UP || down_direction == MoveDirection::DOWN) && checkBarrierCollisions(hit_box_2, barriers))
		return true;

	return axis_.isOverlapping(hit_box_1, hit_box_2);

}
void PlayerObjectHandler::getDirection(const std::vector<bool> &inputs,
		player_ptr &up_player, player_ptr &down_player)
{
	if (up_player->isNotMovingVertucally())
	{
		if (inputs.at(0))
			up_direction_ = MoveDirection::LEFT;
		else if (inputs.at(1))
			up_direction_ = MoveDirection::RIGHT;
	}

	if (inputs.at(2))
		up_direction_ = MoveDirection::UP;
	else if (inputs.at(3))
		up_direction_ = MoveDirection::DOWN;

	if (down_player->isNotMovingVertucally())
	{
		if (inputs.at(4))
			down_direction_ = MoveDirection::LEFT;
		else if (inputs.at(5))
			down_direction_ = MoveDirection::RIGHT;

	}
	if (inputs.at(6))
		down_direction_ = MoveDirection::UP;
	else if (inputs.at(7))
		down_direction_ = MoveDirection::DOWN;
}

bool PlayerObjectHandler::checkBarrierCollisions(HitBox & hitbox,vec_of_object_ptrs & barriers)
{
	for(auto &i:barriers)
	{
		auto box = i->getHitBox();
		if(axis_.isOverlapping(hitbox,box))
			return true;
	}
	return false;
}
