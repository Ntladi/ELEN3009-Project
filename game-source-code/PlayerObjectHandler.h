#ifndef PLAYEROBJECTHANDLER_H_
#define PLAYEROBJECTHANDLER_H_
#include <SeparatingAxisTheorem.h>
#include "Player.h"
#include "HitBox.h"
#include <vector>
#include <memory>
using player_ptr = std::shared_ptr<Player>;
using vec_of_object_ptrs = std::vector<std::shared_ptr<IEntity>>;

/** \brief This class determines whether or not it is appropriate to move a Player
 * game object based on what game inputs the received. This class is encapsulated within
 * the ObjectFactory class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class PlayerObjectHandler
{
public:
	void changePlayerDirections(player_ptr &up_player, player_ptr &down_player,
			const std::vector<bool> &inputs, vec_of_object_ptrs & barriers);
private:
	bool isColliding(player_ptr &up_player, player_ptr &down_player,
			MoveDirection up_direction, MoveDirection down_direction,
			Orientation up_orientation, Orientation down_orientation, vec_of_object_ptrs & barriers );
	void getDirection(const std::vector<bool> &inputs,player_ptr &up_player, player_ptr &down_player);

	bool checkBarrierCollisions(HitBox &hitbox,vec_of_object_ptrs & barriers);
	SeparatingAxisTheorem axis_;
	MoveDirection up_direction_;
	MoveDirection down_direction_;
};

#endif
