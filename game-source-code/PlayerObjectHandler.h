#ifndef PLAYEROBJECTHANDLER_H_
#define PLAYEROBJECTHANDLER_H_
#include "Player.h"
#include "SeperatingAxisTheorem.h"
#include <vector>
#include <memory>
using player_ptr = std::shared_ptr<Player>;

class PlayerObjectHandler
{
public:
	void changePlayerDirections(player_ptr &up_player, player_ptr &down_player,
			std::vector<bool> &inputs);
private:
	bool isColliding(player_ptr &up_player, player_ptr &down_player,
			MoveDirection up_direction, MoveDirection down_direction,
			Orientation up_orientation, Orientation down_orientation);
	void getDirection(std::vector<bool> &inputs,player_ptr &up_player, player_ptr &down_player);
	SeperatingAxisTheorem axis_;
	MoveDirection up_direction_;
	MoveDirection down_direction_;
};

#endif
