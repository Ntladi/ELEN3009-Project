#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_
#include "Player.h"
#include "Armada.h"
#include "LifeFactory.h"
#include "PlayerObjectHandler.h"
#include "BarrierFactory.h"
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
using vec_of_moving_object_ptrs = std::vector<std::shared_ptr<IMovingEntity>>;
using vec_of_object_ptrs = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

class ObjectFactory
{
public:
	ObjectFactory();
	void getSizes(map_of_two_floats& sizes);
	void getAllObjects(vec_of_object_ptrs& objects);
	void getMovingObjects(vec_of_moving_object_ptrs& movingObjects);
	void changePlayerDirections(std::vector<bool> &inputs);
	void checkPlayer();
	bool gameOverStatus() const;
	bool gameWonStatus() const;
	void startPowerClock();

private:
	std::shared_ptr<Player> up_player_;
	std::shared_ptr<Player> down_player_;
	std::shared_ptr<Armada> up_armada_;
	std::shared_ptr<Armada> down_armada_;
	std::shared_ptr<BarrierFactory> up_barriers_;
	std::shared_ptr<BarrierFactory> down_barriers_;
	std::shared_ptr<LifeFactory> up_lives_;
	std::shared_ptr<LifeFactory> down_lives_;
	PlayerObjectHandler player_input_handler_;
	void initializeObjects();
	void getGlyphs(vec_of_object_ptrs& objects);
	void getBarriers(vec_of_object_ptrs& objects);
	void getPlayers(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);
	void getAliens(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);
	void getPlayerBullets(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);
	void getAlienBullets(vec_of_moving_object_ptrs & movingObjects, vec_of_object_ptrs &objects);

};

#endif
