#include <PlayerObjectHandler.h>

void PlayerObjectHandler::changePlayerDirections(player_ptr & up_player, player_ptr & down_player, std::vector<bool> &inputs)
{
	if (inputs.at(0))
		up_player->setMoveDirection(MoveDirection::LEFT);
	else if (inputs.at(1))
		up_player->setMoveDirection(MoveDirection::RIGHT);
	else if (inputs.at(2))
		up_player->setMoveDirection(MoveDirection::UP);
	else if (inputs.at(3))
		up_player->setMoveDirection(MoveDirection::DOWN);
	if (inputs.at(4))
		down_player->setMoveDirection(MoveDirection::LEFT);
	else if (inputs.at(5))
		down_player->setMoveDirection(MoveDirection::RIGHT);
	else if (inputs.at(6))
		down_player->setMoveDirection(MoveDirection::UP);
	else if (inputs.at(7))
		down_player->setMoveDirection(MoveDirection::DOWN);
	if (inputs.at(8))
		up_player->shoot();
	if (inputs.at(9))
		down_player->shoot();
}
