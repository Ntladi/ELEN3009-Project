#ifndef PLAYEROBJECTHANDLER_H_
#define PLAYEROBJECTHANDLER_H_
#include "Player.h"
#include <vector>
#include <memory>
using player_ptr = std::shared_ptr<Player>;

class PlayerObjectHandler
{
public:
	void changePlayerDirections(player_ptr & up_player, player_ptr & down_player, std::vector<bool> &inputs);
private:

};

#endif
